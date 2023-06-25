// ****************************************************************************
//
//                                 ADC controller
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "sdk_adc.h"

// temperature noise reduction
#if TEMP_NOISE > 0
u16 ADCTempHist[TEMP_NOISE];		// deep of temperature history
u32 ADCTempHistSum = 0;			// sum of history
int ADCTempHistNum = 0;			// number of entries
int ADCTempHistInx = 0;			// index in temperature history
#endif // TEMP_NOISE

void ADC_Init() {
    adc_init();
}

void ADC_Mux(u8 input) {
    adc_select_input(input);
}

// do single conversion (takes 96 clock cycles = 2 us on 48 MHz clock)
u16 ADC_Single() {
    return adc_read();
}

// do single conversion with denoise (returns value 0..0xffff; takes 32 us on 48 MHz clock
u16 ADC_SingleDenoise() {
    int i;
    u16 t = 0;
    for (i = 16; i > 0; i--) t += ADC_Single();
    return t;
}

// do single conversion and recalculate to voltage on 3.3V
float ADC_SingleU() {
    return ADC_SingleDenoise() * 3.3f / (4096 * 16);
}

// do single conversion and recalculate to voltage on 3.3V, integer in mV (range 0..3300)
int ADC_SingleUint() {
    return ADC_SingleDenoise() * 3300 / (4096 * 16);
}

void ADC_PinInit(u8 pin) {
    adc_gpio_init(pin);
}

void ADC_PinTerm(u8 pin) {
    gpio_deinit(pin);
}

void ADC_Disable() {
    adc_hw->cs = 0;
}

// get current temperature in �C
float ADC_Temp()
{
    // enable temperature sensor
    adc_set_temp_sensor_enabled(true);

    // select ADC input
    ADC_Mux(ADC_MUX_TEMP);

    // do single conversion with fast denoise
    u16 t = ADC_SingleDenoise();

    // temperature noise reduction
#if TEMP_NOISE > 0
    ADCTempHistSum += t;
	if (ADCTempHistNum < TEMP_NOISE) // initialize
	{
		ADCTempHistNum++;
		ADCTempHist[ADCTempHistInx] = t;
		t = (ADCTempHistSum + ADCTempHistNum/2) / ADCTempHistNum;
	}
	else
	{
		ADCTempHistSum -= ADCTempHist[ADCTempHistInx];
		ADCTempHist[ADCTempHistInx] = t;
		t = (ADCTempHistSum + TEMP_NOISE/2) / TEMP_NOISE;
	}
	ADCTempHistInx++;
	if (ADCTempHistInx >= TEMP_NOISE) ADCTempHistInx = 0;
#endif // TEMP_NOISE

    // do single conversion (T = 27 - (ADC_voltage - 0.706) / 0.001721)
    return 27 - (t*3.3f/(4096*16) - 0.706f) / 0.001721f;
}
