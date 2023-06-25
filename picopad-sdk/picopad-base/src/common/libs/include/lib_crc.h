
// ****************************************************************************
//
//                                CRC Check Sum
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz
// https://github.com/pajenicko/picopad

// CRC-32 Normal and Reversed
// CRC-16 CCITT Normal, Reversed and Normal Alternative
// CRC-8 Dallas
// Parity
// Simple checksum on 8-bit, 16-bit and 32-bit data
// CRC-XOR

#include "config_def.h"

#if USE_CRC    // use CRC Check Sum (lib_crc.c, lib_crc.h)

#ifndef _CRC_H
#define _CRC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

// CRC-32 Normal (CRC32A) polynomial
#define CRC32A_POLY 0x04C11DB7

// CRC-32 Normal (CRC32A) init word (not reversed, not inverted)
#define CRC32A_INIT 0xFFFFFFFF

// Calculate CRC-32 Normal (CRC32A) - slow version
//   Calculation speed: 790 us per 1 KB
u32 Crc32ASlow(const void *buf, int len);

// Calculate CRC-32 Normal (CRC32A), buffer - slow version
u32 Crc32ABufSlow(u32 crc, const void *buf, int len);

// Calculate CRC-32 Normal (CRC32A) - DMA version (uses DMA_TEMP_CHAN() temporary channel)
//   Calculation speed: 2 us per 1 KB
// Can be used simultaneously in both CPUs, but not simultaneously in an interrupt.
u32 Crc32ADMA(const void *ptr, int len);

#ifdef __cplusplus
}
#endif

#endif // _CRC_H

#endif // USE_CRC	// use CRC Check Sum (lib_crc.c, lib_crc.h)
