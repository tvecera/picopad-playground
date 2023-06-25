// ****************************************************************************
//
//                             PicoPad System Info
//
// ****************************************************************************
// Based on the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "system_info.h"
#include "pico/printf.h"

#include "st7789.h"
#include "lib_drawtft.h"
#include "sdk_bootrom.h"
#include "sdk_adc.h"

#include "picopad_pico_info.h"
#include "picopad_key.h"
#include "picopad_fonts.h"
#include "picopad_bat.h"
#include <string.h>

#include "../img/battery.cpp"

// color
const u16 BatCol[8] = {
        COL_BLACK,        // 0
        COL_RED,        // 1
        RGBTO16(255, 120, 0),    // 2
        RGBTO16(255, 120, 0),    // 3
        RGBTO16(255, 240, 0),    // 4
        RGBTO16(255, 240, 0),    // 5
        RGBTO16(0, 240, 0),    // 6
        RGBTO16(0, 240, 0),    // 7
};

u8 battery_info() {
    u8 ch = NOKEY;
    DrawClear(COL_BLACK);
    KeyFlush();
    int i;

    // set font
    pDrawFont = FontBold8x16; // font 8x8
    DrawFontHeight = 16; // font height

    char buffer[30];
    char sdkTxt[20];
    snprintf(sdkTxt, sizeof(sdkTxt), "SDK version %.2f", SDK_VER * 0.01f);

    do {

        // draw battery
        i = 7;
        if (i < 0) i = 0;
        if (i > 7) i = 7;
        DrawImgRle(BatteryImg, BatteryImg_Pal, 0, 0, 128, 240);

        u16 col = BatCol[i];
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

        // SDK version
        DrawTextBg(sdkTxt, DISPX + (DISPW - strlen(sdkTxt) * 8) / 2, y, COL_WHITE, COL_BLACK);
        y += DY;

        // temperature
        snprintf(buffer, sizeof(buffer), " Temperature %.1f`C ", ADC_Temp());
        DrawTextBg(buffer, DISPX + (DISPW - strlen(buffer) * 8) / 2, y, COL_WHITE, COL_BLACK);
        y += DY;

        // battery
        snprintf(buffer, sizeof(buffer), " Battery %.2fV ", GetBat());
        DrawTextBg(buffer, DISPX + (DISPW - strlen(buffer) * 8) / 2, y, COL_WHITE, COL_BLACK);
        y += DY;

        // redraw display
        DispUpdate();

        sleep_ms(20);

        ch = KeyGet();

    } while (ch == NOKEY);

    return ch;
}

u8 system_info() {
    u8 ch = NOKEY;
    DrawClear(COL_BLACK);
    KeyFlush();

    // Draws the sensor image to the display.
    DrawImgRle(SystemInfoImg_RLE, SystemInfoImg_Pal, 0, 0, 320, 240);

    DrawImgRle(ArrowBatteryImg_RLE, ArrowBatteryImg_Pal, 238, 212, 72, 21);

    // set font
    pDrawFont = FontBold8x8; // font 8x8
    DrawFontHeight = 8; // font height

    do {
        MemoryUsage memoryUsage;
        get_memory_usage(&memoryUsage);
        char ram_size[50];
        snprintf(ram_size, sizeof(ram_size), "Ram size: %0.2f kB", memoryUsage.ram_size / 1024.0f);
//        char total_heap[50];
//        snprintf(total_heap, sizeof(total_heap), "Total heap: %0.3f kB", memoryUsage.total_heap / 1024.0f);
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
//    DrawText(totalCores, x, y, COL_WHITE);
//    y += i_increment;

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
//        DrawText(total_heap, x, y, COL_WHITE);
//        y += i_increment;
        DrawText(free_heap, x, y, COL_WHITE);
        y += i_increment;

        // redraw display
        DispUpdate();

        sleep_ms(20);

        ch = KeyGet();

    } while (ch == NOKEY);

    return ch;

}

void show_system_info() {
    KeyFlush();

    u8 ch = NOKEY;
    u8 page = 1;

    while (True) {
        if (page == 1)
            ch = battery_info();
        else
            ch = system_info();

        if (ch == KEY_Y) return;
        if (ch == KEY_RIGHT || ch == KEY_LEFT) {
            if (page == 1) {
                page = 2;
            } else {
                page = 1;
            }
        }
    }
}
