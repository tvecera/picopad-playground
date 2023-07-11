// ****************************************************************************
//
//                              PicoPad Battery
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "picopad_bat.h"
#include "sdk_adc.h"
#include "config_def.h"
#include "hardware/gpio.h"

// init battery measurement
void BatInit()
{
    // ADC init
    ADC_Init();

    // init battery GPIO
    ADC_PinInit(BAT_PIN);
}

// get battery voltage in V
float GetBat()
{
    // workaroud for battery measurement on Pico W
    gpio_init(LED_PIN);
    gpio_pull_down(LED_PIN);
    gpio_set_dir(LED_PIN, true);
    gpio_put(LED_PIN, true);

    // switch to battery input
    ADC_Mux(BAT_ADC);

    // get battery voltage
    float voltage = ADC_SingleU()*BAT_MUL+BAT_DIODE_FV;
    gpio_deinit(LED_PIN);
    return voltage;
}

// get battery voltage, integer in mV
int GetBatInt()
{
    // workaroud for battery measurement on Pico W
    gpio_init(LED_PIN);
    gpio_pull_down(LED_PIN);
    gpio_set_dir(LED_PIN, true);

    // switch to battery input
    ADC_Mux(BAT_ADC);
    // get battery voltage
    int voltage = ADC_SingleUint()*BAT_MUL+BAT_DIODE_FV_INT;

    gpio_deinit(LED_PIN);
    return voltage;
}

// terminate battery measurement
void BatTerm()
{
    // terminate battery GPIO
    ADC_PinTerm(BAT_PIN);

    // disable ADC
    ADC_Disable();
}
