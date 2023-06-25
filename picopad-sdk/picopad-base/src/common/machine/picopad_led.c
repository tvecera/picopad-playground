// ****************************************************************************
//
//                              PicoPad LEDs
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "hardware/gpio.h"
#include "picopad_led.h"

// GPIO with LED
const u8 LedGpioTab[LED_NUM] = {
	LED1_PIN,	// LED1 inverted, blue, on right
	LED2_PIN,	// default internal LED pin, on Pico board
};

// GPIO invert flag
const Bool LedGpioTabInv[LED_NUM] = {
	True,		// LED1 inverted, blue, on right
	False,		// default internal LED pin, on Pico board
};

// set LED ON (inx = LED index LED?)
void LedOn(u8 inx)
{
	gpio_put(LedGpioTab[inx], 1);
}

// set LED OFF (inx = LED index LED?)
void LedOff(u8 inx)
{
    gpio_put(LedGpioTab[inx], 0);
}

// set LED (inx = LED index LED?)
void LedSet(u8 inx, u8 val)
{
	if (val == 0) LedOff(inx); else LedOn(inx);
}

// initialize LEDs
void LedInit()
{
	int i;
	for (i = 0; i < LED_NUM; i++)
	{
        gpio_init(LedGpioTab[i]);
        gpio_set_dir(LedGpioTab[i], GPIO_OUT);
		if (LedGpioTabInv[i]) gpio_set_outover(LedGpioTab[i], GPIO_OVERRIDE_INVERT);
		LedOff(i);
	}
}

// terminate LEDs
void LedTerm()
{
	int i;
	for (i = 0; i < LED_NUM; i++)
	{
        gpio_deinit(LedGpioTab[i]);
	}
}
