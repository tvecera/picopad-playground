// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#ifndef PICOPAD_GLOBAL_H
#define PICOPAD_GLOBAL_H

#include "pico/time.h"
#include "pico/rand.h"

#define SDK_VER		90	// SDK library version in hundredths

// ----------------------------------------------------------------------------
//                               Attributes
// ----------------------------------------------------------------------------

// count of array entries
#define count_of(a) (sizeof(a)/sizeof((a)[0]))

// request to use inline
#define INLINE __attribute__((always_inline)) inline

// avoid to use inline
#define NOINLINE __attribute__((noinline))

// align array to 4-bytes
#define ALIGNED __attribute__((aligned(4)))

// change endian of u16
#define ENDIAN16(k) ( (((k)>>8)&0xff) | (((k)&0xff)<<8) )

// clamp float value to valid range 0 to 1
#define CLAMP01(val) ( ((val)<=0) ? 0 : ( ((val)>=1) ? 1 : (val) ) )

// clamp value to u8 range
#define CLAMPU8(val) ( ((val)<=0) ? 0 : ( ((val)>=255) ? 255 : (val) ) )

// absolute value
#define ABS(val) ( ((val)<0) ? -(val) : (val) )

// convert 24-bit RGB to 16-bit color
#define RGBTO16(r,g,b)	( (((r)&0xf8)<<8) | (((g)&0xfc)<<3) | (((b)&0xf8)>>3) )

// convert 24-bit RGB to 15-bit color
#define RGBTO15(r,g,b)	( (((r)&0xf8)<<7) | (((g)&0xf8)<<2) | (((b)&0xf8)>>3) )

// place time critical function into RAM
#define NOFLASH(fnc) NOINLINE __attribute__((section(".time_critical." #fnc))) fnc

// ----------------------------------------------------------------------------
//                              Base data types
// ----------------------------------------------------------------------------

/* Basic data types and their sizes (in bytes) depending on the system:

		8-bit	16-bit	32-bit	64-bit
char		1	1	1	1
short		1	1	2	2
int		2	2	4	4
long		4	4	4	4,8
long long	8	8	8	8
*/

// Note: 'char' can be signed or unsigned

// base types - to check type size, use CheckTypeSize()
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;        // on 8-bit system use "signed int"
typedef unsigned short u16;        // on 8-bit system use "unsigned int"
typedef signed long int s32;        // on 64-bit system use "signed int"
typedef unsigned long int u32;        // on 64-bit system use "unsigned int"
typedef signed long long int s64;
typedef unsigned long long int u64;

typedef unsigned int uint;

typedef u16 uint16_t;        // used only by PIO program

typedef unsigned char Bool;
#define True 1
#define False 0

// NULL
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

// ----------------------------------------------------------------------------
//                               Constants
// ----------------------------------------------------------------------------
// Control characters (ASCII characters)
#define CH_NUL		0x00	// NUL null ^@
#define CH_ALL		0x01	// SOH start of heading ^A	... select all
#define CH_BLOCK	0x02	// STX start of text ^B		... mark block
#define CH_COPY		0x03	// ETX end of text ^C		... copy block, copy file
#define CH_END		0x04	// EOT end of transmission ^D	... end of row, end of files
#define CH_MOVE		0x05	// ENQ enquiry ^E		... rename files, move block
#define CH_FIND		0x06	// ACK acknowledge ^F		... find
#define CH_NEXT		0x07	// BEL bell ^G			... repeat find
#define CH_BS		0x08	// BS backspace ^H		... backspace
#define CH_TAB		0x09	// HT horizontal tabulator ^I	... tabulator
#define CH_LF		0x0A	// LF line feed ^J		... line feed
#define CH_PGUP		0x0B	// VT vertical tabulator ^K	... page up
#define CH_PGDN		0x0C	// FF form feed ^L		... page down
#define CH_FF		CH_PGDN
#define CH_CR		0x0D	// CR carriage return ^M	... enter, next row, run file
#define CH_NEW		0x0E	// SO shift-out ^N		... new file
#define CH_OPEN		0x0F	// SI shift-in ^O		... open file, edit file
#define CH_PRINT	0x10	// DLE data link escape ^P	... print file, send file
#define CH_QUERY	0x11	// DC1 device control 1 ^Q	... display help (query)
#define CH_REPLACE	0x12	// DC2 device control 2 ^R	... find and replace
#define CH_SAVE		0x13	// DC3 device control 3 ^S	... save file
#define CH_INS		0x14	// DC4 device control 4 ^T	... toggle Insert switch, mark file
#define CH_HOME		0x15	// NAK negative acknowledge ^U	... begin of row, begin of files
#define CH_PASTE	0x16	// SYN synchronous idle ^V	... paste from clipboard
#define CH_SYN		CH_PASTE
#define CH_CLOSE	0x17	// ETB end of transmission block ^W ... close file
#define CH_CUT		0x18	// CAN cancel ^X		... cut selected text
#define CH_REDO		0x19	// EM end of medium ^Y		... redo previously undo action
#define CH_UNDO		0x1A	// SUB subtitle character ^Z	... undo action
#define CH_ESC		0x1B	// ESC escape ^[		... break, menu
#define CH_RIGHT	0x1C	// FS file separator ^back_slash ... Right, Shift: End, Ctrl: Word right
#define CH_UP		0x1D	// GS group separator ^]	... Up, Shift: PageUp, Ctrl: Text start
#define CH_LEFT		0x1E	// RS record separator ^^	... Left, Shift: Home, Ctrl: Word left
#define CH_DOWN		0x1F	// US unit separator ^_		... Down, Shift: PageDn, Ctrl: Text end
#define CH_SPC		0x20	// SPC space

#define CH_DEL		0x7F	// delete			... delete character on cursor, Ctrl: delete block, delete file

#define _T(a) a		// not using wide characters

#define	B0 (1<<0)
#define	B1 (1<<1)
#define	B2 (1<<2)
#define	B3 (1<<3)
#define	B4 (1<<4)
#define	B5 (1<<5)
#define	B6 (1<<6)
#define	B7 (1<<7)
#define	B8 (1U<<8)
#define	B9 (1U<<9)
#define	B10 (1U<<10)
#define	B11 (1U<<11)
#define	B12 (1U<<12)
#define	B13 (1U<<13)
#define	B14 (1U<<14)
#define	B15 (1U<<15)
#define B30 (1UL<<30)

#define PI 3.14159265358979324
#define PI2 (3.14159265358979324*2)

#define	BIGINT	0x40000000

#ifndef SYS_SPIN
#define SYS_SPIN	31		// system spinlock (memory allocator, safe integer etc.; -1 = not used)
#endif

#define WaitMs(ms) sleep_ms(ms)
#define Time() (to_us_since_boot(get_absolute_time()))
#define Time64() (to_us_since_boot(get_absolute_time()))

#define BOOTLOADER_SIZE	0x30000		// size of boot loader 196608
#define BOOTLOADER_DATA	32		// boot loader resident data

#endif //PICOPAD_GLOBAL_H
