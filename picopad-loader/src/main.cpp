// ****************************************************************************
//
//                             PicoPad Boot Loader
//
// ****************************************************************************
// Based on the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "Arduino.h"
#include "RP2040.h"
#include "hardware/resets.h"
#include "picopad.h"
#include "fonts/picopad_fonts.h"
#include "img/icons.h"
#include "img/splash.h"
#include "snd/click.h"
#include "snd/battery.h"
#include "system_info.h"
#include "sdk_flash.h"
#include "file_manager.h"

#define BAR_TIMEOUT 3000000
#define MAX_VOLUME 5

#define BAR_COLOR RGBTO16(100, 103, 125)
#define BAR_STEP_HEIGHT 24
#define PADDING 4
#define BAR_HEIGHT 120
#define BAR_WIDTH 18

typedef enum {
		NONE,
		UPDATE_SCREEN
} event_t;

event_t event = UPDATE_SCREEN;

bool show_volume = true;
bool show_screen_brightness = true;
bool speaker_enabled = true;

uint64_t bar_next_timeout = 0;
uint64_t sleep_next_timeout = 0;

int volume = 5;
int brightness = 5;
int battery_alarm = 0;
int64_t screen_sleep = 0;
int64_t refresh_battery = 0;

// Repeating timer for periodical call update battery
struct repeating_timer timer1;

// color
const u16 battery_icon_color[3] = {
		COL_RED,
		RGBTO16(255, 120, 0),
		RGBTO16(0, 240, 0),
};

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

static void jump_to_vtor() {
	u32 vtor = XIP_BASE + WRITE_ADDR_MIN;
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

[[noreturn]] static void handle_go() {
	disable_interrupts();

	reset_peripherals();

	jump_to_vtor();

	while (true);
}

bool update_battery_info(struct repeating_timer *t) {
	int i = BatLevel();

	u16 col;
	if (i <= 4) {
		col = battery_icon_color[0];
	} else if (i <= 8) {
		col = battery_icon_color[1];
	} else {
		col = battery_icon_color[2];
	}

	DrawImgRle(BatteryIconImg, BatteryIconImg_Pal, 6, 0, 30, 20);
	DrawRect(12, 12, 2 + i, 6, col);

	if (battery_alarm && i <= BATTERY_ALARM_THRESHOLD)
		PLAYSOUND(BatteryLowSnd);

	if (t != nullptr)
		DispUpdate();

	return true;
}

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

void sleep_display() {
	LedFlip(LED1);
	DispOnOff(false);
	while (KeyGet() == NOKEY);
	DispOnOff(true);
	LedFlip(LED1);
}

void toggle_repeating_timer(bool cancel = false) {
	if (cancel) {
		cancel_repeating_timer(&timer1);
	} else {
		if (refresh_battery > 0) {
			refresh_battery = refresh_battery * 30 * 1000 * 1000;
			add_repeating_timer_us(refresh_battery, update_battery_info, nullptr, &timer1);
		}
	}
}

// Setup function to initialize the system and display
void setup() {
	// Initialize serial communication
	Serial.begin(115200);
	delay(100);
	Serial.println("SCD41 sensor application starting...");

	// Initialize the device and display
	DeviceInit();
	DrawClear();
	DispUpdate();

	// Get configuration data
	auto config_data = load_config_data();
	volume = config_data.volume;
	brightness = config_data.brightness;
	refresh_battery = config_data.refresh_battery;
	screen_sleep = config_data.screen_sleep;
	battery_alarm = config_data.battery_alarm;

	// check loader magic
	watchdog_hw->scratch[4] = 0;

	speaker_enabled = volume != 0;
	screen_sleep = screen_sleep == 0 ? INT64_MAX : screen_sleep * 120 * 1000 * 1000;
	sleep_next_timeout = time_us_64() + screen_sleep;

	toggle_repeating_timer();

	delay(100);
}

// Main loop function
void loop() {
	uint64_t current_time = time_us_64();

	if (bar_next_timeout <= current_time) {
		if (show_volume) {
			show_volume = false;
			event = UPDATE_SCREEN;
		}
		if (show_screen_brightness) {
			show_screen_brightness = false;
			event = UPDATE_SCREEN;
		}
	}

	if (!event && sleep_next_timeout <= current_time) {
		sleep_display();
		sleep_next_timeout = time_us_64() + screen_sleep;
		event = UPDATE_SCREEN;
	}

	if (event) {
		SelFont8x8();
		DrawImgRle(SplashImg, SplashImg_Pal, 0, 0, WIDTH, HEIGHT);

		// set font
		if (speaker_enabled) {
			DrawImgRle(SpeakerImg, SpeakerImg_Pal, 295, 5, 20, 20);
		} else {
			DrawImgRle(SpeakerOffImg, SpeakerOffImg_Pal, 295, 5, 20, 20);
		}
		update_battery_info(nullptr);

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
		event = NONE;
	}

	// keyboard service
	switch (KeyGet()) {

		case KEY_UP: {
			if (volume < MAX_VOLUME) {
				volume++;
			}
			if (!speaker_enabled) {
				speaker_enabled = true;
				GlobalSoundSetOn();
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
			SetVolume(volume);
			show_volume = true;
			show_screen_brightness = false;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_DOWN: {
			if (volume > 0) {
				volume--;
			}
			if (volume == 0) {
				speaker_enabled = false;
				GlobalSoundSetOff();
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
			SetVolume(volume);
			show_volume = true;
			show_screen_brightness = false;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_RIGHT: {
			if (brightness < MAX_VOLUME) {
				brightness++;
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
			SetBrightness(brightness);
			show_volume = false;
			show_screen_brightness = true;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_LEFT: {
			if (brightness > 0) {
				brightness--;
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
			SetBrightness(brightness);
			show_volume = false;
			show_screen_brightness = true;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_X: {
			show_system_info();
			KeyFlush();
			event = UPDATE_SCREEN;
			break;
		}

			// Reset to USB BOOT
		case KEY_Y: {
			reset_to_bootsel();
			break;
		}

		case KEY_B: {
			toggle_repeating_timer(true);
			bool result = show_file_manager();
			if (result) {
				DrawClear();
				DeviceTerm();
				handle_go();
			}
			KeyFlush();
			event = UPDATE_SCREEN;
			toggle_repeating_timer();
			break;
		}

		case KEY_A:
			DrawClear();
			DeviceTerm();
			handle_go();
	}
}
