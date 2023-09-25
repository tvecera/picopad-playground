/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
* Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef PICOPAD_CLICK_SND_H
#define PICOPAD_CLICK_SND_H

#include "picopad.h"

// sound format: PCM mono 8-bit 22050Hz
const u8 ClickSnd[220] __attribute__ ((aligned(4))) = {
		0x7F, 0xD1, 0xF6, 0xE2, 0xB1, 0x8D, 0x8B, 0x9F, 0xAA, 0x9D, 0x81, 0x6F, 0x73, 0x81, 0x83, 0x6D, 0x53, 0x51, 0x73,
		0xA5, 0xBD, 0xA1, 0x5A, 0x16, 0x00, 0x21, 0x5E, 0x8E, 0x9B, 0x91, 0x8D, 0x9D, 0xB9, 0xC7, 0xBE, 0xA8, 0x9C, 0xA4,
		0xB0, 0xA4, 0x75, 0x39, 0x17, 0x2A, 0x69, 0xA8, 0xBE, 0xA2, 0x6D, 0x47, 0x45, 0x5B, 0x6D, 0x6A, 0x5D, 0x5A, 0x6E,
		0x8B, 0x9B, 0x96, 0x89, 0x90, 0xB6, 0xE8, 0xFD, 0xDE, 0x94, 0x49, 0x27, 0x37, 0x61, 0x7E, 0x7C, 0x67, 0x58, 0x5F,
		0x73, 0x7F, 0x78, 0x69, 0x66, 0x78, 0x90, 0x94, 0x78, 0x4E, 0x3D, 0x5C, 0xA1, 0xE4, 0xFD, 0xE3, 0xAF, 0x86, 0x7A,
		0x83, 0x85, 0x74, 0x59, 0x48, 0x4C, 0x5B, 0x61, 0x55, 0x47, 0x4E, 0x75, 0xAA, 0xC8, 0xB6, 0x7F, 0x47, 0x36, 0x53,
		0x88, 0xAE, 0xB6, 0xA7, 0x9C, 0xA1, 0xB0, 0xB4, 0xA3, 0x89, 0x78, 0x7B, 0x82, 0x77, 0x4F, 0x1E, 0x06, 0x1E, 0x5E,
		0x9F, 0xBC, 0xAC, 0x85, 0x6B, 0x6E, 0x84, 0x95, 0x93, 0x85, 0x7F, 0x8A, 0x9C, 0xA2, 0x95, 0x82, 0x80, 0x9A, 0xBF,
		0xCC, 0xAD, 0x6B, 0x29, 0x0D, 0x20, 0x4B, 0x6C, 0x73, 0x6A, 0x66, 0x74, 0x8D, 0x9E, 0x9C, 0x91, 0x90, 0x9E, 0xB0,
		0xAD, 0x8E, 0x62, 0x4B, 0x5E, 0x92, 0xC5, 0xD5, 0xB9, 0x87, 0x60, 0x56, 0x5E, 0x63, 0x5A, 0x48, 0x41, 0x4D, 0x63,
		0x70, 0x6E, 0x68, 0x75, 0x9B, 0xCB, 0xE5, 0xD3, 0x9D, 0x67, 0x50, 0x62, 0x88, 0xA2, 0xA0, 0x8D, 0x7D, 0x7D, 0x87,
		0x89, 0x7B, 0x66, 0x5C, 0x64, 0x71, 0x6E, 0x54, 0x31, 0x24, 0x41
};

#endif //PICOPAD_CLICK_SND_H
