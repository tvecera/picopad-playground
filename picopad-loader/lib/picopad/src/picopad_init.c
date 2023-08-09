
// ****************************************************************************
//
//                              PicoPad Init
//
// ****************************************************************************
// PicoLibSDK - Alternative SDK library for Raspberry Pico and RP2040
// Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
// 	https://github.com/Panda381/PicoLibSDK
//	https://www.breatharian.eu/hw/picolibsdk/index_en.html
//	https://github.com/pajenicko/picopad
//	https://picopad.eu/en/
// License:
//	This source code is freely available for any purpose, including commercial.
//	It is possible to take and modify the code or parts of it, without restriction.

#include "picopad.h"

// Repeating timer for periodical call KeyScan
struct repeating_timer timer0;

bool repeating_timer_callback(struct repeating_timer *t) {
	KeyScan();
	return true;
}

// Device init
void DeviceInit() {
	// initialize LEDs
	LedInit();

#if USE_SD
	SDInit();
	sleep_ms(100);
#else
	// Disable SD LED
	gpio_init(SD_CS);
	gpio_put(SD_CS, 1);
	gpio_set_dir(SD_CS, GPIO_OUT);
#endif

	// Try to load config file from SD card
	load_config_file();

#if USE_ST7789
	// initialize display
	DispInit(1);
#endif

	// initilize keys
	KeyInit();

	// init battery measurement
	BatInit();

#if USE_PWMSND    // use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)
	// initialize PWM sound output (must be re-initialized after changing CLK_SYS system clock)
	PWMSndInit();
#endif

#if SYSTICK_KEYSCAN
	add_repeating_timer_us(500, repeating_timer_callback, NULL, &timer0);
#endif
}

// Device terminate
void DeviceTerm() {
	// terminate LEDs
	LedTerm();

#if USE_ST7789
	// terminate display
	DispTerm();
#endif

	// terminate keys
	KeyTerm();

	// terminate battery measurement
	BatTerm();

#if USE_PWMSND  // use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)
	// terminate PWM sound output
	PWMSndTerm();
#endif

#if USE_SD    // use SD card (lib_sd.c, lib_sd.h)
	// terminate SD card interface
	SDTerm();
#endif

#if SYSTICK_KEYSCAN
	cancel_repeating_timer(&timer0);
#endif
}
