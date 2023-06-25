#ifndef _PICOPAD_ADC_H
#define _PICOPAD_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

#define ADC_MUX_GPIO29	3	// pin GPIO 29
#define ADC_MUX_TEMP	4	// temperature sensor

void ADC_Init();

void ADC_PinInit(u8 pin);

void ADC_Mux(u8 input);

u16 ADC_SingleDenoise();

u16 ADC_Single();

float ADC_SingleU();

void ADC_PinTerm(u8 pin);

int ADC_SingleUint();

void ADC_Disable();

float ADC_Temp();

#ifdef __cplusplus
}
#endif

#endif //_PICOPAD_ADC_H
