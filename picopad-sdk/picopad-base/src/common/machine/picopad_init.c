// ****************************************************************************
//
//                              PicoPad Init
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "st7789.h"
#include "hardware/gpio.h"
#include "picopad_bat.h"
#include "picopad_key.h"
#include "picopad_led.h"
#include "sdk_config.h"
#include "lib_sd.h"
#include "lib_pwmsnd.h"
#include "lib_rand.h"
#include "lib_mem.h"

// Device init
void DeviceInit(bool load_config_from_sd)
{
    // select GPIO function
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    // initialize LEDs
	LedInit();

	if (load_config_from_sd) {
		// initialize SD card interface (must be re-initialized after changing system clock)
		SDInit();
		sleep_ms(100);
		load_config_from_sd_card();
	}

	// initialize display
	DispInit(1);

	// initilize keys
	KeyInit();

	// init battery measurement
	BatInit();

    RandInit();

    MemInit();

#if USE_PWMSND		// use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)
	// initialize PWM sound output (must be re-initialized after changing CLK_SYS system clock)
	PWMSndInit();
#endif
}

// Device terminate
void DeviceTerm()
{
	// terminate LEDs
	LedTerm();

	// terminate display
	DispTerm();

	// terminate keys
	KeyTerm();

	// terminate battery measurement
	BatTerm();

#if USE_PWMSND	// use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)
	// terminate PWM sound output
	PWMSndTerm();
#endif

#if USE_SD		// use SD card (lib_sd.c, lib_sd.h)
	// terminate SD card interface
	SDTerm();
#endif
}
