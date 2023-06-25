// ****************************************************************************
//
//                              PicoPad Battery
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "picopad_bat.h"
#include "sdk_adc.h"

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
    // switch to battery input
    ADC_Mux(BAT_ADC);
    float v = ((float)ADC_Single() / (1 << 12)) * 3.3f;

    // get battery voltage
    return v * 3.0f;
}

// get battery voltage, integer in mV
int GetBatInt()
{
    // switch to battery input
    ADC_Mux(BAT_ADC);

    // get battery voltage
    return ADC_SingleUint()*BAT_MUL;
}

// terminate battery measurement
void BatTerm()
{
    // terminate battery GPIO
    ADC_PinTerm(BAT_PIN);

    // disable ADC
    ADC_Disable();
}
