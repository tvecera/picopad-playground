
// ****************************************************************************
//
//                              Decode number
//
// ****************************************************************************
// https://github.com/pajenicko/picopad

#ifndef _DECNUM_H
#define _DECNUM_H

#include "config_def.h"

#if USE_DECNUM		// use DecNum (decnum.c, decnum.h)

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

// temporary decode text buffer
#define DECNUMBUF_SIZE	16		// max. size of decode text buffer
extern char DecNumBuf[DECNUMBUF_SIZE];

// decode unsigned number into ASCIIZ text buffer (returns number of digits)
//  sep = thousand separator, 0=none
int DecUNum(char* buf, u32 num, char sep);

// decode signed number into ASCIIZ text buffer (returns number of digits)
//  sep = thousand separator, 0=none
int DecNum(char* buf, s32 num, char sep);

// decode hex number (dig = number of digits)
void DecHexNum(char* buf, u32 num, u8 dig);

// decode 2 digits of number
void Dec2Dig(char* buf, u8 num);

// decode 2 digits of number with space character
void Dec2DigSpc(char* buf, u8 num);

#ifdef __cplusplus
}
#endif

#endif // USE_DECNUM		// use DecNum (decnum.c, decnum.h)

#endif // _DECNUM_H

