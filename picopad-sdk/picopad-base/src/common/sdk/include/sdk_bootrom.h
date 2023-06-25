
// ****************************************************************************
//
//                                Boot ROM
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz

#ifndef _SDK_BOOTROM_H
#define _SDK_BOOTROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

INLINE u8 RomGetVersion() { return 4; }

#ifdef __cplusplus
}
#endif

#endif // _SDK_BOOTROM_H
