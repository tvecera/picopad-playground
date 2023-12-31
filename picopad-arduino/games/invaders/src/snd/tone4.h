#include "picopad.h"

// sound format: PCM mono 8-bit 22050Hz
const u8 Tone4Snd[754] = {
	0x80, 0x7F, 0x7F, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x7F, 0x7F, 0x80, 0x80, 0x81, 0x7F, 
	0x7F, 0x7F, 0x80, 0x7F, 0x81, 0x80, 0x7E, 0x7F, 0x7F, 0x81, 0x80, 0x7D, 0x7D, 0x8A, 0x9D, 0xB0, 
	0xBA, 0xC3, 0xC9, 0xCD, 0xD1, 0xD3, 0xD5, 0xD6, 0xD7, 0xD4, 0xCA, 0xBD, 0xAB, 0x99, 0x8F, 0x84, 
	0x7A, 0x73, 0x6D, 0x6A, 0x64, 0x63, 0x61, 0x5F, 0x5F, 0x5D, 0x5C, 0x5D, 0x5B, 0x5B, 0x5F, 0x5E, 
	0x60, 0x60, 0x62, 0x62, 0x61, 0x64, 0x63, 0x66, 0x67, 0x69, 0x69, 0x69, 0x68, 0x69, 0x6A, 0x69, 
	0x69, 0x69, 0x67, 0x69, 0x76, 0x8C, 0xA4, 0xB5, 0xC1, 0xC6, 0xCB, 0xD0, 0xD2, 0xD4, 0xD3, 0xD7, 
	0xD5, 0xCB, 0xB9, 0xA5, 0x93, 0x85, 0x79, 0x72, 0x69, 0x64, 0x61, 0x60, 0x5D, 0x5A, 0x59, 0x57, 
	0x58, 0x57, 0x56, 0x59, 0x58, 0x5B, 0x5B, 0x5D, 0x5C, 0x5E, 0x5F, 0x60, 0x61, 0x63, 0x64, 0x64, 
	0x68, 0x68, 0x68, 0x67, 0x68, 0x67, 0x69, 0x69, 0x67, 0x65, 0x68, 0x76, 0x8E, 0xA5, 0xB4, 0xBE, 
	0xC6, 0xCB, 0xD0, 0xD2, 0xD4, 0xD3, 0xD6, 0xD3, 0xC9, 0xB4, 0xA2, 0x8F, 0x82, 0x76, 0x6C, 0x68, 
	0x62, 0x5F, 0x5D, 0x5C, 0x5A, 0x59, 0x58, 0x58, 0x58, 0x58, 0x58, 0x5B, 0x5C, 0x5D, 0x5E, 0x5E, 
	0x5F, 0x60, 0x61, 0x63, 0x63, 0x65, 0x68, 0x68, 0x68, 0x68, 0x67, 0x6A, 0x69, 0x68, 0x68, 0x6A, 
	0x68, 0x68, 0x6A, 0x6B, 0x6C, 0x6C, 0x6C, 0x6D, 0x6E, 0x71, 0x6F, 0x71, 0x71, 0x76, 0x7A, 0x84, 
	0x97, 0xA9, 0xB7, 0xC0, 0xC6, 0xCD, 0xD0, 0xD2, 0xD5, 0xD6, 0xD6, 0xD5, 0xD0, 0xC1, 0xB1, 0xA0, 
	0x93, 0x87, 0x7C, 0x76, 0x6F, 0x6A, 0x67, 0x63, 0x62, 0x5F, 0x5F, 0x5F, 0x5B, 0x5C, 0x5B, 0x5C, 
	0x5E, 0x5D, 0x60, 0x60, 0x61, 0x63, 0x62, 0x62, 0x64, 0x64, 0x68, 0x67, 0x69, 0x69, 0x69, 0x69, 
	0x69, 0x69, 0x69, 0x6A, 0x67, 0x68, 0x6F, 0x85, 0x9C, 0xB0, 0xBC, 0xC5, 0xC9, 0xCE, 0xD2, 0xD3, 
	0xD5, 0xD5, 0xD5, 0xD0, 0xC1, 0xAB, 0x99, 0x8A, 0x7E, 0x72, 0x6D, 0x67, 0x61, 0x61, 0x5D, 0x5B, 
	0x59, 0x57, 0x59, 0x57, 0x57, 0x56, 0x59, 0x59, 0x5D, 0x5B, 0x5D, 0x5D, 0x5E, 0x61, 0x61, 0x60, 
	0x64, 0x66, 0x65, 0x69, 0x68, 0x67, 0x68, 0x67, 0x67, 0x6B, 0x67, 0x65, 0x66, 0x71, 0x84, 0x9D, 
	0xB1, 0xBB, 0xC3, 0xCA, 0xCE, 0xD2, 0xD2, 0xD4, 0xD5, 0xD5, 0xCD, 0xBE, 0xA6, 0x96, 0x85, 0x7A, 
	0x71, 0x69, 0x63, 0x60, 0x5E, 0x5C, 0x5B, 0x5A, 0x58, 0x57, 0x59, 0x57, 0x59, 0x58, 0x5C, 0x5D, 
	0x5E, 0x5F, 0x5E, 0x5F, 0x61, 0x61, 0x65, 0x64, 0x67, 0x67, 0x68, 0x68, 0x68, 0x69, 0x6A, 0x68, 
	0x69, 0x68, 0x69, 0x68, 0x69, 0x6B, 0x6C, 0x6A, 0x6E, 0x6D, 0x6E, 0x6E, 0x6F, 0x71, 0x71, 0x71, 
	0x71, 0x72, 0x72, 0x73, 0x76, 0x7C, 0x87, 0x9A, 0xAD, 0xB7, 0xC2, 0xC8, 0xCD, 0xD0, 0xD2, 0xD6, 
	0xD6, 0xD7, 0xD4, 0xCD, 0xBF, 0xAD, 0x9E, 0x91, 0x85, 0x7C, 0x74, 0x6E, 0x6B, 0x65, 0x63, 0x61, 
	0x5F, 0x5F, 0x5D, 0x5E, 0x5B, 0x5B, 0x5D, 0x5C, 0x5F, 0x60, 0x60, 0x61, 0x61, 0x63, 0x62, 0x65, 
	0x65, 0x67, 0x68, 0x69, 0x6A, 0x67, 0x6A, 0x69, 0x69, 0x6A, 0x69, 0x67, 0x68, 0x72, 0x88, 0xA0, 
	0xB2, 0xBF, 0xC6, 0xC9, 0xD0, 0xD2, 0xD3, 0xD4, 0xD6, 0xD5, 0xCD, 0xBE, 0xA8, 0x97, 0x87, 0x7B, 
	0x72, 0x6B, 0x65, 0x62, 0x60, 0x5E, 0x5A, 0x59, 0x58, 0x57, 0x57, 0x58, 0x56, 0x59, 0x5B, 0x5B, 
	0x5C, 0x5D, 0x5D, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x65, 0x68, 0x67, 0x68, 0x66, 0x69, 0x68, 0x68, 
	0x69, 0x68, 0x65, 0x67, 0x73, 0x89, 0xA0, 0xB2, 0xBE, 0xC3, 0xCB, 0xD0, 0xD0, 0xD4, 0xD3, 0xD6, 
	0xD4, 0xCC, 0xB9, 0xA4, 0x92, 0x84, 0x78, 0x6E, 0x69, 0x63, 0x5E, 0x5F, 0x5B, 0x5B, 0x59, 0x58, 
	0x59, 0x57, 0x58, 0x59, 0x58, 0x5D, 0x5D, 0x5E, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x65, 0x67, 
	0x68, 0x67, 0x68, 0x69, 0x69, 0x68, 0x6A, 0x68, 0x68, 0x69, 0x68, 0x6A, 0x6B, 0x6B, 0x6C, 0x6C, 
	0x6E, 0x6E, 0x6F, 0x6F, 0x71, 0x71, 0x71, 0x71, 0x72, 0x73, 0x73, 0x77, 0x7D, 0x8A, 0x9D, 0xAF, 
	0xBA, 0xC3, 0xC9, 0xCD, 0xD0, 0xD4, 0xD5, 0xD6, 0xD6, 0xD4, 0xCB, 0xBD, 0xAA, 0x9B, 0x8F, 0x83, 
	0x7A, 0x74, 0x6E, 0x69, 0x65, 0x63, 0x5F, 0x60, 0x5F, 0x5D, 0x5E, 0x5A, 0x5B, 0x5C, 0x5E, 0x5F, 
	0x60, 0x60, 0x62, 0x62, 0x62, 0x63, 0x64, 0x65, 0x67, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x68, 
	0x6A, 0x69, 0x67, 0x69, 0x75, 0x8C, 0xA4, 0xB6, 0xBF, 0xC6, 0xCB, 0xD0, 0xD2, 0xD4, 0xD4, 0xD5, 
	0xD6, 0xCC, 0xB8, 0xA6, 0x93, 0x86, 0x7A, 0x70, 0x6A, 0x66, 0x60, 0x60, 0x5C, 0x5A, 0x59, 0x58, 
	0x57, 0x58, 0x56, 0x57, 0x59, 0x5B, 0x5C, 0x5B, 0x5D, 0x5F, 0x5D, 0x61, 0x61, 0x62, 0x64, 0x65, 
	0x68, 0x68, 0x67, 0x68, 0x68, 0x66, 0x6A, 0x68, 0x68, 0x66, 0x66, 0x77, 0x8E, 0xA5, 0xB3, 0xBE, 
	0xC6, 0xCB, 0xCF, 0xD3, 0xD2, 0xD4, 0xD6, 0xD4, 0xC9, 0xB5, 0xA1, 0x8F, 0x83, 0x75, 0x6E, 0x68, 
	0x61, 0x5F, 0x5E, 0x5B, 0x5A, 0x59, 0x59, 0x58, 0x57, 0x58, 0x58, 0x5A, 0x5C, 0x5E, 0x5E, 0x5E, 
	0x5F, 0x60, 0x61, 0x63, 0x63, 0x66, 0x66, 0x69, 0x68, 0x68, 0x68, 0x69, 0x68, 0x69, 0x69, 0x67, 
	0x6A, 0x68, 0x6A, 0x6C, 0x6A, 0x6D, 0x6C, 0x6E, 0x6E, 0x6F, 0x6F, 0x71, 0x71, 0x71, 0x72, 0x72, 
	0x70, 0x75, 
};
