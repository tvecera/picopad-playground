/**
 * Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
 * Repository: https://github.com/Panda381/PicoLibSDK
 */

#include "pico/stdlib.h"

// format: 1-bit pixel graphics
// image width: 2048 pixels
// image height: 8 lines
// image pitch: 256 bytes
const uint8_t FontBold8x8[2048] __attribute__ ((aligned(4))) = {
	0x00, 0xAA, 0x00, 0x00, 0x6C, 0x10, 0x10, 0x10, 0x3C, 0x3C, 0x30, 0x38, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 
	0x00, 0x18, 0x6C, 0x6C, 0x18, 0x60, 0x38, 0x18, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0x3C, 0x18, 0x3C, 0x3C, 0x1C, 0x7E, 0x1C, 0x7E, 0x3C, 0x3C, 0x00, 0x00, 0x0C, 0x00, 0x60, 0x3C, 
	0x3C, 0x18, 0x7C, 0x3C, 0x78, 0x7E, 0x7E, 0x3C, 0x66, 0x7E, 0x06, 0x63, 0x60, 0xC6, 0xC6, 0x3C, 
	0x7C, 0x3C, 0x7C, 0x3C, 0x7E, 0x66, 0x66, 0xC6, 0xC3, 0xC3, 0x7E, 0x3C, 0xC0, 0x3C, 0x18, 0x00, 
	0x38, 0x00, 0x60, 0x00, 0x06, 0x00, 0x1C, 0x00, 0x60, 0x18, 0x0C, 0x60, 0x38, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x18, 0x38, 0x76, 0x06, 
	0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 
	0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 
	0xFF, 0xE7, 0x93, 0x93, 0xE7, 0x9F, 0xC7, 0xE7, 0xF3, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
	0xC3, 0xE7, 0xC3, 0xC3, 0xE3, 0x81, 0xE3, 0x81, 0xC3, 0xC3, 0xFF, 0xFF, 0xF3, 0xFF, 0x9F, 0xC3, 
	0xC3, 0xE7, 0x83, 0xC3, 0x87, 0x81, 0x81, 0xC3, 0x99, 0x81, 0xF9, 0x9C, 0x9F, 0x39, 0x39, 0xC3, 
	0x83, 0xC3, 0x83, 0xC3, 0x81, 0x99, 0x99, 0x39, 0x3C, 0x3C, 0x81, 0xC3, 0x3F, 0xC3, 0xE7, 0xFF, 
	0xC7, 0xFF, 0x9F, 0xFF, 0xF9, 0xFF, 0xE3, 0xFF, 0x9F, 0xE7, 0xF3, 0x9F, 0xC7, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xE7, 0xC7, 0x89, 0xF9, 
	0x00, 0x55, 0x18, 0x18, 0xFE, 0x38, 0x38, 0x38, 0x42, 0x7E, 0x28, 0x38, 0x08, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 
	0x00, 0x18, 0x6C, 0x6C, 0x7E, 0x66, 0x6C, 0x18, 0x18, 0x18, 0x6C, 0x18, 0x00, 0x00, 0x00, 0x06, 
	0x66, 0x38, 0x66, 0x66, 0x3C, 0x60, 0x30, 0x06, 0x66, 0x66, 0x00, 0x00, 0x18, 0x00, 0x30, 0x66, 
	0x6E, 0x3C, 0x66, 0x66, 0x6C, 0x60, 0x60, 0x66, 0x66, 0x18, 0x06, 0x66, 0x60, 0xEE, 0xE6, 0x66, 
	0x66, 0x66, 0x66, 0x66, 0x18, 0x66, 0x66, 0xC6, 0x66, 0x66, 0x06, 0x30, 0x60, 0x0C, 0x3C, 0x00, 
	0x6C, 0x00, 0x60, 0x00, 0x06, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x0C, 0xDC, 0x06, 
	0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 
	0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 0xFF, 0xFF, 0xD7, 0xD7, 
	0xFF, 0xE7, 0x93, 0x93, 0x81, 0x99, 0x93, 0xE7, 0xE7, 0xE7, 0x93, 0xE7, 0xFF, 0xFF, 0xFF, 0xF9, 
	0x99, 0xC7, 0x99, 0x99, 0xC3, 0x9F, 0xCF, 0xF9, 0x99, 0x99, 0xFF, 0xFF, 0xE7, 0xFF, 0xCF, 0x99, 
	0x91, 0xC3, 0x99, 0x99, 0x93, 0x9F, 0x9F, 0x99, 0x99, 0xE7, 0xF9, 0x99, 0x9F, 0x11, 0x19, 0x99, 
	0x99, 0x99, 0x99, 0x99, 0xE7, 0x99, 0x99, 0x39, 0x99, 0x99, 0xF9, 0xCF, 0x9F, 0xF3, 0xC3, 0xFF, 
	0x93, 0xFF, 0x9F, 0xFF, 0xF9, 0xFF, 0xCF, 0xFF, 0x9F, 0xFF, 0xFF, 0x9F, 0xE7, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xE7, 0xF3, 0x23, 0xF9, 
	0x00, 0xAA, 0x24, 0x3C, 0xFE, 0x7C, 0x54, 0x7C, 0xA5, 0xDB, 0x24, 0x10, 0x0C, 0x38, 0x30, 0x10, 
	0x18, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 
	0x00, 0x18, 0x6C, 0xFE, 0xD8, 0x0C, 0x38, 0x30, 0x30, 0x0C, 0x38, 0x18, 0x00, 0x00, 0x00, 0x0C, 
	0x6E, 0x78, 0x06, 0x06, 0x6C, 0x7C, 0x60, 0x06, 0x66, 0x66, 0x18, 0x18, 0x30, 0x7E, 0x18, 0x06, 
	0x6E, 0x66, 0x66, 0x60, 0x66, 0x60, 0x60, 0x60, 0x66, 0x18, 0x06, 0x6C, 0x60, 0xFE, 0xF6, 0x66, 
	0x66, 0x66, 0x66, 0x60, 0x18, 0x66, 0x66, 0xC6, 0x3C, 0x3C, 0x0C, 0x30, 0x30, 0x0C, 0x66, 0x00, 
	0x38, 0x3C, 0x7C, 0x3C, 0x3E, 0x3C, 0x7C, 0x3E, 0x7C, 0x38, 0x1C, 0x66, 0x18, 0xCC, 0x7C, 0x3C, 
	0x7C, 0x3E, 0x7C, 0x3E, 0x7E, 0x66, 0x66, 0xC6, 0xC6, 0x66, 0x7E, 0x30, 0x18, 0x0C, 0x00, 0x0E, 
	0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 
	0xE7, 0x0F, 0xD7, 0x17, 0xE0, 0x00, 0xD0, 0x10, 0xFF, 0x07, 0xD7, 0x17, 0xC0, 0x00, 0xD0, 0x10, 
	0xFF, 0xE7, 0x93, 0x01, 0x27, 0xF3, 0xC7, 0xCF, 0xCF, 0xF3, 0xC7, 0xE7, 0xFF, 0xFF, 0xFF, 0xF3, 
	0x91, 0x87, 0xF9, 0xF9, 0x93, 0x83, 0x9F, 0xF9, 0x99, 0x99, 0xE7, 0xE7, 0xCF, 0x81, 0xE7, 0xF9, 
	0x91, 0x99, 0x99, 0x9F, 0x99, 0x9F, 0x9F, 0x9F, 0x99, 0xE7, 0xF9, 0x93, 0x9F, 0x01, 0x09, 0x99, 
	0x99, 0x99, 0x99, 0x9F, 0xE7, 0x99, 0x99, 0x39, 0xC3, 0xC3, 0xF3, 0xCF, 0xCF, 0xF3, 0x99, 0xFF, 
	0xC7, 0xC3, 0x83, 0xC3, 0xC1, 0xC3, 0x83, 0xC1, 0x83, 0xC7, 0xE3, 0x99, 0xE7, 0x33, 0x83, 0xC3, 
	0x83, 0xC1, 0x83, 0xC1, 0x81, 0x99, 0x99, 0x39, 0x39, 0x99, 0x81, 0xCF, 0xE7, 0xF3, 0xFF, 0xF1, 
	0x00, 0x55, 0x42, 0x7E, 0xFE, 0xFE, 0xFE, 0xFE, 0x81, 0xFF, 0x24, 0x7C, 0x7E, 0x7C, 0x7E, 0x10, 
	0x3C, 0xF0, 0x10, 0xF0, 0x1F, 0xFF, 0x1F, 0xFF, 0x10, 0xF0, 0x10, 0xF0, 0x1F, 0xFF, 0x1F, 0xFF, 
	0x00, 0x18, 0x00, 0x6C, 0x7C, 0x18, 0x76, 0x00, 0x30, 0x0C, 0xFE, 0x7E, 0x00, 0x7E, 0x00, 0x18, 
	0x76, 0x18, 0x0C, 0x1C, 0xCC, 0x06, 0x7C, 0x0C, 0x3C, 0x3E, 0x18, 0x18, 0x60, 0x00, 0x0C, 0x0C, 
	0x6C, 0x66, 0x7C, 0x60, 0x66, 0x7C, 0x7C, 0x6E, 0x7E, 0x18, 0x06, 0x78, 0x60, 0xD6, 0xDE, 0x66, 
	0x7C, 0x66, 0x7C, 0x3C, 0x18, 0x66, 0x66, 0xD6, 0x18, 0x18, 0x18, 0x30, 0x18, 0x0C, 0x00, 0x00, 
	0x00, 0x06, 0x66, 0x60, 0x66, 0x66, 0x30, 0x66, 0x66, 0x18, 0x0C, 0x6C, 0x18, 0xFE, 0x66, 0x66, 
	0x66, 0x66, 0x66, 0x60, 0x30, 0x66, 0x66, 0xC6, 0x6C, 0x66, 0x0C, 0x60, 0x18, 0x06, 0x00, 0xCC, 
	0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 
	0xC3, 0xFF, 0xD7, 0xF7, 0xFF, 0xFF, 0xDF, 0xFF, 0xD7, 0xF7, 0xD7, 0xF7, 0xDF, 0xFF, 0xDF, 0xFF, 
	0xFF, 0xE7, 0xFF, 0x93, 0x83, 0xE7, 0x89, 0xFF, 0xCF, 0xF3, 0x01, 0x81, 0xFF, 0x81, 0xFF, 0xE7, 
	0x89, 0xE7, 0xF3, 0xE3, 0x33, 0xF9, 0x83, 0xF3, 0xC3, 0xC1, 0xE7, 0xE7, 0x9F, 0xFF, 0xF3, 0xF3, 
	0x93, 0x99, 0x83, 0x9F, 0x99, 0x83, 0x83, 0x91, 0x81, 0xE7, 0xF9, 0x87, 0x9F, 0x29, 0x21, 0x99, 
	0x83, 0x99, 0x83, 0xC3, 0xE7, 0x99, 0x99, 0x29, 0xE7, 0xE7, 0xE7, 0xCF, 0xE7, 0xF3, 0xFF, 0xFF, 
	0xFF, 0xF9, 0x99, 0x9F, 0x99, 0x99, 0xCF, 0x99, 0x99, 0xE7, 0xF3, 0x93, 0xE7, 0x01, 0x99, 0x99, 
	0x99, 0x99, 0x99, 0x9F, 0xCF, 0x99, 0x99, 0x39, 0x93, 0x99, 0xF3, 0x9F, 0xE7, 0xF9, 0xFF, 0x33, 
	0x00, 0xAA, 0x42, 0x7E, 0x7C, 0x7C, 0x54, 0xFE, 0xA5, 0xFF, 0x28, 0x10, 0x0C, 0x10, 0x30, 0x7C, 
	0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x18, 0x00, 0xFE, 0x36, 0x30, 0xDC, 0x00, 0x30, 0x0C, 0x38, 0x18, 0x00, 0x00, 0x00, 0x30, 
	0x66, 0x18, 0x38, 0x06, 0xFE, 0x06, 0x66, 0x18, 0x66, 0x06, 0x00, 0x00, 0x30, 0x7E, 0x18, 0x18, 
	0x60, 0x7E, 0x66, 0x60, 0x66, 0x60, 0x60, 0x66, 0x66, 0x18, 0x06, 0x6C, 0x60, 0xC6, 0xCE, 0x66, 
	0x60, 0x66, 0x6C, 0x06, 0x18, 0x66, 0x66, 0xFE, 0x3C, 0x18, 0x30, 0x30, 0x0C, 0x0C, 0x00, 0x00, 
	0x00, 0x3E, 0x66, 0x60, 0x66, 0x7E, 0x30, 0x66, 0x66, 0x18, 0x0C, 0x78, 0x18, 0xD6, 0x66, 0x66, 
	0x66, 0x66, 0x60, 0x3C, 0x30, 0x66, 0x66, 0xD6, 0x38, 0x66, 0x18, 0x30, 0x18, 0x0C, 0x00, 0xDC, 
	0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xC3, 0x0F, 0xFF, 0x07, 0xE0, 0x00, 0xC0, 0x00, 0xD7, 0x17, 0xD7, 0x17, 0xD0, 0x10, 0xD0, 0x10, 
	0xFF, 0xE7, 0xFF, 0x01, 0xC9, 0xCF, 0x23, 0xFF, 0xCF, 0xF3, 0xC7, 0xE7, 0xFF, 0xFF, 0xFF, 0xCF, 
	0x99, 0xE7, 0xC7, 0xF9, 0x01, 0xF9, 0x99, 0xE7, 0x99, 0xF9, 0xFF, 0xFF, 0xCF, 0x81, 0xE7, 0xE7, 
	0x9F, 0x81, 0x99, 0x9F, 0x99, 0x9F, 0x9F, 0x99, 0x99, 0xE7, 0xF9, 0x93, 0x9F, 0x39, 0x31, 0x99, 
	0x9F, 0x99, 0x93, 0xF9, 0xE7, 0x99, 0x99, 0x01, 0xC3, 0xE7, 0xCF, 0xCF, 0xF3, 0xF3, 0xFF, 0xFF, 
	0xFF, 0xC1, 0x99, 0x9F, 0x99, 0x81, 0xCF, 0x99, 0x99, 0xE7, 0xF3, 0x87, 0xE7, 0x29, 0x99, 0x99, 
	0x99, 0x99, 0x9F, 0xC3, 0xCF, 0x99, 0x99, 0x29, 0xC7, 0x99, 0xE7, 0xCF, 0xE7, 0xF3, 0xFF, 0x23, 
	0x00, 0x55, 0x24, 0x3C, 0x38, 0x38, 0x10, 0x10, 0x99, 0xDB, 0xE0, 0x28, 0x08, 0x10, 0x10, 0x38, 
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x6C, 0xFC, 0x66, 0xCC, 0x00, 0x18, 0x18, 0x6C, 0x18, 0x18, 0x00, 0x18, 0x60, 
	0x66, 0x18, 0x60, 0x66, 0x0C, 0x66, 0x66, 0x18, 0x66, 0x0C, 0x18, 0x18, 0x18, 0x00, 0x30, 0x00, 
	0x66, 0x66, 0x66, 0x66, 0x6C, 0x60, 0x60, 0x66, 0x66, 0x18, 0x66, 0x66, 0x60, 0xC6, 0xC6, 0x66, 
	0x60, 0x6C, 0x66, 0x66, 0x18, 0x66, 0x3C, 0xEE, 0x66, 0x18, 0x60, 0x30, 0x06, 0x0C, 0x00, 0x00, 
	0x00, 0x66, 0x66, 0x60, 0x66, 0x60, 0x30, 0x3E, 0x66, 0x18, 0x0C, 0x6C, 0x18, 0xD6, 0x66, 0x66, 
	0x7C, 0x3E, 0x60, 0x06, 0x30, 0x66, 0x3C, 0x7C, 0x6C, 0x3E, 0x30, 0x30, 0x18, 0x0C, 0x00, 0xF8, 
	0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 
	0xFF, 0xFF, 0xFF, 0x93, 0x03, 0x99, 0x33, 0xFF, 0xE7, 0xE7, 0x93, 0xE7, 0xE7, 0xFF, 0xE7, 0x9F, 
	0x99, 0xE7, 0x9F, 0x99, 0xF3, 0x99, 0x99, 0xE7, 0x99, 0xF3, 0xE7, 0xE7, 0xE7, 0xFF, 0xCF, 0xFF, 
	0x99, 0x99, 0x99, 0x99, 0x93, 0x9F, 0x9F, 0x99, 0x99, 0xE7, 0x99, 0x99, 0x9F, 0x39, 0x39, 0x99, 
	0x9F, 0x93, 0x99, 0x99, 0xE7, 0x99, 0xC3, 0x11, 0x99, 0xE7, 0x9F, 0xCF, 0xF9, 0xF3, 0xFF, 0xFF, 
	0xFF, 0x99, 0x99, 0x9F, 0x99, 0x9F, 0xCF, 0xC1, 0x99, 0xE7, 0xF3, 0x93, 0xE7, 0x29, 0x99, 0x99, 
	0x83, 0xC1, 0x9F, 0xF9, 0xCF, 0x99, 0xC3, 0x83, 0x93, 0xC1, 0xCF, 0xCF, 0xE7, 0xF3, 0xFF, 0x07, 
	0x00, 0xAA, 0x18, 0x18, 0x10, 0x10, 0x38, 0x38, 0x42, 0x66, 0xC0, 0x44, 0x00, 0x10, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x18, 0x00, 0x6C, 0x30, 0x06, 0x76, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x18, 0x00, 0x18, 0xC0, 
	0x3C, 0x7E, 0x7E, 0x3C, 0x0C, 0x3C, 0x3C, 0x18, 0x3C, 0x38, 0x18, 0x18, 0x0C, 0x00, 0x60, 0x18, 
	0x3C, 0x66, 0x7C, 0x3C, 0x78, 0x7E, 0x60, 0x3C, 0x66, 0x7E, 0x3C, 0x63, 0x7E, 0xC6, 0xC6, 0x3C, 
	0x60, 0x36, 0x66, 0x3C, 0x18, 0x3C, 0x18, 0xC6, 0xC3, 0x18, 0x7E, 0x3C, 0x03, 0x3C, 0x00, 0x00, 
	0x00, 0x3E, 0x7C, 0x3C, 0x3E, 0x3C, 0x30, 0x06, 0x66, 0x3C, 0x6C, 0x66, 0x3C, 0xC6, 0x66, 0x3C, 
	0x60, 0x06, 0x60, 0x7C, 0x1E, 0x3E, 0x18, 0x6C, 0xC6, 0x06, 0x7E, 0x1C, 0x18, 0x38, 0x00, 0x70, 
	0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 
	0xFF, 0xE7, 0xFF, 0x93, 0xCF, 0xF9, 0x89, 0xFF, 0xF3, 0xCF, 0xFF, 0xFF, 0xE7, 0xFF, 0xE7, 0x3F, 
	0xC3, 0x81, 0x81, 0xC3, 0xF3, 0xC3, 0xC3, 0xE7, 0xC3, 0xC7, 0xE7, 0xE7, 0xF3, 0xFF, 0x9F, 0xE7, 
	0xC3, 0x99, 0x83, 0xC3, 0x87, 0x81, 0x9F, 0xC3, 0x99, 0x81, 0xC3, 0x9C, 0x81, 0x39, 0x39, 0xC3, 
	0x9F, 0xC9, 0x99, 0xC3, 0xE7, 0xC3, 0xE7, 0x39, 0x3C, 0xE7, 0x81, 0xC3, 0xFC, 0xC3, 0xFF, 0xFF, 
	0xFF, 0xC1, 0x83, 0xC3, 0xC1, 0xC3, 0xCF, 0xF9, 0x99, 0xC3, 0x93, 0x99, 0xC3, 0x39, 0x99, 0xC3, 
	0x9F, 0xF9, 0x9F, 0x83, 0xE1, 0xC1, 0xE7, 0x93, 0x39, 0xF9, 0x81, 0xE3, 0xE7, 0xC7, 0xFF, 0x8F, 
	0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 0xD7, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0x9F, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};
