/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
*
* Lot of parts of this software are derived from the PicoLibSDK:
*   Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
*   Repository: https://github.com/Panda381/PicoLibSDK
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
* Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Arduino.h"
#include "include.h"

// boot loader resident segment
uint8_t __attribute__((section(".bootloaderdata"))) LoaderData[BOOTLOADER_DATA];

#define MOUNT_INTERVAL 1000000
#define MOUNT_INVALID_INTERVAL (MOUNT_INTERVAL + 1000000)

// display
uint16_t FgCol, BgCol; // foreground and background color
int DispX, DispY; // X and Y text coordinate

// temporary buffer
#define TEMPBUF 1024 // size of temporary buffer
char TempBuf[TEMPBUF + 1];
int TempBufNum; // number of bytes in temporary buffer
int TempBufInx; // current index in temporary buffer

// files
char Path[PATHMAX + 1]; // current path (with terminating 0)
int PathLen; // length of path
uint32_t LastMount; // last mount time
Bool Remount; // remount request
sFileDesc FileDesc[MAXFILES]; // file descriptors
int FileNum; // number of files
int FileCur; // index of current file
int FileTop; // index of first visible file
FILINFO FileI; // search file info

// current directory start cluster (0 = root)
uint32_t CurDirClust;

// seek cursor to last name
char LastName[FILE_NAME_SIZE];
int LastNameLen; // length of last name, 0 = not used
uint8_t LastNameDir; // ATTR_DIR flag of last name

// preview
enum {
		PREV_START,    // waiting for start
		PREV_TXT_LOAD,    // loading text
		PREV_BMP_START,    // waiting for bitmap start
		PREV_BMP_LOAD,    // loading bitmap
		PREV_STOP,    // preview not active
};

uint8_t PrevState; // current preview state
sFileDesc *PrevFD; // preview file descriptor
int PrevLine; // current preview line
FIL PrevFile; // preview file (name[0] = 0 if not open)
int PrevW, PrevH; // size of preview image

// set print colors
void DispCol(uint16_t fgcol, uint16_t bgcol) {
	FgCol = fgcol;
	BgCol = bgcol;
}

// display text
void DispText(const char *text) {
	SelFont8x16();
	DrawTextBg(text, DispX * FONTW, DispY * FONTH, FgCol, BgCol);
	DispX += static_cast<int>(strlen(text));
}

// display small text
void DispSmallText(const char *text) {
	SelFont6x8();
	DrawTextBg(text, DispX * FONTW2, DispY * FONTH2, FgCol, BgCol);
	DispX += static_cast<int>(strlen(text));
}

// print character
void DispChar(char ch) {
	char buf[2];
	buf[0] = ch;
	buf[1] = 0;
	DispText(buf);
}

// print small character
void DispSmallChar(char ch) {
	char buf[2];
	buf[0] = ch;
	buf[1] = 0;
	DispSmallText(buf);
}

// print space
void DispSpc() {
	DispChar(' ');
}

// display character repeated
void DispCharRep(char ch, int num) {
	for (; num > 0; num--) DispChar(ch);
}

// display space repeated
void DispSpcRep(int num) {
	for (; num > 0; num--) DispSpc();
}

// save boot loader data
void save_boot_data() {
	if ((uint) FileCur < (uint) FileNum) {
		sFileDesc *fd;
		fd = &FileDesc[FileCur];
		LoaderData[0] = fd->len;
		LoaderData[1] = fd->attr & ATTR_DIR;
		memcpy(LoaderData + 2, fd->name, 8);
		get_dir_cluster(Path, &CurDirClust);
		*(uint32_t *) &LoaderData[12] = CurDirClust;
		*(uint32_t *) &LoaderData[16] = FileTop;
		*(uint32_t *) &LoaderData[20] = CRC32(LoaderData, 20);
	}
}

// load boot loader data
void load_boot_data() {
	if (*(uint32_t *) &LoaderData[20] == CRC32(LoaderData, 20)) {
		LastNameLen = LoaderData[0];
		LastNameDir = LoaderData[1];
		memcpy(LastName, LoaderData + 2, 8);
		CurDirClust = *(uint32_t *) &LoaderData[12];
		FileTop = static_cast<int>(*(uint32_t *) &LoaderData[16]);
		PathLen = find_dir_by_cluster(CurDirClust, Path, PATHMAX);
	} else {
		LoaderData[0] = 0;
	}
}

// display frame of file list
void FrameFileList() {
	// reset cursor
	DispX = 0;
	DispY = TEXTH + 1;

	// top frame
	DispCol(COL_STATUSBG, COL_STATUSBG);
	DispSpcRep(FILECOLW); // row
	DispY++;

	// inner rows
	do {
		DispX = 0; // reset column
		DispCol(COL_BLACK, COL_BLACK);
		DispSpcRep(FILECOLW);
		DispY++; // increment row
	} while (DispY < (TEXTH * 2));

	// bottom frame
	DispX = 0; // reset column
	DispCol(COL_STATUSBG, COL_STATUSBG);
	DispSpcRep(FILECOLW); // row
}

// display current path
void PathFileList() {
	// prepare path length
	int len = PathLen;

	// reset cursor
	DispY = TEXTH + 1;
	DispX = 1;

	// left part of top line, left space
	if (len <= FILECOLW - 4) {
		// left part of top line
		DispCol(COL_STATUSBG, COL_STATUSBG); // invert color
		DispSpcRep((FILECOLW - 4 - len) / 2); // line

		// left space
		DispCol(COL_BLACK, COL_WHITE);
		DispSpc();
	}

	// path
	DispCol(COL_BLACK, COL_WHITE);
	if (len <= FILECOLW - 2) {
		// full path
		DispText(Path);
	} else {
		// short path
		DispCharRep('.', 3);
		DispText(Path + len - (FILECOLW - 2 - 3));
	}

	// right space
	if (len <= FILECOLW - 3) DispSpc();

	// right part of top line
	if (len <= FILECOLW - 4) {
		// right part of top line
		DispCol(COL_STATUSBG, COL_STATUSBG);
		DispSpcRep((FILECOLW - 4 - len + 1) / 2); // line
	}
}

// display current index of selected file
void display_file_list_idx() {
	int textLength;

	//if (FileNum == 0) return;
	if (FileNum == 0) {
		TempBuf[0] = '0';
		TempBuf[1] = '/';
		TempBuf[2] = '0';
		TempBuf[3] = '\0';
		textLength = 3;
	} else {
		// Prepare text
		textLength = DecNum(TempBuf, FileCur + 1, 0);
		TempBuf[textLength++] = '/';
		textLength += DecNum(&TempBuf[textLength], FileNum, 0);
	}

	// Reset cursor
	DispX = 0;
	DispY = (TEXTH * 2);

	DispCol(COL_STATUSBG, COL_STATUSBG);
	DispSpc();
	// File color for text 13
	DispCol(COL_CURBG, COL_STATUSBG);
	DispText("A");
	DispCol(COL_WHITE, COL_STATUSBG);
	DispText("-OPEN");
	DispSpc();
	DispCol(COL_CURBG, COL_STATUSBG);
	DispText("B");
	DispCol(COL_WHITE, COL_STATUSBG);
	DispText("-BACK");

	// Display the centered actual text, e.g. 1/20
	DispSpcRep((FILECOLW - 28 - textLength) / 2);
	DispText(TempBuf);
	DispSpcRep((FILECOLW - 2 - textLength) / 2);
	DispSpc();
}

bool has_extension(const char *name, const char *ext) {
	size_t len = strlen(name);
	size_t ext_len = strlen(ext);
	if (len <= ext_len) {
		return false;
	}
	// Pointer to the start of the extension in name
	const char *name_ext = name + len - ext_len;
	// Check if the character before the extension is a dot and perform a case-insensitive comparison
	return *(name_ext - 1) == '.' && strncasecmp(name_ext, ext, ext_len) == 0;
}

bool is_directory(const FILINFO &file_info) {
	return (file_info.fattrib & ATTR_DIR) != 0;
}

bool is_hidden(const FILINFO &file_info) {
	return (file_info.fattrib & ATTR_HID) != 0;
}

const char *extract_name(const FILINFO &file_info) {
	if (strlen(file_info.fname) > FILE_NAME_SIZE) {
		return file_info.altname;
	}
	return file_info.fname;
}

int compare_file_desc(const void *a, const void *b) {
	auto *fa = (sFileDesc *) a;
	auto *fb = (sFileDesc *) b;

	// If one is a directory and the other is not, the directory comes first.
	if ((fa->attr & ATTR_DIR) && !(fb->attr & ATTR_DIR)) {
		return -1;
	} else if (!(fa->attr & ATTR_DIR) && (fb->attr & ATTR_DIR)) {
		return 1;
	}

	// If both are directories or both are files, compare by name.
	return strcasecmp(fa->name, fb->name);
}

void display_attributes(unsigned char attributes) {
	if (attributes & ATTR_TXT) {
		DispText("TXT");
	} else {
		DispSpcRep(3);
	}

	DispSpc();

	if (attributes & ATTR_BMP) {
		DispText("BMP");
	} else {
		DispSpcRep(3);
	}
	DispSpc();
}

void display_file_name(sFileDesc *fd) {
	char startChar = ' ';
	char endChar = ' ';
	int padding = 30;

	if (fd->attr & ATTR_DIR) {
		DispSpc();
		padding--;
		startChar = '[';
		endChar = ']';
	}

	DispChar(startChar);
	for (int j = 0; j < fd->len; j++) {
		DispChar(fd->name[j]);
	}
	DispChar(endChar);

	DispSpcRep(padding - fd->len); // Display spaces
}

void display_file_list() {
	DispY = TEXTH + 2;
	sFileDesc *fd = &FileDesc[FileTop];

	for (int i = 0; i < FILEROWS; i++) {
		DispX = 0;

		// If entry is valid
		if (i + FileTop < FileNum) {
			if (i + FileTop == FileCur) {
				DispCol(COL_CURFG, COL_CURBG);
			} else {
				// Set default file or directory color
				DispCol(COL_WHITE, COL_BLACK);
			}

			display_file_name(fd);
			display_attributes(fd->attr);
			DispSpc();
		} else {
			DispCol(COL_WHITE, COL_BLACK);
			// Clear invalid row
			DispSpcRep(FILECOLW);
		}

		DispY++;
		fd++;
	}

	display_file_list_idx();
	PrevState = PREV_START;
}

void load_file_list() {
	DIR DirInstance;
	size_t len;
	sFileDesc *fd = FileDesc;

	// Clear file list
	FileNum = 0;
	FileCur = 0;
	FileTop = 0;

	if (!open_search(&DirInstance, &FileI, Path, "*")) return;

	do {
		// extract name
		const char *name = extract_name(FileI);
		// name length
		len = strlen(name);
		// get file attributes
		fd->attr = FileI.fattrib & ATTR_MASK;

		if (is_directory(FileI)) {
			if (len == 1 && name[0] == '.') continue;
			if (len == 2 && name[0] == '.' && name[1] == '.') {
				fd->len = len;
				strcpy(fd->name, "..");
				fd++;
				FileNum++;
			} else if (!is_hidden(FileI)) {
				// Directory with no extension
				char *dot = strchr(name, '.');
				if (!dot) {
					strcpy(fd->name, name);
					fd->len = len;
					fd++;
					FileNum++;
				}
			}
		} else {
			if ((has_extension(name, "PP2") || has_extension(name, "UF2")) && !is_hidden(FileI)) {
				if (name[0] == '.') continue;
				fd->len = len - 4;
				memcpy(fd->name, name, fd->len);
				memcpy(fd->extension, name + fd->len + 1, 3);
				fd->name[fd->len] = '\0';
				fd->extension[3] = '\0';
				fd++;
				FileNum++;
			}
		}
	} while (find_next(&DirInstance, &FileI));

	// Additional operations on TXT and BMP files
	if (open_search(&DirInstance, &FileI, Path, "*.*")) {
		do {
			if (is_directory(FileI)) continue;

			const char *name = extract_name(FileI);
			len = strlen(name) - 4;

			if (has_extension(name, "TXT")) {
				for (int inx = 0; inx < FileNum; inx++) {
					if (FileDesc[inx].len == len && memcmp(FileDesc[inx].name, name, len) == 0) {
						FileDesc[inx].attr |= ATTR_TXT;
					}
				}
			} else if (has_extension(name, "BMP")) {
				for (int inx = 0; inx < FileNum; inx++) {
					if (FileDesc[inx].len == len && memcmp(FileDesc[inx].name, name, len) == 0) {
						FileDesc[inx].attr |= ATTR_BMP;
					}
				}
			}
		} while (find_next(&DirInstance, &FileI));
	}

	// Sort files using qsort
	qsort(FileDesc, FileNum, sizeof(sFileDesc), compare_file_desc);

	close_search(&DirInstance);
}

// request to reload current directory
void reload() {
	// reset file list
	FileNum = 0; // no entry
	FileCur = 0; // reset cursor
	FileTop = 0; // reset top entry

	// preview state not active
	PrevState = PREV_STOP;

	// display frame of file list
	FrameFileList();

	// display current path
	PathFileList();

	// set flag - disk need to be remounted
	Remount = True;
}

// reset to root
void reset_root() {
	// reset path to root
	Path[0] = PATHCHAR;
	Path[1] = 0;
	PathLen = 1;

	// request to reload current directory
	reload();
}

// set cursor to last name
void set_last_name() {
	sFileDesc *fd;
	int i;

	// no last name required
	if (LastNameLen == 0) return;

	// search last name in file list
	for (FileCur = FileNum - 1; FileCur > 0; FileCur--) {
		fd = &FileDesc[FileCur];
		if ((fd->len == LastNameLen) &&
				((fd->attr & ATTR_DIR) == LastNameDir) &&
				(memcmp(LastName, fd->name, LastNameLen) == 0))
			break;
	}

	// limit max. top entry
	if (FileTop > FileCur) FileTop = FileCur;

	// limit min. top entry
	i = FileCur - (FILEROWS - 1);
	if (i < 0) i = 0;
	if (FileTop < i) FileTop = i;

	// delele last name request
	LastNameLen = 0;
}

// display info text
void disp_info(const char *text) {
	// prepare length of into text
	int len = static_cast<int>(strlen(text));

	// set text color and coordinated
	DispCol(COL_INFOFG, COL_BLACK);
	DispY = TEXTH + 3;
	DispX = (FILECOLW - len) / 2;

	// display info text
	DispText(text);
}

// loading next byte from temporary buffer (returns 0 if no next byte)
uint8_t prev_char() {
	// check if buffer need to be loaded
	if (TempBufInx >= TempBufNum) {
		// check if file is open
		if (!is_file_open(&PrevFile)) return 0;

		// read next temporary buffer
		TempBufInx = 0;
		TempBufNum = file_read(&PrevFile, TempBuf, TEMPBUF);

		// end of file
		if (TempBufNum < TEMPBUF) file_close(&PrevFile);

		// no data
		if (TempBufNum == 0) return 0;
	}

	// get next byte
	return TempBuf[TempBufInx++];
}

// loading next byte from temporary buffer, skip CR (returns 0 if no next byte)
char prev_char_cr() {
	char ch;
	do {
		ch = prev_char();
	} while (ch == CH_CR);
	return ch;
}

// clear preview panel
void preview_clear() {
	DrawRect(0, 0, WIDTH, HEIGHT / 2, COL_BLACK);
}

// display preview
void disp_preview() {
	int i, padding;
	char ch;
	uint8_t inv;
	sBmp *bmp;
	uint16_t *dst;

	switch (PrevState) {
		// waiting for start
		case PREV_START:

			// close old preview file
			file_close(&PrevFile);

			// clear preview panel
			preview_clear();

			// check if current file is valid
			if ((uint) FileCur >= (uint) FileNum) {
				// no current file
				PrevState = PREV_STOP;
				return;
			}

			// prepare file descriptor
			PrevFD = &FileDesc[FileCur];

			// no text file
			if ((PrevFD->attr & ATTR_TXT) == 0) {
				// waiting for bitmap start
				PrevState = PREV_BMP_START;
				return;
			}

			// prepare filename of text file
			memcpy(TempBuf, PrevFD->name, PrevFD->len);
			memcpy(&TempBuf[PrevFD->len], ".TXT", 5);

			// open text file
			set_dir(Path);
			if (!file_open(&PrevFile, TempBuf, FA_READ)) {
				// cannot open text file, waiting for bitmap start
				PrevState = PREV_BMP_START;
				return;
			}
			TempBufNum = 0; // no data in temporary buffer
			TempBufInx = 0; // reset current index in temporary buffer
			PrevLine = 0; // reset current preview line

			// loading text file
			PrevState = PREV_TXT_LOAD;
			break;

			// loading text
			//	- text width = 26 characters
			//	- ^ is prefix of control characters
			//		^^ ... print ^ character
			//		^1..^9 ... print character with code 1..9
			//		^A..^V ... print character with code 10..31
			//		^0 ... normal gray text
			//		^W ... white text
			//		^X ... green text
			//		^Y ... yellow text
			//		^Z ... red text
			//		^[ ... start invert
			//		^] ... stop invert
		case PREV_TXT_LOAD:

			// set normal text color
			DispCol(COL_TEXTFG, COL_TEXTBG);
			inv = 0;

			// set coordinates
			DispX = (TEXTW2 + 1) / 2;
			DispY = PrevLine;

			// decode one row (i = relative character position)
			for (i = 0; i < TEXTW2 / 2;) {
				// load next character, skip CR characters
				ch = prev_char_cr();

				// LF end of line or NUL end of file
				if ((ch == CH_LF) || (ch == 0)) break;

				// tabulator (modulo 8)
				if (ch == CH_TAB) {
					do {
						DispSmallChar(' ' ^ inv);
						i++; // increase character position
					} while ((i < TEXTW2 / 2) && ((i & 7) != 0));
				} else {
					// prefix character ^
					if (ch == '^') {
						// load next character
						ch = prev_char_cr();

						// LF end of line or NUL end of file
						if ((ch == CH_LF) || (ch == 0))
							break;

							// set white text
						else if (ch == 'W')
							DispCol(COL_WHITE, COL_TEXTBG);

							// set green text
						else if (ch == 'X')
							DispCol(COL_GREEN, COL_TEXTBG);

							// set yellow text
						else if (ch == 'Y')
							DispCol(COL_YELLOW, COL_TEXTBG);

							// set red text
						else if (ch == 'Z')
							DispCol(COL_RED, COL_TEXTBG);

							// set normal text
						else if (ch == '0')
							DispCol(COL_TEXTFG, COL_TEXTBG);

							// print character with code 1..9
						else if ((ch >= '1') && (ch <= '9')) {
							DispSmallChar((ch - '0') ^ inv);
							i++; // increase character position
						}

							// print character with code 10..31
						else if ((ch >= 'A') && (ch <= 'V')) {
							DispSmallChar((ch - 'A' + 10) ^ inv);
							i++; // increase character position
						}

							// start invert
						else if (ch == '[')
							inv = 0x80;

							// stop invert
						else if (ch == ']')
							inv = 0;

							// print ^ character or other normal character
						else {
							DispSmallChar(ch ^ inv);
							i++; // increase character position
						}
					} else {
						// display one character
						DispSmallChar(ch ^ inv);
						i++; // increase character position
					}
				}
			}

			// skip rest of the row
			if (i == TEXTW2 / 2) {
				// find LF end of line or NUL end of file
				do {
					ch = prev_char_cr();
				} while ((ch != CH_LF) && (ch != 0));
			}

			// prepare number of rows
			i = ((PrevFD->attr & ATTR_BMP) == 0) ? TEXTH2 : (TEXTH2 / 2);

			// increase curren row
			PrevLine++;
			if (PrevLine >= i) {
				// close text file
				file_close(&PrevFile);

				// start loading bitmap
				PrevState = PREV_BMP_START;
			}
			break;

			// waiting for bitmap start
		case PREV_BMP_START:
			// close old preview file
			file_close(&PrevFile);

			// no bitmap file
			if ((PrevFD->attr & ATTR_BMP) == 0) {
				int ix;
				if (PrevFD->attr & ATTR_DIR) {
					ix = (PrevFD->attr & ATTR_TXT) == 0 ? (WIDTH / 2) - (86 / 2) : 0;
					DrawImgRle(FolderImg_RLE, FolderImg_Pal, ix, 25, 86, 70);
				} else {
					ix = (PrevFD->attr & ATTR_TXT) == 0 ? (WIDTH / 2) - (68 / 2) : 0;
					DrawImgRle(FileImg_RLE, FileImg_Pal, ix, 17, 68, 86);
				}

				// stop loading
				PrevState = PREV_STOP;
				return;
			}

			// prepare filename of bitmap file
			memcpy(TempBuf, PrevFD->name, PrevFD->len);
			memcpy(&TempBuf[PrevFD->len], ".BMP", 5);

			// open bitmap file
			set_dir(Path);
			if (!file_open(&PrevFile, TempBuf, FA_READ)) {
				// cannot open bitmap file, stop
				PrevState = PREV_STOP;
				return;
			}
			TempBufNum = 0; // no data in temporary buffer
			TempBufInx = 0; // reset current index in temporary buffer

			// load bitmap header
			i = file_read(&PrevFile, TempBuf, sizeof(sBmp));

			// get size of preview image
			bmp = (sBmp *) TempBuf;
			PrevW = (bmp->biWidth + 1) & ~1; // width aligned to DWORD
			PrevH = bmp->biHeight;
			if (PrevH < 0) PrevH = -PrevH; // negative height -> flip row order

			// check bitmap header
			if ((i != sizeof(sBmp)) ||
					(PrevW < 8) || (PrevW > 2048) ||
					(PrevH < 8) || (PrevH > 2048) ||
					(bmp->bfType != 0x4D42) ||
					(bmp->bfSize < 100) || (bmp->bfSize > 5000000) ||
					(bmp->bfOffBits < 54) || (bmp->bfOffBits > 2000) ||
					(bmp->biPlanes != 1) ||
					(bmp->biBitCount != 16)) {
				file_close(&PrevFile);

				// cannot open bitmap file, stop
				PrevState = PREV_STOP;
				return;
			}

			// set start of first line
			file_seek(&PrevFile, bmp->bfOffBits);

			// prepare first video line
			PrevLine = 0; //((PrevFD->attr & ATTR_TXT) == 0) ? 0 : (HEIGHT / 2);

			// loading bitmap file
			PrevState = PREV_BMP_LOAD;
			break;

			// loading bitmap
		case PREV_BMP_LOAD:
			// prepare address in video memory
			padding = ((PrevFD->attr & ATTR_TXT) == 0) ? (WIDTH / 4) : 0;
			dst = &FrameBuf[(PrevLine * WIDTH) + padding];

			// prepare size of data to read from one line
			i = (PrevW > (WIDTH / 2)) ? (WIDTH / 2) : PrevW;

			// read one video line
			file_read(&PrevFile, dst, i * 2);
			DispDirtyRect(padding, PrevLine, WIDTH / 2, 1);

			// skip rest of line
			if (PrevW > (WIDTH / 2)) file_seek(&PrevFile, PrevFile.fptr + (PrevW - (WIDTH / 2)) * 2);

			// increase line
			PrevLine++;
			PrevH--;

			// end of image
			if ((PrevLine >= (HEIGHT / 2)) || (PrevH <= 0)) {
				// close preview file
				file_close(&PrevFile);

				// stop preview
				PrevState = PREV_STOP;
			}
			break;

			// preview not active
			// PREV_STOP
		default:
			break;
	}
}

// display big error text
void disp_big_err(uint8_t code) {
	file_close(&PrevFile);
	disp_error_page(code);
	DrawClear();
	preview_clear();
	FrameFileList();
	display_file_list();
	DispUpdate();
}

// Button A
void enter_subdirectory(sFileDesc *fd) {
	// going to subdirectory
	// check path length
	if (PathLen + 1 + fd->len <= PATHMAX) {
		// add path separator if not root
		if (PathLen != 1) Path[PathLen++] = PATHCHAR;

		// add path name
		memcpy(&Path[PathLen], fd->name, fd->len);
		PathLen += fd->len;
	}

	// set terminating 0
	Path[PathLen] = 0;

	// request to reload current directory
	FileTop = 0;
	reload();

	// Invalidate last mount time
	LastMount = to_us_since_boot(get_absolute_time()) - MOUNT_INVALID_INTERVAL;
}

static void run_from_ram(int size) {
	// wait for no key pressed
	KeyWaitNoPressed();

	auto *s = (uint8_t *) FrameBuf;
	device_terminate();
	disable_interrupts();
	reset_peripherals();
	systick_hw->csr = 0x2;

	// copy program to RAM
	auto *d = (uint8_t *) SRAM_BASE;
	for (; size > 0; size--) {
		*d++ = *s++;
	}

	((void (*)(void)) (SRAM_BASE + 1))();
}

// Button A
uint8_t load_application(sFileDesc *fd) {
	uint8_t res;
	// close old preview file
	file_close(&PrevFile);

	// prepare filename of the file
	snprintf(TempBuf, fd->len + 5, "%s.%s", fd->name, fd->extension);
	bool to_ram = strncasecmp(fd->extension, "uf2", 3) == 0;
	int loaded_size = 0;
	res = flash_file(Path, TempBuf, to_ram, &loaded_size);

	if (res != RESULT_OK) {
		disp_big_err(res);
		return res;
	}

	save_boot_data();

	if (to_ram) {
		run_from_ram(loaded_size);
	}

	return RESULT_OK;
}

// out of directory
void leave_directory() {
	int i;

	// not root directory yet
	if (PathLen > 1) {
		// delete last directory
		i = PathLen;
		while (Path[PathLen - 1] != PATHCHAR) PathLen--;

		// save last name
		LastNameLen = i - PathLen;
		memcpy(LastName, &Path[PathLen], LastNameLen);
		LastNameDir = ATTR_DIR;

		// delete path separator if not root
		if (PathLen > 1) PathLen--;

		// set terminating 0
		Path[PathLen] = 0;

		// request to reload current directory
		FileTop = 0;
		reload();

		// Invalidate last mount time
		LastMount = to_us_since_boot(get_absolute_time()) - MOUNT_INVALID_INTERVAL;

		save_boot_data();
	}
}

uint8_t show_file_manager() {
	DrawClear();

	int i, j;
	uint32_t t;
	sFileDesc *fd;
	uint8_t res;

	// reset to root
	LastNameLen = 0; // no last name
	PrevState = PREV_STOP;

	// display frame of file list
	FrameFileList();
	reset_root();
	DrawImgRle(SdcardImg_RLE, SdcardImg_Pal, (WIDTH / 2) - (82 / 2), 19, 82, 82);
	disp_info("Insert SD card");

	// initialize remount
	// invalidate last mount time
	LastMount = to_us_since_boot(get_absolute_time()) - MOUNT_INVALID_INTERVAL;
	// remount request
	Remount = True;

	if (sd_mount()) {
		FileTop = 0;

		// display info text
		disp_info("Loading files...");
		DispUpdate();

		// load boot loader data
		load_boot_data();

		// load files
		Remount = False; // clear flag - disk already remounted
		load_file_list(); // load file list

		// set cursor to last name
		set_last_name();

		// display new directory
		display_file_list();
	}

	while (True) {
		// display update
		DispUpdate();

		// check last mount time (interval 1 second)
		t = to_us_since_boot(get_absolute_time());
		if (((int) (t - LastMount) > MOUNT_INTERVAL) && PrevState == PREV_STOP) {
			// save new last mount time
			LastMount = t;

			// disk removed, request to remount disk next time
			if (!sd_mount()) {
				// clear directories if not done yet
				if (!Remount) // if remount request yet not set
				{
					// clear preview panel
					preview_clear();

					// reset to root
					reset_root();

					DrawImgRle(SdcardImg_RLE, SdcardImg_Pal, (WIDTH / 2) - (82 / 2), 19, 82, 82);

					// display info text
					disp_info("Insert SD card");
				}
			} else {
				// reload directories if disk need to be remounted
				if (Remount) {
					FileTop = 0;

					// clear preview panel
					preview_clear();

					// display info text
					disp_info("Loading files...");

					// load files
					Remount = False; // clear flag - disk already remounted
					load_file_list(); // load file list

					// set cursor to last name
					set_last_name();

					// display new directory
					display_file_list();

					save_boot_data();
				}
			}
		}

		// keyboard service
		while (True) {
			uint8_t ch = screensaver_reset_timer(KeyGet());
			if (ch == NOKEY) break;

			// key switch
			switch (ch) {
				// Down
				case KEY_DOWN:
					if (FileCur < FileNum - 1) {
						// increase cursor
						FileCur++;

						// prepare max. top entry
						i = FileCur - (FILEROWS - 1);
						if (i < 0) i = 0;

						// limit min. top entry
						if (FileTop < i) FileTop = i;

						// repaint display
						display_file_list();
						save_boot_data();
					}
					break;

					// PageDown and Right
				case KEY_RIGHT:
					if (FileCur < FileNum - 1) {
						// max. top entry
						i = FileNum - FILEROWS;
						if (i < 0) i = 0;

						// max. top entry not reached - move page
						if (FileTop < i) {
							j = FILEROWS - 1; // page size
							FileTop += j; // shift top file
							if (FileTop > i) // max. top entry exceeded?
							{
								j -= FileTop - i; // reduce page size
								FileTop = i; // reduce top entry
							}
							FileCur += j; // shift cursor
						} else {
							// max. top entry reached - only shift cursor
							FileCur = FileNum - 1;
						}

						// repaint display
						display_file_list();
						save_boot_data();
					}
					break;

					// Up
				case KEY_UP:
					if (FileCur > 0) {
						// decrease cursor
						FileCur--;

						// limit top entry
						if (FileTop > FileCur) FileTop = FileCur;

						// repaint display
						display_file_list();
						save_boot_data();
					}
					break;

					// PagUp and Left
				case KEY_LEFT:
					if (FileCur > 0) {
						// min. top entry not reached - move page
						if (FileTop > 0) {
							j = FILEROWS - 1; // page size
							FileTop -= j; // shift top file
							if (FileTop < 0) // min. top entry exceeded?
							{
								j += FileTop; // reduce page size
								FileTop = 0; // reduce top entry
							}
							FileCur -= j; // shift cursor
						}
							// min. top entry reached - only shift cursor
						else
							FileCur = 0;

						// repaint display
						display_file_list();
						save_boot_data();
					}
					break;

					// Enter
				case KEY_A:
					if ((uint) FileCur < (uint) FileNum) {
						fd = &FileDesc[FileCur];
						// change directory
						if ((fd->attr & ATTR_DIR) != 0) {
							enter_subdirectory(fd);
						} else {
							// Try to load selected application
							res = load_application(fd);
							if (res == RESULT_OK)
								return RESULT_OK;
						}
					}
					break;

					// out of directory
				case KEY_B:
					// Root directory, leave file manager
					if (PathLen == 1)
						return RESULT_CANCEL;
					leave_directory();
					break;

					// restart program
				case KEY_Y:
					return RESULT_CANCEL;

				case KEY_X:
				default:
					break;
			}
		}

		// preview
		disp_preview();
	}
}
