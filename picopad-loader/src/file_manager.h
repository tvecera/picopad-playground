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

#ifndef PICO_FIRMWARE_FILE_MANAGER_H
#define PICO_FIRMWARE_FILE_MANAGER_H

uint8_t show_file_manager();

#define FILE_NAME_SIZE 32

// text of file list
#define TEXTW		(WIDTH/FONTW) // number of characters per row (=320/8=40)
#define TEXTH		(((HEIGHT/FONTH) - 1) / 2) // number of rows (=240/16-1/2=7)

// text of preview (preview field width = 20 characters, height = 15 rows)
#define FONTW2		6	// font width
#define FONTH2		8	// font height
#define TEXTW2		(WIDTH/FONTW2) // number of characters per row (=320/6=53)
#define TEXTH2		(HEIGHT/FONTH2) // number of rows (=240/8=30)

// files
#define PATHMAX		240	// max. length of path (it must be <= 256 with CRC and magic)
#define MAXFILES	1024	// max files in one directory
#define FILEROWS	(TEXTH-2) // rows of files (=6)
#define FILECOLW	(TEXTW)	// width of file panel

#define PATHCHAR	'/'

// file entry descriptor (10 bytes)
#define	ATTR_HID	(1<<1)	// Hidden
#define ATTR_DIR	(1<<4)	// Directory
#define ATTR_TXT	(1<<6)	// internal: text file TXT present
#define ATTR_BMP	(1<<7)	// internal: bitmap indicator BMP present
#define ATTR_MASK	0x3F	// mask of valid bits

typedef struct { // 10 bytes
    uint8_t	attr;		// attributes ATTR_*
    uint8_t	len;		// file name length
    char	name[FILE_NAME_SIZE];	// file name (without extension and without terminating zero)
} sFileDesc;

// colors
#define COL_CURFG	COL_BLACK	// cursor foreground color
#define COL_CURBG	COL_LTORANGE	// cursor background color
#define COL_STATUSBG	COL_MDKGRAY // cursor background color
#define COL_INFOFG COL_CURBG	// info text foreground color
#define COL_TEXTBG	COL_BLACK	// text background color
#define COL_TEXTFG	COL_GRAY	// text foreground color

// BMP file header (size 70 bytes)
#pragma pack(push,1)
typedef struct {
    // BMP file header (size 14 bytes)
    uint16_t	bfType;			// 0x00: magic, 'B' 'M' = 0x4D42
    uint32_t	bfSize;			// 0x02: file size, aligned to DWORD = 70 + 320*240*2 + 2 = 153672 = 0x25848
    uint16_t	bfReserved1;		// 0x06: = 0
    uint16_t	bfReserved2;		// 0x08: = 0
    uint32_t	bfOffBits;		// 0x0A: offset of data bits after file header = 70 (0x46)
    // BMP info header (size 40 bytes)
    uint32_t	biSize;			// 0x0E: size of this info header = 56 (0x38)
    s32	biWidth;		// 0x12: width = 320 (0x140)
    s32	biHeight;		// 0x16: height, negate if flip row order = -240 (0xFFFFFF10)
    uint16_t	biPlanes;		// 0x1A: planes = 1
    uint16_t	biBitCount;		// 0x1C: number of bits per pixel = 16
    uint32_t	biCompression;		// 0x1E: compression = 3 (BI_BITFIELDS)
    uint32_t	biSizeImage;		// 0x22: size of data of image + aligned file = 320*240*2 + 2 = 153602 (0x25802)
    s32	biXPelsPerMeter;	// 0x26: X pels per meter = 2834 (= 0xB12)
    s32	biYPelsPerMeter;	// 0x2A: Y pels per meter = 2834 (= 0xB12)
    uint32_t	biClrUsed;		// 0x2E: number of user colors (0 = all)
    uint32_t	biClrImportant;		// 0x32: number of important colors (0 = all)
    // BMP color bit mask (size 16 bytes)
    uint32_t	biRedMask;		// 0x36: red mask = 0x0000F800
    uint32_t	biGreenMask;		// 0x3A: green mask = 0x000007E0
    uint32_t	biBlueMask;		// 0x3E: blue mask = 0x0000001F
    uint32_t	biAlphaMask;		// 0x42: alpha mask = 0x00000000
    // 0x46
} sBmp;
#pragma pack(pop)



#endif //PICO_FIRMWARE_FILE_MANAGER_H
