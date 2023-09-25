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

#include "include.h"

#if USE_PWMSND

#include "snd/click.h"
#include "snd/battery.h"

// Timer for stop error sound
struct repeating_timer sound_timer;

bool stop_sound(struct repeating_timer *t) {
#if USE_PWMSND
	StopSound();
#endif
	return false;
}

void play_battery_alarm(float timeout) {
	PLAYSOUNDREP(BatteryLowSnd);
#if USE_PWMSND
	PLAYSOUNDREP(BatteryLowSnd);
	add_repeating_timer_us(static_cast<int64_t>((timeout * 1000 * 1000)), stop_sound, nullptr, &sound_timer);
#endif
}

void play_click() {
#if USE_PWMSND
	PLAYSOUND(ClickSnd);
#endif
}

#endif
