
// ****************************************************************************
//
//                               Clocks
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz

// (RP2040 datasheet page 199)

#ifndef _SDK_CLOCKS_H
#define _SDK_CLOCKS_H

#include "picopad.h"
#include "hardware/clocks.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CLK_SYS        5

INLINE u32 ClockGetHz(u8 clk) { return clock_get_hz((clock_index) clk); }

#ifdef __cplusplus
}
#endif

#endif // _SDK_CLOCKS_H
