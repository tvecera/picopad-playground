
// ****************************************************************************
//
//                          Display controller ST7789
//
// ****************************************************************************
// PicoLibSDK - Alternative SDK library for Raspberry Pico and RP2040
// Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
// 	https://github.com/Panda381/PicoLibSDK
//	https://www.breatharian.eu/hw/picolibsdk/index_en.html
//	https://github.com/pajenicko/picopad
//	https://picopad.eu/en/
// License:
//	This source code is freely available for any purpose, including commercial.
//	It is possible to take and modify the code or parts of it, without restriction.

#if USE_ST7789

#ifndef _ST7789_H
#define _ST7789_H

#ifdef __cplusplus
extern "C" {
#endif

// DISP_SPI_BAUD	24000000
// send data: 320x240x2 = 153600 B = 1 228 800 bits
// transfer time: 51 ms, real time: 70 ms
#define DISP_FRAME_MS (320*240*2*9*1000/DISP_SPI_BAUD)	// transfer time of whole frame in [ms]

// initialize display
//  rot ... rotation mode
//		0 Portrait
//		1 Landscape
//		2 Inverted Portrait
//		3 Inverted Landscape
void DispInit(u8 rot);

void DispWindow(u16 x1, u16 x2, u16 y1, u16 y2);

void DispWriteData(const void* data, int len);

// terminate display
void DispTerm();

void DrawLine(u16 *row, u16 line);

void DrawLines(u16 *data, u16 y1, u16 y2, int len);

void DrawClearCol(u16 col);

void DrawClear();

void set_brightness(u8 value);

#ifdef __cplusplus
}
#endif

#endif // _ST7789_H

#endif
