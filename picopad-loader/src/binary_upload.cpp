/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
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
*
* NOTICE FOR DERIVED CODE:
*  Throughout this file, sections marked with the comment "Derived from PicoLibSDK" are based on or derived from the
*  PicoLibSDK by Miroslav Nemecek. The original work can be found at:
*  Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
*  Repository: https://github.com/Panda381/PicoLibSDK
*/

#include <Arduino.h>
#include "include.h"

// Constants and defines for buffer and file sizes.
#define BUFFER_SIZE (FLASH_PAGE_SIZE * 4)
#define MAX_FILE_SIZE (PICO_FLASH_SIZE_BYTES - WRITE_ADDR_MIN)

// Enumeration for different upload states.
typedef enum {
		begin,
		filesize,
		filecrc,
		flash,
} upload_status_t;

// Structure to hold the current context of the file upload process.
static struct {
		upload_status_t phase;
		uint32_t len, len_i, crc;
		char buf[256];
		int page;
		int addr;
} context;

// Reset the context to its default state.
void reset_context() {
	memset(&context, 0, sizeof(context));
}

// Function to display an information page on the device screen.
void disp_info_page(const char *title, const char *subtitle = "") {
	DrawClear();
	DrawImgRle(CopyImg_RLE, CopyImg_Pal, (WIDTH / 2) - (82 / 2), 20, 83, 84);
	int title_len = static_cast<int>(strlen(title));
	int subtitle_len = static_cast<int>(strlen(subtitle));

	SelFont8x16();
	DrawTextBg2(title, (WIDTH - title_len * 16) / 2, 120, COL_LTORANGE, COL_BLACK);
	if (subtitle_len > 0) {
		DrawTextBg(subtitle, (WIDTH - subtitle_len * 8) / 2, 120 + 40, COL_WHITE, COL_BLACK);
	}
	DispUpdate();
}

// Function to display an error message and waits for a key to be pressed.
uint8_t disp_error_page(uint8_t code) {
#if USE_PWMSND
	play_battery_alarm(0.5);
#endif
	DrawClear();
	result_t error_message = get_result_detail(code);
	int len = static_cast<int>(strlen(error_message.message));
	int len_second = static_cast<int>(strlen(error_message.message_two));

	SelFont8x16();
	DrawImgRle(ErrorImg_RLE, ErrorImg_Pal, (WIDTH / 2) - (52 / 2), 20, 52, 84);
	DrawTextBg2(error_message.message, (WIDTH - len * 16) / 2, 125, COL_MDKRED, COL_BLACK);
	DrawTextBg2(error_message.message_two, (WIDTH - len_second * 16) / 2, 125 + 32, COL_MDKRED, COL_BLACK);
	DrawTextBg("Press any key", (WIDTH - 13 * 8) / 2, 130 + 74, COL_WHITE, COL_BLACK);

	DispUpdate();
	KeyFlush();
	char ch = NOKEY;
	while (ch == NOKEY) {
		ch = screensaver_reset_timer(KeyGet());
	}

	DrawClear();
	DispUpdate();

	return code;
}

// Function to display a progress bar on the screen.
// Derived from PicoLibSDK
void disp_progress_bar(int i, int n, uint16_t col) {
#define PROGRESS_X 32
#define PROGRESS_Y 195
#define PROGRESS_W 256
#define PROGRESS_H 16

	DrawFrame(PROGRESS_X - 2, PROGRESS_Y - 2, PROGRESS_W + 4, PROGRESS_H + 4, COL_WHITE);
	DrawRect(PROGRESS_X, PROGRESS_Y, PROGRESS_W, PROGRESS_H, COL_MDKGRAY);
	DrawRect(PROGRESS_X, PROGRESS_Y, i * PROGRESS_W / n, PROGRESS_H, col);
	DispUpdate();
}

// Function to delete an application (erases a segment of memory).
// Derived from PicoLibSDK
uint8_t delete_app(int size) {
	// Display the erasing message.
	disp_info_page("Erasing", "Application flash memory");

	// Find start address
	uint32_t addr = XIP_BASE + WRITE_ADDR_MIN;
	uint32_t count = size;
	if (count <= 0)
		count = MAX_FILE_SIZE;
	else
		count = count + 0x8000;
	const auto *s = (const uint32_t *) (addr + count);
	while (count >= 4) {
		if (s[-1] != (uint32_t) -1) break;
		s--;
		count -= 4;
	}
	count = (count + 0x8000 - 4) & ~0x7fff;

	int n = static_cast<int>(count);
	int k;
	while (count >= 0x1000) {
		disp_progress_bar(static_cast<int>(n - count), n, COL_MDKRED);

		k = static_cast<int>(count);
		if (((addr & 0xffff) == 0x8000) && (count >= 0x8000))
			k = 0x8000;
		else if (k >= 0x10000) k = 0x10000;

		if (!FlashErase(addr - XIP_BASE, k)) {
			return RESULT_ERROR_ERASE_FLASH;
		}
		addr += k;
		count -= k;
	}
	disp_progress_bar(n, n, COL_MDKRED);
	delay(50);

	return RESULT_OK;
}

// Function to write a binary file to the flash memory.
uint8_t flash_binary(int addr, const uint8_t *data, uint32_t count, int size) {
	// Update progress bar
	disp_progress_bar(static_cast<int>(addr - WRITE_ADDR_MIN), size, COL_LTORANGE);

	// Flash program pages
	return FlashProgram(addr, (const u8 *) data, count) ? RESULT_OK : RESULT_ERROR_FLASH_PROGRAM;
}

// Function to flash an application file from storage to memory.
// Derived from PicoLibSDK
uint8_t flash_application_file(char *path, char *filename) {
	char buff[BUFFER_SIZE + 1];
	int read_count;
	int remaining_bytes, file_position, addr, pages_count, total_file_size;
	FIL file;
	uint8_t res;

	// open file
	disp_info_page("Loading", "Try to open file");

	set_dir(path);
	if (!file_open(&file, filename, FA_READ)) {
		return RESULT_ERROR_OPEN_FILE;
	}

	remaining_bytes = static_cast<int>(file_size(&file));

	if (remaining_bytes > MAX_FILE_SIZE) {
		file_close(&file);
		return RESULT_ERROR_LARGE_FILE;
	}

	// Erase application flash memory
	res = delete_app(remaining_bytes);
	if (res != RESULT_OK) {
		file_close(&file);
		return res;
	}

	disp_info_page("Loading", "Application to flash memory");

	file_position = 0;
	file_position -= FLASH_PAGE_SIZE;
	pages_count = 0;
	total_file_size = remaining_bytes;
	addr = WRITE_ADDR_MIN;

	// Loading program into memory
	do {
		// Load next 4 program pages
		while ((pages_count <= BUFFER_SIZE - FLASH_PAGE_SIZE) && (remaining_bytes > 0)) {
			file_position += FLASH_PAGE_SIZE;
			file_seek(&file, file_position);
			read_count = file_read(&file, &buff[pages_count], FLASH_PAGE_SIZE);
			pages_count += FLASH_PAGE_SIZE;
			remaining_bytes -= FLASH_PAGE_SIZE;
		}

		res = flash_binary(addr, (const u8 *) buff, pages_count, total_file_size);
		if (res != RESULT_OK) {
			file_close(&file);
			return res;
		}

		// Go to the next page start address
		addr += pages_count;
		if (remaining_bytes <= 0) break;
		pages_count = 0;

	} while (read_count > 0);

	file_close(&file);

	return RESULT_OK;
}

const int STARTING_SEQUENCE[8] = {7, 3, 9, 3, 9, 1, 7, 3};

// Function to flash binary content received from a serial connection.
uint8_t flash_binary_serial() {
	char ch = NOKEY;
	uint8_t res;
	disp_info_page("Waiting...", "User serial connection");

	while (true) {
		ch = screensaver_reset_timer(KeyGet());

		if (ch == KEY_Y) {
			reset_context();
			Serial.println("UPLOAD_CANCEL");
			return RESULT_CANCEL;
		}

		if (Serial.available() > 0) {
			int c = Serial.read();
			if (c == PICO_ERROR_TIMEOUT) {
				reset_context();
				return disp_error_page(RESULT_ERROR_SERIAL_TIMEOUT);
			}

			switch (context.phase) {
				case begin:
					if (c == STARTING_SEQUENCE[context.len_i]) {
						context.len_i++;

						if (context.len_i == 8) {
							Serial.println("ACK");
							reset_context();
							context.phase = filecrc;
						}
					} else {
						Serial.printf("%s\n", get_result_detail(RESULT_ERROR_INVALID_SEQUENCE).name);
						context.len_i = 0;
					}
					break;
				case filecrc:
					// Waiting for binary file CRC
					((char *) (&context.crc))[context.len_i++] = c;
					if (context.len_i >= sizeof(uint32_t)) {
						Serial.printf("ACK CRC32 0x%lx\n", context.crc);
						context.phase = filesize;
						context.len_i = 0;

						disp_info_page("Loading", "Application to flash memory");
					}
					break;
				case filesize:
					// Waiting for binary file size
					((char *) (&context.len))[context.len_i++] = c;
					if (context.len_i >= sizeof(uint32_t)) {
						if (context.len > MAX_FILE_SIZE) {
							Serial.printf("%s 0x%lx\n", get_result_detail(RESULT_ERROR_LARGE_FILE).name, context.len);
							reset_context();
							return disp_error_page(RESULT_ERROR_LARGE_FILE);
						}
						// Delete flash region of the new application size
						res = delete_app(static_cast<int>(context.len));
						if (res != RESULT_OK) {
							Serial.printf("%s 0x%lx\n", get_result_detail(res).name, context.len);
							reset_context();
							return disp_error_page(res);
						}

						Serial.printf("ACK FILESIZE 0x%lx\n", context.len);

						context.phase = flash;
						context.len_i = 0;
						context.page = 0;
						context.addr = WRITE_ADDR_MIN;

						disp_info_page("Loading", "Application to flash memory");
					}
					break;
				case flash:
					context.buf[context.len_i++ % FLASH_PAGE_SIZE] = c;
					if (context.len_i % FLASH_PAGE_SIZE == 0 || context.len_i == context.len) {
						res = flash_binary(context.addr, (const u8 *) context.buf, FLASH_PAGE_SIZE, static_cast<int>(context.len));
						if (res != RESULT_OK) {
							Serial.printf("%s 0x%lx\n", get_result_detail(res).name, context.len_i);
							reset_context();
							return disp_error_page(res);
						}
						context.addr += FLASH_PAGE_SIZE;
					}

					if (context.len_i == context.len) {
						const auto *app = (const uint32_t *) (XIP_BASE + WRITE_ADDR_MIN);
						uint32_t crc = CRC32(app, static_cast<int>(context.len));

						if (crc != context.crc) {
							Serial.printf("%s\n", get_result_detail(RESULT_ERROR_INVALID_CRC).name);
							reset_context();
							return disp_error_page(RESULT_ERROR_INVALID_CRC);
						}

						Serial.printf("ACK FLASH 0x%lx\n", context.len_i);
						reset_context();
						return RESULT_OK;
					}
					break;
			}
		}
	}
}

uint8_t show_bootsel_dialog() {
	KeyFlush();

	uint8_t ch = NOKEY;
	uint8_t res;

	while (True) {
		DrawClear();

		SelFont8x8();
		int dy = 30;
		int dh = 60;
		DrawFillRect(0, dy - (dh / 4), WIDTH, dh, COL_MDKGRAY);
		DrawFillRoundRect(10, dy, 100, dh / 2, 3, COL_LTORANGE);
		DrawText("A", 20, dy + (dh / 4) - 4, COL_MDKGRAY);
		DrawText("BOOTSEL", 42, dy + (dh / 4) - 4, COL_MDKGRAY);

		SelFont6x8();
		DrawText("Restart Picopad to BOOTSEL mode,", 123, dy, COL_WHITE);
		DrawText("allowing you to load the UF2", 123, dy + 10, COL_WHITE);
		DrawText("firmware into Picopad.", 123, dy + 20, COL_WHITE);


		SelFont8x8();
		dy = dy + dh + 15;
		DrawFillRoundRect(10, dy, 100, dh / 2, 3, COL_LTORANGE);
		DrawText("B", 20, dy + (dh / 4) - 4, COL_MDKGRAY);
		DrawText("SERIAL", 42, dy + (dh / 4) - 4, COL_MDKGRAY);

		SelFont6x8();
		DrawText("Open the SERIAL UPLOAD mode,", 123, dy, COL_WHITE);
		DrawText("which allows you to load the", 123, dy + 10, COL_WHITE);
		DrawText("PP2 binaries via UART serial.", 123, dy + 20, COL_WHITE);


		SelFont8x8();
		dy = dy + dh + 15;
		DrawFillRoundRect(10, dy, 100, dh / 2, 3, COL_LTORANGE);
		DrawText("X", 20, dy + (dh / 4) - 4, COL_MDKGRAY);
		DrawText("RESET", 42, dy + (dh / 4) - 4, COL_MDKGRAY);

		SelFont6x8();
		DrawText("Restart Picopad using the", 123, dy, COL_WHITE);
		DrawText("watchdog to enter the", 123, dy + 10, COL_WHITE);
		DrawText("bootloader.", 123, dy + 20, COL_WHITE);

		DispUpdate();

		ch = screensaver_reset_timer(KeyGet());

		switch (ch) {
			case KEY_A:
				reset_to_bootsel();
				break;
			case KEY_B:
				res = flash_binary_serial();
				if (res != RESULT_OK) {
					Serial.flush();
					disp_error_page(res);
					device_terminate();
					reset_to_boot_loader();
				}
				return res;
				break;
			case KEY_X:
				DrawClear();
				device_terminate();
				reset_to_boot_loader();
				break;
			case KEY_Y:
				return RESULT_CANCEL;
				break;
		}
	}
}
