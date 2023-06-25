
// ****************************************************************************
//
//                              Watchdog Timer
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz

// Time source is shared with main timer counter.

#ifndef _SDK_WATCHDOG_H
#define _SDK_WATCHDOG_H

#include "picopad.h"
#include "pico.h"

#ifdef __cplusplus
extern "C" {
#endif

void reset_to_bootsel();

// reset to boot loader
void ResetToBootLoader();

#ifdef __cplusplus
}
#endif

#endif // _SDK_WATCHDOG_H
