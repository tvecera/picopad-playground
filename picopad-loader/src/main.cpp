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
*/

#include <Arduino.h>
#include "include.h"

#include "RP2040.h"
#include "hardware/resets.h"

#define BAR_TIMEOUT 3000000
#define MAX_VOLUME 5
#define MAX_BRIGHTNESS 5

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

static int volume = 5;
static int brightness = 5;
static int battery_alarm = 0;
static int refresh_battery = 0;
static bool update_battery_icon = true;

// Repeating timer for periodical call update battery
struct repeating_timer timer1;
// Timer for stop alarm sound
struct repeating_timer timer2;

// color
const uint16_t battery_icon_color[3] = {
		COL_RED,
		RGBTO16(255, 120, 0),
		RGBTO16(0, 240, 0),
};

static void jump_to_vtor() {
	uint32_t vtor = XIP_BASE + WRITE_ADDR_MIN;
	// Derived from the Leaf Labs Cortex-M3 bootloader.
	// Copyright (c) 2010 LeafLabs LLC.
	// Modified 2021 Brian Starkey <stark3y@gmail.com>
	// Originally under The MIT License
	uint32_t reset_vector = *(volatile uint32_t *) (vtor + 0x04);

	SCB->VTOR = (volatile uint32_t) (vtor);

	asm volatile("msr msp, %0"::"g"
	(*(volatile uint32_t *) vtor));
	asm volatile("bx %0"::"r" (reset_vector));
}

[[noreturn]] static void handle_go() {
	disable_interrupts();

	reset_peripherals();

	jump_to_vtor();

	while (true);
}

int draw_battery_info_icon() {
	int i = BatLevel();

	if (update_battery_icon) {
		uint16_t col;
		if (i <= 4) {
			col = battery_icon_color[0];
		} else if (i <= 8) {
			col = battery_icon_color[1];
		} else {
			col = battery_icon_color[2];
		}

		DrawImgRle(BatteryIconImg, BatteryIconImg_Pal, 6, 0, 30, 20);
		DrawRect(12, 12, 2 + i, 6, col);
	}

	return i;
}

bool update_battery_info(struct repeating_timer *t) {
	int i = draw_battery_info_icon();
	bool alarm = battery_alarm && i <= BATTERY_ALARM_THRESHOLD;

#if USE_PWMSND
	if (alarm) {
		play_battery_alarm(BATTERY_ALARM_DURATION);
	}
#endif

	if (update_battery_icon || alarm)
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

void toggle_repeating_timer() {
	if (refresh_battery > 0) {
		cancel_repeating_timer(&timer1);
		add_repeating_timer_us(refresh_battery * 30 * 1000 * 1000, update_battery_info, nullptr, &timer1);
	}
}

// Setup function to initialize the system and display
void setup() {
	// Initialize serial communication
	Serial.begin(115200);
	delay(100);

	// Initialize the device and display
	device_init();
	DrawClear();
	DispUpdate();

	// Get configuration data
	auto config_data = load_config_data();
	volume = config_data.volume;
	brightness = config_data.brightness;
	refresh_battery = config_data.refresh_battery;
	battery_alarm = config_data.battery_alarm;
	speaker_enabled = volume != 0;

	// Init screensaver
	screensaver_init();

	toggle_repeating_timer();

	delay(100);
}

// Main loop function
void loop() {
	char ch = NOKEY;
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

	if (event) {
		SelFont8x8();
		DrawImgRle(SplashImg, SplashImg_Pal, 0, 0, WIDTH, HEIGHT);

		// set font
		if (speaker_enabled) {
			DrawImgRle(SpeakerImg, SpeakerImg_Pal, 295, 5, 20, 20);
		} else {
			DrawImgRle(SpeakerOffImg, SpeakerOffImg_Pal, 295, 5, 20, 20);
		}

		draw_battery_info_icon();

		if (show_volume) {
			show_bar(292, 40, volume);
			DrawImgRle(SpeakerBarImg, SpeakerBarImg_Pal, 292, 165, 18, 18);
#if USE_PWMSND
			play_click();
#endif
		}
		if (show_screen_brightness) {
			show_bar(10, 40, brightness);
			DrawImgRle(BrightnessImg, BrightnessImg_Pal, 10, 165, 18, 18);
		}

		DispUpdate();
		event = NONE;
	}

	// Keyboard events
	ch = screensaver_reset_timer(KeyGet());
	switch (ch) {

		case KEY_UP: {
			volume = volume < MAX_VOLUME ? volume + 1 : MAX_VOLUME;
			if (!speaker_enabled) {
				speaker_enabled = true;
#if USE_PWMSND
				GlobalSoundSetOn();
#endif
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
#if USE_PWMSND
			SetVolume(volume);
#else
			save_volume(volume);
#endif
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
#if USE_PWMSND
				GlobalSoundSetOff();
#endif
			}
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
#if USE_PWMSND
			SetVolume(volume);
#else
			save_volume(volume);
#endif
			show_volume = true;
			show_screen_brightness = false;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_RIGHT: {
			brightness = brightness < MAX_BRIGHTNESS ? brightness + 1 : MAX_BRIGHTNESS;
			bar_next_timeout = time_us_64() + BAR_TIMEOUT;
			SetBrightness(brightness, true);
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
			SetBrightness(brightness, true);
			show_volume = false;
			show_screen_brightness = true;
			event = UPDATE_SCREEN;
			break;
		}

		case KEY_X: {
			update_battery_icon = false;
			show_system_info();
			KeyFlush();
			event = UPDATE_SCREEN;
			update_battery_icon = true;
			break;
		}

			// Reset to USB BOOT
		case KEY_Y: {
			update_battery_icon = false;
			if (show_bootsel_dialog() == RESULT_OK) {
				DrawClear();
				device_terminate();
				handle_go();
			}
			KeyFlush();
			event = UPDATE_SCREEN;
			update_battery_icon = true;
			break;
		}

		case KEY_B: {
			update_battery_icon = false;
			if (show_file_manager() == RESULT_OK) {
				DrawClear();
				device_terminate();
				handle_go();
			}
			KeyFlush();
			event = UPDATE_SCREEN;
			update_battery_icon = true;
			break;
		}

		case KEY_A: {
			DrawClear();
			device_terminate();
			handle_go();
		}

		default:
			break;
	}
}
