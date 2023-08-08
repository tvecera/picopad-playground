#include "picopad.h"

// format: 4-bit paletted pixel graphics
// image width: 80 pixels
// image height: 16 lines
// image pitch: 40 bytes
const u16 GrassImg_Pal[16] __attribute__ ((aligned(4))) = {
	0xA158, 0x3DE7, 0x0DC0, 0x0CC0, 0x0B21, 0x1D43, 0x9E73, 0x7E0E, 0x34C5, 0x2B65, 0x2640, 0x662A, 0x648B, 0x3581, 0x5543, 0x6641, 
};

const u8 GrassImg[640] __attribute__ ((aligned(4))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x05, 0x03, 0x40, 0xB7, 0x05, 0x31, 0x50, 0x00, 0x05, 
	0x50, 0x30, 0x00, 0x78, 0x7C, 0x76, 0x10, 0x0B, 0x30, 0x00, 0x10, 0x03, 0x05, 0x60, 0x67, 0x75, 
	0x00, 0x00, 0x30, 0x5B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x71, 0x15, 0x7B, 0x31, 0x7B, 0x16, 
	0xB1, 0x75, 0x12, 0x8C, 0x38, 0x81, 0x35, 0xB5, 0x98, 0x10, 0x08, 0x71, 0x58, 0x32, 0x67, 0x37, 
	0x7B, 0x36, 0xB3, 0xB6, 0x67, 0x65, 0x51, 0x13, 0x83, 0x15, 0x33, 0x37, 0xB0, 0x16, 0x00, 0x00, 
	0x00, 0x07, 0xB5, 0xB1, 0x35, 0x00, 0x12, 0x51, 0xBB, 0xE3, 0x55, 0x38, 0xB1, 0x53, 0x33, 0x5A, 
	0x31, 0x70, 0x03, 0x37, 0x03, 0x33, 0x8B, 0x31, 0x70, 0x31, 0xB3, 0x00, 0x01, 0x13, 0x51, 0x52, 
	0xB3, 0x51, 0xA2, 0x5D, 0x20, 0x30, 0x00, 0x00, 0x06, 0x60, 0x7B, 0x5D, 0x35, 0x85, 0xBA, 0x33, 
	0x2A, 0x2D, 0x35, 0xB1, 0x11, 0x38, 0x53, 0x15, 0x32, 0x5F, 0xD3, 0x24, 0x22, 0x84, 0x2A, 0xD2, 
	0x23, 0xD2, 0x83, 0xA1, 0x52, 0x35, 0x35, 0xBA, 0xBA, 0x35, 0xA5, 0x52, 0x22, 0x66, 0x08, 0x36, 
	0x00, 0x0B, 0x25, 0x53, 0x22, 0xE5, 0x2A, 0x23, 0xBA, 0x2A, 0x2E, 0xC5, 0x2F, 0xDA, 0x53, 0x23, 
	0x22, 0x2D, 0xED, 0xA2, 0x2D, 0x22, 0x22, 0x8D, 0x22, 0xF2, 0x32, 0x25, 0x12, 0x32, 0x2A, 0x33, 
	0xAD, 0xD3, 0x2A, 0x13, 0xA2, 0x75, 0x70, 0x33, 0x00, 0x28, 0x52, 0x51, 0x2A, 0x32, 0x23, 0xAD, 
	0xDD, 0xA5, 0x8D, 0x22, 0xAD, 0xDA, 0xD8, 0x2D, 0x5A, 0xA8, 0xED, 0xEE, 0xDF, 0xE2, 0xA2, 0x1E, 
	0x8D, 0x2D, 0xAD, 0x2F, 0x18, 0x52, 0x51, 0x33, 0xFF, 0xD3, 0xAD, 0x22, 0x22, 0x2B, 0x00, 0xC6, 
	0x00, 0x8C, 0x75, 0x35, 0x2D, 0xAF, 0xD3, 0x2A, 0x3A, 0xA3, 0xDD, 0x2D, 0x5A, 0x32, 0xD2, 0x2E, 
	0x5E, 0xD2, 0xFD, 0x1E, 0xDE, 0xA2, 0xDF, 0xEE, 0xFA, 0xEF, 0x25, 0xFA, 0x31, 0x52, 0x23, 0x2D, 
	0xE2, 0x3A, 0x2A, 0x82, 0x3A, 0x21, 0x0B, 0x6C, 0x07, 0x6B, 0x32, 0x2A, 0xD5, 0x5A, 0x2E, 0x53, 
	0xDD, 0xE2, 0x25, 0xD3, 0xDD, 0x3A, 0x52, 0xA5, 0x25, 0xFE, 0x53, 0x32, 0xA2, 0xDF, 0x5F, 0xEE, 
	0xF2, 0xAE, 0x88, 0x3D, 0xE3, 0x1E, 0x82, 0xA2, 0x33, 0x2F, 0xF3, 0x32, 0x51, 0x25, 0x48, 0x0C, 
	0x64, 0xB8, 0x84, 0xDF, 0x53, 0x52, 0x2E, 0x52, 0x22, 0xA2, 0xED, 0xDA, 0xA2, 0xAD, 0xDE, 0x3E, 
	0xF2, 0xAE, 0x2A, 0xEA, 0xA3, 0xFF, 0x33, 0xAA, 0xD5, 0x23, 0xD2, 0x22, 0xD1, 0xDE, 0x83, 0xA2, 
	0x38, 0x52, 0xFE, 0xA2, 0x32, 0x11, 0x58, 0x60, 0x0B, 0x48, 0x83, 0xBE, 0xDD, 0xDE, 0xD8, 0x8F, 
	0xF3, 0x2A, 0xBB, 0xDA, 0x22, 0xD3, 0x2D, 0x2D, 0xDD, 0x2A, 0x8A, 0xD8, 0x3E, 0xE3, 0xEA, 0xDD, 
	0x55, 0xAD, 0xDD, 0xD2, 0xAF, 0x3D, 0xE3, 0x22, 0xD8, 0x8D, 0x23, 0x52, 0x23, 0x54, 0x8C, 0x99, 
	0x0C, 0x8C, 0x93, 0x53, 0x3D, 0xBF, 0xEE, 0xD3, 0x33, 0xB5, 0x38, 0xDA, 0x25, 0xD2, 0x3D, 0x22, 
	0xDB, 0xFF, 0xE5, 0x38, 0x3E, 0xD3, 0x38, 0xED, 0xFE, 0xDA, 0xED, 0xFD, 0xAA, 0xA3, 0xDA, 0xD2, 
	0xDF, 0x8D, 0x52, 0x53, 0x34, 0x38, 0x8C, 0x79, 0x00, 0x09, 0x94, 0x97, 0x84, 0xDF, 0xB8, 0xD1, 
	0x32, 0x88, 0x5A, 0x28, 0xBF, 0xAA, 0x35, 0xB1, 0xDE, 0x8F, 0xAA, 0xF9, 0x3A, 0x3E, 0x21, 0x1D, 
	0xEE, 0xDF, 0xF5, 0xDE, 0xE3, 0x31, 0xB9, 0x8F, 0xDD, 0x9D, 0xD2, 0x25, 0x8C, 0x99, 0x00, 0x00, 
	0x06, 0x0C, 0x6C, 0x6C, 0xCC, 0x8C, 0x8B, 0x8C, 0xBA, 0x38, 0x7D, 0x17, 0x8B, 0xE3, 0xA3, 0x9E, 
	0xFD, 0x51, 0xF3, 0x3D, 0x2A, 0x1B, 0x54, 0x49, 0x88, 0xDF, 0x34, 0x7E, 0x31, 0xB8, 0xC9, 0xA7, 
	0x83, 0x38, 0x98, 0x5C, 0xCC, 0x60, 0x9C, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x76, 0x99, 0x94, 0x09, 
	0x84, 0x47, 0x94, 0xBB, 0x84, 0x95, 0x31, 0x09, 0xE3, 0xB8, 0x38, 0x53, 0x85, 0x8B, 0x84, 0xDC, 
	0x9F, 0x84, 0x4D, 0x74, 0x11, 0x6C, 0x43, 0x44, 0x89, 0x4C, 0xC9, 0x49, 0x09, 0x76, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xC4, 0x00, 0x09, 0x45, 0xCC, 0x93, 0x40, 0x00, 0x90, 0x18, 0x99, 0x0C, 
	0xC9, 0xDB, 0x49, 0x98, 0x04, 0x94, 0x00, 0x48, 0x44, 0x80, 0x0E, 0x41, 0x14, 0x97, 0x00, 0x99, 
	0xC0, 0x48, 0x90, 0x94, 0x00, 0x10, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x90, 0x00, 
	0x07, 0x04, 0x90, 0xC9, 0xC0, 0x90, 0xC0, 0x40, 0x6C, 0x00, 0x64, 0x96, 0x08, 0x00, 0x90, 0x00, 
	0x96, 0xC0, 0x90, 0x80, 0x0C, 0x00, 0x00, 0x60, 0x90, 0xC9, 0x00, 0x07, 0x40, 0x00, 0x00, 0x00, 
};