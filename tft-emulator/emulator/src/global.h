// ****************************************************************************
//
//                         Global common C definitions
//
// ****************************************************************************
// https://github.com/Pajenicko/Picopad/blob/main/sdk/global.h

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdint.h>

// Display
#ifndef WIDTH
#define WIDTH	320			// display width
#endif

#ifndef HEIGHT
#define HEIGHT	240			// display height
#endif

#ifndef FRAMESIZE
#define FRAMESIZE (WIDTH*HEIGHT) 	// frame size in number of colors
#endif

#ifndef FONT
#define FONT		FontBold8x16	// default system font
#endif

#ifndef FONTW
#define FONTW		8		// width of system font
#endif

#ifndef FONTH
#define FONTH		16		// height of system font
#endif

// base types - to check type size, use CheckTypeSize()
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;		// on 8-bit system use "signed int"
typedef unsigned short u16;		// on 8-bit system use "unsigned int"
typedef signed long int s32;		// on 64-bit system use "signed int"
typedef unsigned long int u32;		// on 64-bit system use "unsigned int"
typedef signed long long int s64;
typedef unsigned long long int u64;

typedef unsigned int uint;

typedef u16 uint16_t;		// used only by PIO program


// ----------------------------------------------------------------------------
//                               Constants
// ----------------------------------------------------------------------------

#define	B0 (1<<0)
#define	B1 (1<<1)
#define	B2 (1<<2)
#define	B3 (1<<3)
#define	B4 (1<<4)
#define	B7 (1<<7)
#define	B8 (1U<<8)
#define	B9 (1U<<9)
#define	B10 (1U<<10)
#define	B12 (1U<<12)
#define	B13 (1U<<13)
#define	B14 (1U<<14)
#define	B15 (1U<<15)

#define FRACT		12	// number of bits of fractional part of fractint number (use max. 13, min. 8)
#define FRACTMUL (1<<FRACT)	// - update vga_config.h too

// count of array entries
#define count_of(a) (sizeof(a)/sizeof((a)[0]))

#define RGBTO16(r,g,b)	( (((r)&0xf8)<<8) | (((g)&0xfc)<<3) | (((b)&0xf8)>>3) )

// 16-bit color definitions
#define COL_BLACK	0x0000
#define COL_BLUE	0x001F
#define COL_RED		RGBTO16(255,0,0)
#define COL_GREEN	0x07E0
#define COL_CYAN	0x07FF
#define COL_MAGENTA	0xF81F
#define COL_YELLOW	0xFFE0
#define COL_GRAY	RGBTO16(128, 128, 128)
#define COL_WHITE	0xFFFF
#define COL_LTBLUE	RGBTO16(0, 128, 255)
#define COL_ORANGE	RGBTO16(255, 128, 0)

#endif // _GLOBAL_H