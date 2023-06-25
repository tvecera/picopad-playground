
// ****************************************************************************
//
//                             PicoPad Boot Loader
//
// ****************************************************************************
// Based on the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "main.h"
#include "RP2040.h"
#include "hardware/resets.h"
#include "hardware/watchdog.h"

#include "st7789.h"
#include "lib_drawtft.h"
#include "lib_pwmsnd.h"
#include "picopad_key.h"
#include "picopad_bat.h"
#include "picopad_init.h"
#include "sdk_watchdog.h"
#include "sdk_flash.h"
#include "sdk_config.h"
#include "../img/icons.h"
#include "../img/splash.h"
#include "../snd/click.h"

#include "../file-manager/src/file_manager.h"
#include "system_info.h"

static void disable_interrupts() {
    SysTick->CTRL &= ~1;

    NVIC->ICER[0] = 0xFFFFFFFF;
    NVIC->ICPR[0] = 0xFFFFFFFF;
}

static void reset_peripherals() {
    reset_block(~(
            RESETS_RESET_IO_QSPI_BITS |
            RESETS_RESET_PADS_QSPI_BITS |
            RESETS_RESET_SYSCFG_BITS |
            RESETS_RESET_PLL_SYS_BITS
    ));
}

static void jump_to_vtor(u32 vtor) {
    // Derived from the Leaf Labs Cortex-M3 bootloader.
    // Copyright (c) 2010 LeafLabs LLC.
    // Modified 2021 Brian Starkey <stark3y@gmail.com>
    // Originally under The MIT License
    u32 reset_vector = *(volatile u32 *) (vtor + 0x04);


    SCB->VTOR = (volatile u32) (vtor);

    asm volatile("msr msp, %0"::"g"
    (*(volatile u32 *) vtor));
    asm volatile("bx %0"::"r" (reset_vector));
}

static void handle_go(u32 vtor) {
    disable_interrupts();

    reset_peripherals();

    jump_to_vtor(vtor);

    while (1);
}

// color
const u16 battery_icon_color[3] = {
        COL_RED,
        RGBTO16(255, 120, 0),
        RGBTO16(0, 240, 0),
};

void update_battery_info() {
    float bat = GetBat();
    int i = (bat - BATTERY_EMPTY) / (BATTERY_FULL - BATTERY_EMPTY) * 12;
    u16 col = battery_icon_color[2];
    if (i < 0) {
        i = 0;
        col = battery_icon_color[0];
    }
    if (i > 0 && i <= 4) col = battery_icon_color[0];
    if (i > 4 && i <= 8) col = battery_icon_color[1];;
    if (i > 8) col = battery_icon_color[2];
    if (i > 12) i = 12;
    DrawImgRle(BatteryIconImg, BatteryIconImg_Pal, 6, 0, 30, 20);
    DrawRect(12, 12, 2 + i, 6, col);
}

#define MAX_VOLUME 5

#define BAR_COLOR RGBTO16(100, 103, 125)
#define BAR_STEP_HEIGHT 24
#define PADDING 4
#define BAR_HEIGHT 120
#define BAR_WIDTH 18

void show_bar(int x, int y, int value, int color = BAR_COLOR) {
    const int radius = BAR_WIDTH / 2;

    DrawRect(x + 1, y + radius + 2, BAR_WIDTH - 1, BAR_HEIGHT - 2 * radius - 2, COL_WHITE);
    DrawFillCircle(x + radius, y + radius + 4, radius, COL_WHITE);
    DrawFillCircle(x + radius, y + BAR_HEIGHT - radius, radius, COL_WHITE);

    if (value > 0) {
        const int innerGap = (PADDING / 2);
        const int innerRadius = radius - innerGap;
        const int innerHeight = (value - 1) * BAR_STEP_HEIGHT;
        const int innerWidth = BAR_WIDTH - PADDING;
        const int innerStartY = (y + BAR_HEIGHT) - radius;

        DrawRect(x + innerGap + 1, innerStartY - innerHeight, innerWidth - 1, innerHeight, color);
        DrawFillCircle(x + radius, innerStartY - innerHeight - 1, innerRadius, color);
        DrawFillCircle(x + radius, innerStartY - 1, innerRadius, color);
    }
}

int main() {
    DeviceInit(True);
    uint64_t next_time = 0;
    uint64_t bar_timeout = 0;

    bool update_screen = true;
    bool show_volume = true;
    bool show_screen_brightness = true;
    int volume = load_config_data().volume;
    int brightness = load_config_data().brightness;

    // check loader magic
    Bool loader = (watchdog_hw->scratch[4] == WATCHDOG_LOADER_MAGIC);
    watchdog_hw->scratch[4] = 0;
    bool speaker_enabled = volume != 0;

    // main loop
    while (True) {
        uint64_t current_time = time_us_64();
        if (current_time >= next_time) {
            next_time = current_time + 30000000;
            update_screen = true;
        }
        if (bar_timeout <= current_time) {
            if (show_volume) {
                show_volume = false;
                update_screen = true;
            }
            if (show_screen_brightness) {
                show_screen_brightness = false;
                update_screen = true;
            }
        }

        if (update_screen) {
            SelFont8x8();
            DrawImgRle(SplashImg, SplashImg_Pal, 0, 0, WIDTH, HEIGHT);

            // set font
            if (speaker_enabled) {
                DrawImgRle(SpeakerImg, SpeakerImg_Pal, 295, 5, 20, 20);
            } else {
                DrawImgRle(SpeakerOffImg, SpeakerOffImg_Pal, 295, 5, 20, 20);
            }
            update_battery_info();

            if (show_volume) {
                show_bar(292, 40, volume);
                DrawImgRle(SpeakerBarImg, SpeakerBarImg_Pal, 292, 165, 18, 18);
                PLAYSOUND(ClickSnd);
            }
            if (show_screen_brightness) {
                show_bar(10, 40, brightness);
                DrawImgRle(BrightnessImg, BrightnessImg_Pal, 10, 165, 18, 18);
            }

            DispUpdate();
            update_screen = false;
        }

        // keyboard service
        switch (KeyGet()) {
            case KEY_UP:
                if (volume < MAX_VOLUME) {
                    volume++;
                }
                if (!speaker_enabled) {
                    speaker_enabled = true;
                    GlobalSoundSetOn();
                }
                bar_timeout = time_us_64() + 3000000;
                set_volume(volume);
                show_volume = true;
                update_screen = true;
                show_screen_brightness = false;
                break;

            case KEY_DOWN:
                if (volume > 0) {
                    volume--;
                }
                if (volume == 0) {
                    speaker_enabled = false;
                    GlobalSoundSetOff();
                }
                bar_timeout = time_us_64() + 3000000;
                set_volume(volume);
                show_volume = true;
                update_screen = true;
                show_screen_brightness = false;
                break;

            case KEY_RIGHT:
                if (brightness < MAX_VOLUME) {
                    brightness++;
                }
                bar_timeout = time_us_64() + 3000000;
                set_brightness(brightness);
                show_volume = false;
                update_screen = true;
                show_screen_brightness = true;
                break;

            case KEY_LEFT:
                if (brightness > 0) {
                    brightness--;
                }
                bar_timeout = time_us_64() + 3000000;
                set_brightness(brightness);
                show_volume = false;
                update_screen = true;
                show_screen_brightness = true;
                break;

            case KEY_A:
                handle_go(XIP_BASE + WRITE_ADDR_MIN);
                update_screen = true;
                break;

            case KEY_X:
                show_system_info();
                KeyFlush();
                update_screen = true;
                break;

                // Reset to USB BOOT
            case KEY_Y:
                reset_to_bootsel();
                break;

                // sound
            case KEY_B:
                bool result = show_file_manager();
                if (result) {
                    handle_go(XIP_BASE + WRITE_ADDR_MIN);
                }
                KeyFlush();
                update_screen = true;
                break;
        }
    }
}
