// ****************************************************************************
//
//                              PicoPad Battery
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#ifndef _PICOPAD_BAT_H
#define _PICOPAD_BAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

// Using Pico internal divider 1:2
#define BAT_PIN		29		// input from battery
#define BAT_ADC		3	// ADC input
#define BAT_MUL		3		// voltage multiplier

// init battery measurement
void BatInit();

// get battery voltage in V
float GetBat();

// get battery voltage, integer in mV
int GetBatInt();

// terminate battery measurement
void BatTerm();

#ifdef __cplusplus
}
#endif

#endif // _PICOPAD_BAT_H
