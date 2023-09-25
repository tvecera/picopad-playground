/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
*
* Portions of this software are derived from the PicoLibSDK:
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

#include <Arduino.h>
#include "include.h"
#include "malloc.h"
#include "pico/printf.h"

// color
const uint16_t BatCol[8] = {
		COL_BLACK,             // 0
		COL_RED,               // 1
		RGBTO16(255, 120, 0),  // 2
		RGBTO16(255, 120, 0),  // 3
		RGBTO16(255, 240, 0),  // 4
		RGBTO16(255, 240, 0),  // 5
		RGBTO16(0, 240, 0),    // 6
		RGBTO16(0, 240, 0),    // 7
};


uint32_t get_total_heap() {
	return &__StackLimit  - &__bss_end__;
}

uint32_t get_free_heap() {
	struct mallinfo m = mallinfo();
	return get_total_heap() - m.uordblks;
}

void get_memory_usage(MemoryUsage* usage) {
	usage->ram_size = (uint32_t)&__bss_end__ - (uint32_t)&__data_start__;
	usage->total_heap = get_total_heap();
	usage->free_heap = get_free_heap();
}

void get_flash_usage(FlashUsage* usage) {
	usage->total_size = PICO_FLASH_SIZE_BYTES;
	usage->bootloader_size = (uint32_t)&__boot2_end__ - (uint32_t)&__boot2_start__;
	usage->app_flash_size = (uint32_t)&__flash_binary_end - (uint32_t)&__boot2_end__;
}

void get_cpu_info(CpuInfo *info) {
	info->clockSpeedHz = clock_get_hz(clk_sys);
	info->chipVersion = rp2040_chip_version();

	pico_unique_board_id_t tempUniqueId;
	pico_get_unique_board_id(&tempUniqueId);
	for (int i = 0; i < PICO_UNIQUE_BOARD_ID_SIZE_BYTES; i++) {
		sprintf(&info->uniqueId[2*i], "%02x", tempUniqueId.id[i]);
	}

	info->runningCore = get_core_num();
	info->totalCores = 2; // RP2040 always has 2 cores
}

uint8_t battery_info() {
	uint8_t ch = NOKEY;
	DrawClear();
	KeyFlush();
	int i;

	// set font
	pDrawFont = FontBold8x16; // font 8x8
	DrawFontHeight = 16; // font height

	char buffer[30];
	char loaderTxt[20];
	snprintf(loaderTxt, sizeof(loaderTxt), "Loader version %s", LOADER_VERSION);

	do {
		// draw battery
		float bat = GetBat();
		i = (bat - BATTERY_EMPTY) / (BATTERY_FULL - BATTERY_EMPTY) * 8;
		if (i < 0) i = 0;
		if (i > 7) i = 7;
		DrawImgRle(BatteryImg, BatteryImg_Pal, 0, 0, 128, 240);

		uint16_t col = BatCol[i];
		if (i > 0) {
			for (i--; i >= 0; i--) DrawRect(25, 198 - i * 26, 77, 19, col);
		}

		DrawImgRle(ArrowInfoImg_RLE, ArrowInfoImg_Pal, 238, 212, 72, 21);

#define DISPX    128
#define DISPW    (WIDTH-128)
#define DY    25
		int y = 30;

		// title
		DrawText2("PicoPad", DISPX + (DISPW - 7 * 16) / 2, y, RGBTO16(239, 192, 16));
		y += 50;

		// Loader version
		DrawTextBg(loaderTxt, DISPX + (DISPW - strlen(loaderTxt) * 8) / 2, y, COL_WHITE, COL_BLACK);
		y += DY;

		// temperature
		snprintf(buffer, sizeof(buffer), " Temperature %.1f`C ", analogReadTemp());
		DrawTextBg(buffer, DISPX + (DISPW - strlen(buffer) * 8) / 2, y, COL_WHITE, COL_BLACK);
		y += DY;

		// battery
		snprintf(buffer, sizeof(buffer), " Battery %.2fV ", GetBat());
		DrawTextBg(buffer, DISPX + (DISPW - strlen(buffer) * 8) / 2, y, COL_WHITE, COL_BLACK);
		y += DY;

		// redraw display
		DispUpdate();

		ch = wait_for_keypress(5000);

	} while (ch == NOKEY);

	return ch;
}

uint8_t system_info() {
	uint8_t ch = NOKEY;
	DrawClear();
	KeyFlush();

	// Draws the sensor image to the display.
	DrawImgRle(SystemInfoImg_RLE, SystemInfoImg_Pal, 3, 0, 59, 240);

	DrawImgRle(ArrowBatteryImg_RLE, ArrowBatteryImg_Pal, 238, 212, 72, 21);

	// set font
	pDrawFont = FontBold8x8; // font 8x8
	DrawFontHeight = 8; // font height

	do {
		MemoryUsage memoryUsage;
		get_memory_usage(&memoryUsage);
		char ram_size[50];
		snprintf(ram_size, sizeof(ram_size), "Total heap: %0.2f kB", memoryUsage.ram_size / 1024.0f);
		char free_heap[50];
		snprintf(free_heap, sizeof(free_heap), "Free heap: %0.2f kB", memoryUsage.free_heap / 1024.0f);

		FlashUsage flashUsage;
		get_flash_usage(&flashUsage);
		char total_size[50];
		snprintf(total_size, sizeof(total_size), "Flash size: %0.3f MB", flashUsage.total_size / 1024.0f / 1024.0f);
		char bootloader_size[50];
		snprintf(bootloader_size, sizeof(bootloader_size), "Bootloader: %lu b", flashUsage.bootloader_size);
		char app_flash_size[50];
		snprintf(app_flash_size, sizeof(app_flash_size), "Loader: %0.2f kB", flashUsage.app_flash_size / 1024.0f);

		CpuInfo cpuInfo;
		get_cpu_info(&cpuInfo);
		char clockSpeedHz[50];
		snprintf(clockSpeedHz, sizeof(clockSpeedHz), "Clock speed: %lu MHz", cpuInfo.clockSpeedHz / 1000 / 1000);
		char chipVersion[50];
		snprintf(chipVersion, sizeof(chipVersion), "Chip version: %lu", cpuInfo.chipVersion);
		char uniqueId[50];
		snprintf(uniqueId, sizeof(uniqueId), "Unique ID: %s", cpuInfo.uniqueId);
		char runningCore[50];
		snprintf(runningCore, sizeof(runningCore), "Running on core: %d", cpuInfo.runningCore);
		char totalCores[50];
		snprintf(totalCores, sizeof(totalCores), "Total cores: %d", cpuInfo.totalCores);

		int y = 12;
		int x = 75;
		const int i_increment = 20;

		DrawText(clockSpeedHz, x, y, COL_WHITE);
		y += i_increment;
		DrawText(chipVersion, x, y, COL_WHITE);
		y += i_increment;
		DrawText(runningCore, x, y, COL_WHITE);
		y += i_increment;

		y += 20;

		DrawText(total_size, x, y, COL_WHITE);
		y += i_increment;
		DrawText(bootloader_size, x, y, COL_WHITE);
		y += i_increment;
		DrawText(app_flash_size, x, y, COL_WHITE);
		y += i_increment;

		y += 20;

		DrawText(uniqueId, x, y, COL_WHITE);
		y += i_increment;
		DrawText(ram_size, x, y, COL_WHITE);
		y += i_increment;
		DrawText(free_heap, x, y, COL_WHITE);

		// redraw display
		DispUpdate();

		ch = wait_for_keypress(2000);
	} while (ch == NOKEY);

	return ch;
}

uint8_t show_system_info() {
	KeyFlush();

	uint8_t ch = NOKEY;
	uint8_t page = 1;

	while (True) {
		if (page == 1)
			ch = battery_info();
		else
			ch = system_info();

		ch = screensaver_reset_timer(ch);

		if (ch == KEY_Y) return RESULT_CANCEL;
		if (ch == KEY_RIGHT || ch == KEY_LEFT) {
			if (page == 1) {
				page = 2;
			} else {
				page = 1;
			}
		}
	}
}
