#include "picopad.h"

// sound format: PCM mono 8-bit 22050Hz
const u8 OutSnd[4708] = {
	0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x82, 0x82, 0x82, 0x81, 0x81, 0x7F, 0x7D, 0x7A, 0x7A, 
	0x7A, 0x7A, 0x79, 0x7A, 0x7C, 0x80, 0x83, 0x85, 0x86, 0x87, 0x88, 0x88, 0x87, 0x85, 0x83, 0x81, 
	0x7F, 0x7D, 0x79, 0x77, 0x75, 0x76, 0x77, 0x79, 0x7A, 0x7C, 0x7F, 0x85, 0x89, 0x8A, 0x89, 0x89, 
	0x8A, 0x89, 0x85, 0x81, 0x7F, 0x7E, 0x7D, 0x7B, 0x79, 0x79, 0x7A, 0x7D, 0x7F, 0x80, 0x80, 0x82, 
	0x85, 0x87, 0x87, 0x87, 0x87, 0x86, 0x84, 0x82, 0x80, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7D, 0x7D, 
	0x7C, 0x7C, 0x7B, 0x7B, 0x7A, 0x7A, 0x7A, 0x7C, 0x7E, 0x80, 0x81, 0x84, 0x89, 0x8F, 0x95, 0x98, 
	0x97, 0x94, 0x93, 0x91, 0x8B, 0x7E, 0x70, 0x67, 0x64, 0x63, 0x61, 0x60, 0x64, 0x6C, 0x75, 0x7B, 
	0x80, 0x89, 0x97, 0xA4, 0xAA, 0xA8, 0xA2, 0x9D, 0x98, 0x91, 0x84, 0x72, 0x61, 0x59, 0x59, 0x5A, 
	0x59, 0x5C, 0x68, 0x79, 0x85, 0x89, 0x8E, 0x9B, 0xA8, 0xAC, 0xA7, 0x9F, 0x97, 0x90, 0x8A, 0x82, 
	0x75, 0x64, 0x59, 0x5A, 0x60, 0x62, 0x62, 0x6A, 0x7B, 0x8B, 0x93, 0x97, 0x9C, 0xA2, 0xA4, 0xA0, 
	0x96, 0x8B, 0x83, 0x7F, 0x7A, 0x72, 0x6B, 0x69, 0x6E, 0x74, 0x76, 0x78, 0x7B, 0x7D, 0x7B, 0x7C, 
	0x80, 0x84, 0x86, 0x8C, 0x98, 0xA2, 0xA0, 0x94, 0x8B, 0x86, 0x81, 0x78, 0x6D, 0x66, 0x65, 0x65, 
	0x65, 0x64, 0x6A, 0x7A, 0x8E, 0x9D, 0x9F, 0x9E, 0x9F, 0x9F, 0x95, 0x83, 0x73, 0x6D, 0x6D, 0x6B, 
	0x68, 0x69, 0x72, 0x80, 0x8B, 0x91, 0x98, 0xA4, 0xAE, 0xAC, 0x9A, 0x84, 0x77, 0x72, 0x6D, 0x61, 
	0x56, 0x55, 0x5F, 0x6E, 0x7D, 0x87, 0x91, 0xA0, 0xB1, 0xB9, 0xB4, 0xA9, 0xA1, 0x9A, 0x88, 0x6E, 
	0x5A, 0x54, 0x58, 0x5B, 0x5B, 0x62, 0x76, 0x92, 0xAA, 0xB2, 0xAF, 0xAB, 0xAA, 0xA4, 0x91, 0x7A, 
	0x6D, 0x6B, 0x68, 0x5D, 0x56, 0x5F, 0x73, 0x85, 0x90, 0x97, 0xA1, 0xAA, 0xAD, 0xA5, 0x94, 0x81, 
	0x75, 0x6E, 0x68, 0x5D, 0x55, 0x56, 0x5E, 0x66, 0x6D, 0x78, 0x8A, 0x9D, 0xA7, 0xA5, 0x9D, 0x98, 
	0x94, 0x8B, 0x7C, 0x6D, 0x67, 0x66, 0x64, 0x60, 0x65, 0x76, 0x89, 0x95, 0x99, 0x9B, 0x9E, 0xA0, 
	0x9B, 0x8E, 0x7F, 0x73, 0x6D, 0x69, 0x64, 0x61, 0x65, 0x6F, 0x78, 0x7C, 0x80, 0x89, 0x92, 0x94, 
	0x92, 0x8F, 0x8C, 0x88, 0x85, 0x81, 0x7A, 0x72, 0x70, 0x77, 0x7C, 0x7C, 0x7B, 0x82, 0x88, 0x85, 
	0x80, 0x82, 0x86, 0x7F, 0x74, 0x7B, 0x97, 0xB0, 0xB4, 0xAF, 0xB0, 0xAE, 0x9B, 0x7E, 0x6B, 0x68, 
	0x63, 0x54, 0x4A, 0x56, 0x71, 0x89, 0x96, 0x9F, 0xAB, 0xB5, 0xB3, 0xA0, 0x84, 0x6D, 0x62, 0x5C, 
	0x53, 0x4B, 0x4F, 0x5E, 0x70, 0x7D, 0x89, 0x9D, 0xB2, 0xBC, 0xB3, 0x9F, 0x8C, 0x80, 0x74, 0x62, 
	0x4D, 0x41, 0x49, 0x5F, 0x74, 0x82, 0x8F, 0xA5, 0xBD, 0xC8, 0xC2, 0xB5, 0xAD, 0xA3, 0x8A, 0x64, 
	0x43, 0x38, 0x3E, 0x45, 0x49, 0x53, 0x6E, 0x94, 0xB1, 0xB8, 0xB2, 0xAE, 0xAE, 0xA5, 0x8D, 0x73, 
	0x63, 0x5E, 0x56, 0x4A, 0x49, 0x5C, 0x77, 0x8B, 0x93, 0x98, 0xA0, 0xA6, 0xA6, 0xA1, 0x99, 0x90, 
	0x89, 0x80, 0x74, 0x69, 0x69, 0x72, 0x7B, 0x7C, 0x7C, 0x85, 0x8E, 0x8C, 0x84, 0x83, 0x86, 0x7B, 
	0x60, 0x4D, 0x55, 0x67, 0x74, 0x81, 0x98, 0xAF, 0xB2, 0xA6, 0x9F, 0x9E, 0x8F, 0x72, 0x5D, 0x5E, 
	0x69, 0x6F, 0x75, 0x81, 0x89, 0x84, 0x79, 0x77, 0x7A, 0x79, 0x75, 0x7B, 0x8B, 0x98, 0x9B, 0x9C, 
	0xA1, 0x9F, 0x85, 0x5D, 0x41, 0x43, 0x56, 0x62, 0x69, 0x82, 0xB5, 0xE3, 0xE6, 0xBF, 0x98, 0x85, 
	0x72, 0x4B, 0x25, 0x20, 0x38, 0x4D, 0x5B, 0x7C, 0xBA, 0xEF, 0xF1, 0xC9, 0xA0, 0x88, 0x6F, 0x48, 
	0x27, 0x24, 0x3B, 0x51, 0x61, 0x7D, 0xA9, 0xCD, 0xCC, 0xAF, 0x93, 0x86, 0x77, 0x5D, 0x4A, 0x56, 
	0x76, 0x8E, 0x94, 0x98, 0xA0, 0xA1, 0x8E, 0x76, 0x6A, 0x67, 0x60, 0x59, 0x65, 0x86, 0xA5, 0xAE, 
	0xA6, 0x9F, 0x9C, 0x90, 0x76, 0x5B, 0x51, 0x5A, 0x6B, 0x7A, 0x88, 0x9A, 0xA7, 0xA8, 0x9C, 0x90, 
	0x88, 0x7A, 0x63, 0x55, 0x5E, 0x78, 0x8B, 0x94, 0xA0, 0xB1, 0xB4, 0x9E, 0x7F, 0x6E, 0x6C, 0x67, 
	0x5E, 0x60, 0x72, 0x85, 0x8C, 0x8C, 0x90, 0x94, 0x8E, 0x80, 0x78, 0x7D, 0x86, 0x89, 0x8B, 0x95, 
	0xA1, 0x9E, 0x87, 0x6D, 0x5F, 0x58, 0x4C, 0x42, 0x4E, 0x6C, 0x87, 0x92, 0x9F, 0xB8, 0xCA, 0xB7, 
	0x8A, 0x64, 0x55, 0x4B, 0x39, 0x32, 0x48, 0x6F, 0x8C, 0x9A, 0xAD, 0xC6, 0xCD, 0xB2, 0x82, 0x5D, 
	0x50, 0x4B, 0x41, 0x3B, 0x53, 0x8B, 0xC1, 0xD3, 0xC6, 0xB9, 0xB3, 0xA0, 0x76, 0x51, 0x48, 0x50, 
	0x4F, 0x4E, 0x69, 0x9B, 0xC0, 0xC0, 0xAF, 0xA4, 0x9C, 0x87, 0x67, 0x53, 0x58, 0x6B, 0x7D, 0x8A, 
	0x99, 0xAA, 0xB4, 0xAF, 0xA1, 0x93, 0x87, 0x78, 0x65, 0x5D, 0x68, 0x7C, 0x87, 0x87, 0x8A, 0x92, 
	0x93, 0x84, 0x72, 0x6C, 0x72, 0x78, 0x7A, 0x84, 0x94, 0x9F, 0x9B, 0x91, 0x8B, 0x85, 0x76, 0x62, 
	0x59, 0x62, 0x72, 0x7D, 0x87, 0x98, 0xAA, 0xAA, 0x96, 0x7F, 0x73, 0x6D, 0x65, 0x5D, 0x62, 0x73, 
	0x81, 0x89, 0x93, 0xA0, 0xA3, 0x93, 0x7C, 0x6F, 0x6F, 0x70, 0x6E, 0x72, 0x82, 0x99, 0xA7, 0xA3, 
	0x95, 0x8A, 0x81, 0x72, 0x5D, 0x53, 0x5A, 0x67, 0x6F, 0x7C, 0x98, 0xB5, 0xB8, 0xA0, 0x86, 0x79, 
	0x6B, 0x52, 0x3D, 0x41, 0x56, 0x68, 0x76, 0x90, 0xB5, 0xCC, 0xBF, 0x9B, 0x7C, 0x6C, 0x5B, 0x3E, 
	0x28, 0x38, 0x6A, 0x9B, 0xAE, 0xB4, 0xC2, 0xCF, 0xC0, 0x9A, 0x7D, 0x73, 0x66, 0x4A, 0x37, 0x46, 
	0x6E, 0x8E, 0x9A, 0xA0, 0xAB, 0xB2, 0xA9, 0x92, 0x7A, 0x6D, 0x6C, 0x70, 0x70, 0x71, 0x7A, 0x85, 
	0x89, 0x84, 0x81, 0x83, 0x81, 0x7B, 0x7D, 0x8A, 0x94, 0x93, 0x94, 0x9E, 0xA0, 0x8B, 0x6C, 0x5D, 
	0x5F, 0x5E, 0x58, 0x5F, 0x78, 0x90, 0x9A, 0x9E, 0xA6, 0xAC, 0xA3, 0x89, 0x6D, 0x5D, 0x5C, 0x62, 
	0x65, 0x68, 0x77, 0x8E, 0x9B, 0x95, 0x8A, 0x86, 0x83, 0x77, 0x6C, 0x6E, 0x78, 0x7C, 0x7D, 0x8A, 
	0x9C, 0x9C, 0x8B, 0x7B, 0x75, 0x6E, 0x64, 0x62, 0x6E, 0x7D, 0x86, 0x91, 0x9F, 0xA7, 0xA4, 0x9E, 
	0x95, 0x86, 0x73, 0x66, 0x5B, 0x47, 0x3E, 0x5D, 0x9A, 0xC6, 0xCD, 0xD0, 0xE0, 0xDA, 0x9F, 0x55, 
	0x34, 0x39, 0x32, 0x1E, 0x35, 0x87, 0xD9, 0xF0, 0xD9, 0xC7, 0xBF, 0x9E, 0x5A, 0x21, 0x1C, 0x3F, 
	0x66, 0x81, 0x9F, 0xC3, 0xD4, 0xC3, 0xA5, 0x90, 0x80, 0x5E, 0x39, 0x3B, 0x6B, 0x9C, 0xA8, 0x9D, 
	0x9B, 0x9D, 0x89, 0x63, 0x51, 0x60, 0x77, 0x84, 0x92, 0xA9, 0xB6, 0xAB, 0x95, 0x88, 0x7D, 0x66, 
	0x51, 0x57, 0x76, 0x93, 0x9C, 0x9C, 0xA3, 0xA7, 0x97, 0x76, 0x5E, 0x5D, 0x6A, 0x76, 0x82, 0x90, 
	0x9C, 0x9B, 0x92, 0x8A, 0x85, 0x7A, 0x6A, 0x67, 0x78, 0x8A, 0x8E, 0x8A, 0x8A, 0x8B, 0x82, 0x76, 
	0x77, 0x86, 0x91, 0x97, 0x9F, 0xA7, 0x9E, 0x84, 0x6E, 0x64, 0x58, 0x44, 0x45, 0x6D, 0xA2, 0xB8, 
	0xB1, 0xAD, 0xB3, 0xA3, 0x72, 0x45, 0x3C, 0x45, 0x43, 0x46, 0x72, 0xB8, 0xDB, 0xC3, 0x9C, 0x8B, 
	0x7E, 0x52, 0x24, 0x2A, 0x66, 0xA1, 0xB8, 0xC6, 0xE0, 0xEA, 0xC4, 0x85, 0x60, 0x59, 0x49, 0x2D, 
	0x30, 0x6B, 0xB3, 0xD3, 0xCC, 0xC5, 0xC9, 0xB8, 0x86, 0x51, 0x3F, 0x4E, 0x61, 0x6C, 0x78, 0x8B, 
	0x9A, 0x9B, 0x93, 0x8C, 0x86, 0x7D, 0x77, 0x7F, 0x8F, 0x96, 0x90, 0x87, 0x82, 0x78, 0x68, 0x5E, 
	0x69, 0x7F, 0x8E, 0x97, 0xA3, 0xAF, 0xAA, 0x93, 0x81, 0x7D, 0x77, 0x67, 0x5F, 0x6E, 0x8A, 0x98, 
	0x95, 0x92, 0x94, 0x8D, 0x7D, 0x73, 0x78, 0x82, 0x86, 0x89, 0x90, 0x90, 0x82, 0x6F, 0x68, 0x69, 
	0x66, 0x63, 0x74, 0x9D, 0xBF, 0xC1, 0xAD, 0x9C, 0x90, 0x76, 0x50, 0x3A, 0x42, 0x55, 0x5E, 0x70, 
	0x9B, 0xC9, 0xCD, 0xA7, 0x83, 0x77, 0x6A, 0x4A, 0x37, 0x58, 0x93, 0xB4, 0xB1, 0xAF, 0xB8, 0xAB, 
	0x78, 0x45, 0x39, 0x42, 0x40, 0x40, 0x69, 0xB0, 0xDC, 0xD0, 0xAF, 0x9F, 0x92, 0x6D, 0x3D, 0x2D, 
	0x49, 0x71, 0x8A, 0x9A, 0xAF, 0xC1, 0xBD, 0xA6, 0x91, 0x87, 0x7B, 0x68, 0x5E, 0x67, 0x79, 0x82, 
	0x82, 0x83, 0x86, 0x84, 0x7F, 0x81, 0x8C, 0x95, 0x93, 0x90, 0x91, 0x8D, 0x7C, 0x69, 0x63, 0x65, 
	0x63, 0x62, 0x75, 0x98, 0xAD, 0xA7, 0x96, 0x8F, 0x8A, 0x77, 0x64, 0x66, 0x7B, 0x8C, 0x90, 0x95, 
	0x9E, 0x9D, 0x8C, 0x78, 0x71, 0x72, 0x6F, 0x6D, 0x7C, 0x94, 0xA1, 0x98, 0x87, 0x7D, 0x74, 0x63, 
	0x54, 0x57, 0x68, 0x7B, 0x8A, 0x9F, 0xB6, 0xB5, 0x95, 0x6C, 0x58, 0x55, 0x4A, 0x3E, 0x50, 0x8A, 
	0xC3, 0xD1, 0xBF, 0xB0, 0xA9, 0x90, 0x62, 0x42, 0x45, 0x55, 0x5B, 0x68, 0x91, 0xC0, 0xCC, 0xAE, 
	0x8D, 0x7F, 0x70, 0x51, 0x3C, 0x4F, 0x7E, 0x9E, 0xA3, 0xA6, 0xB0, 0xAE, 0x91, 0x6F, 0x61, 0x61, 
	0x5B, 0x52, 0x60, 0x83, 0x9E, 0xA0, 0x97, 0x96, 0x96, 0x8A, 0x78, 0x71, 0x78, 0x80, 0x81, 0x7F, 
	0x7F, 0x7F, 0x7B, 0x7A, 0x7C, 0x80, 0x82, 0x87, 0x92, 0x98, 0x90, 0x7F, 0x73, 0x6F, 0x69, 0x60, 
	0x64, 0x7F, 0x9E, 0xA9, 0xA1, 0x9A, 0x9A, 0x8C, 0x6C, 0x53, 0x51, 0x51, 0x44, 0x4D, 0x8B, 0xD7, 
	0xE7, 0xB5, 0x85, 0x7D, 0x72, 0x44, 0x24, 0x4F, 0xA3, 0xD1, 0xC7, 0xBB, 0xBC, 0xA4, 0x66, 0x38, 
	0x3C, 0x4F, 0x55, 0x68, 0xA6, 0xE1, 0xDE, 0xA8, 0x78, 0x5F, 0x3D, 0x16, 0x14, 0x41, 0x71, 0x89, 
	0xA4, 0xD1, 0xE6, 0xBD, 0x73, 0x48, 0x49, 0x52, 0x50, 0x5C, 0x81, 0xA5, 0xAD, 0x9F, 0x93, 0x8A, 
	0x7E, 0x74, 0x79, 0x85, 0x8A, 0x88, 0x8A, 0x8C, 0x81, 0x6A, 0x5D, 0x67, 0x7A, 0x86, 0x92, 0xA5, 
	0xAC, 0x95, 0x6F, 0x5B, 0x5F, 0x63, 0x5F, 0x6C, 0x94, 0xB6, 0xB7, 0xA4, 0x99, 0x91, 0x75, 0x53, 
	0x4E, 0x6B, 0x86, 0x8F, 0x9B, 0xB3, 0xBA, 0x9B, 0x6F, 0x5C, 0x60, 0x60, 0x5B, 0x65, 0x7F, 0x91, 
	0x92, 0x8E, 0x8F, 0x8B, 0x81, 0x7F, 0x8B, 0x95, 0x91, 0x8B, 0x8A, 0x82, 0x6C, 0x5D, 0x67, 0x81, 
	0x92, 0x9B, 0xAA, 0xB6, 0xAA, 0x89, 0x70, 0x67, 0x5A, 0x45, 0x47, 0x71, 0xA1, 0xAF, 0xA1, 0x99, 
	0x96, 0x82, 0x5F, 0x50, 0x5F, 0x73, 0x7F, 0x98, 0xC3, 0xD5, 0xAA, 0x67, 0x46, 0x46, 0x3B, 0x26, 
	0x3F, 0x97, 0xEA, 0xF7, 0xD4, 0xBA, 0xAA, 0x7E, 0x3C, 0x19, 0x2A, 0x47, 0x59, 0x75, 0xAD, 0xD5, 
	0xC2, 0x8B, 0x67, 0x5D, 0x4A, 0x30, 0x3C, 0x79, 0xB3, 0xBC, 0xA8, 0x9C, 0x94, 0x7A, 0x5A, 0x54, 
	0x67, 0x79, 0x87, 0xA1, 0xBB, 0xB2, 0x81, 0x56, 0x4E, 0x56, 0x52, 0x57, 0x7F, 0xB4, 0xC3, 0xA6, 
	0x84, 0x71, 0x5C, 0x3D, 0x31, 0x4A, 0x70, 0x8B, 0xA7, 0xCD, 0xDC, 0xB1, 0x65, 0x38, 0x3A, 0x41, 
	0x3A, 0x4B, 0x90, 0xD9, 0xE7, 0xBE, 0x96, 0x83, 0x6C, 0x47, 0x38, 0x4F, 0x70, 0x81, 0x92, 0xB4, 
	0xC9, 0xAC, 0x71, 0x4F, 0x50, 0x54, 0x4F, 0x5B, 0x82, 0xA5, 0xA8, 0x9E, 0x9C, 0x97, 0x7C, 0x5B, 
	0x59, 0x72, 0x87, 0x8C, 0x94, 0xA6, 0xA9, 0x90, 0x73, 0x69, 0x6E, 0x71, 0x70, 0x78, 0x85, 0x8A, 
	0x87, 0x85, 0x85, 0x80, 0x7A, 0x7F, 0x8C, 0x91, 0x8C, 0x87, 0x85, 0x7E, 0x6F, 0x68, 0x74, 0x86, 
	0x92, 0x9E, 0xB0, 0xB7, 0xA2, 0x7E, 0x69, 0x66, 0x5F, 0x4F, 0x53, 0x79, 0xA5, 0xB5, 0xAC, 0xA4, 
	0xA2, 0x93, 0x75, 0x5F, 0x61, 0x6F, 0x79, 0x7F, 0x87, 0x8E, 0x8C, 0x86, 0x83, 0x83, 0x80, 0x81, 
	0x8D, 0x99, 0x95, 0x81, 0x71, 0x6D, 0x67, 0x5B, 0x5E, 0x7F, 0xA7, 0xB5, 0xA9, 0x9C, 0x97, 0x84, 
	0x60, 0x46, 0x4C, 0x61, 0x6D, 0x7C, 0x9C, 0xB7, 0xAB, 0x80, 0x61, 0x5B, 0x4E, 0x36, 0x3F, 0x80, 
	0xC6, 0xD7, 0xC0, 0xB0, 0xAA, 0x89, 0x52, 0x36, 0x43, 0x54, 0x5B, 0x74, 0xAB, 0xD1, 0xBD, 0x8C, 
	0x70, 0x67, 0x55, 0x43, 0x54, 0x80, 0x9C, 0xA0, 0xAA, 0xC0, 0xB7, 0x7A, 0x3B, 0x2E, 0x48, 0x59, 
	0x62, 0x83, 0xB3, 0xC4, 0xA5, 0x7E, 0x6C, 0x61, 0x4C, 0x44, 0x60, 0x8B, 0xA0, 0xA3, 0xAD, 0xBC, 
	0xAB, 0x7C, 0x5A, 0x61, 0x76, 0x7C, 0x80, 0x98, 0xA9, 0x94, 0x66, 0x4E, 0x53, 0x58, 0x53, 0x63, 
	0x92, 0xBA, 0xBD, 0xAF, 0xAC, 0xA4, 0x79, 0x3F, 0x2C, 0x4B, 0x72, 0x85, 0x99, 0xBE, 0xD6, 0xBC, 
	0x82, 0x5D, 0x59, 0x59, 0x4F, 0x55, 0x79, 0xA0, 0xAA, 0xA5, 0xA8, 0xAB, 0x93, 0x6A, 0x58, 0x67, 
	0x7A, 0x7D, 0x80, 0x92, 0x9F, 0x92, 0x79, 0x70, 0x73, 0x72, 0x6E, 0x76, 0x85, 0x8C, 0x89, 0x89, 
	0x8C, 0x87, 0x7D, 0x7E, 0x88, 0x8C, 0x88, 0x87, 0x89, 0x82, 0x72, 0x6B, 0x70, 0x72, 0x71, 0x7B, 
	0x8F, 0x98, 0x8D, 0x7F, 0x7D, 0x7D, 0x78, 0x7B, 0x8B, 0x98, 0x95, 0x89, 0x80, 0x75, 0x66, 0x63, 
	0x73, 0x85, 0x89, 0x89, 0x8E, 0x8D, 0x81, 0x7B, 0x86, 0x94, 0x93, 0x8B, 0x88, 0x82, 0x72, 0x6B, 
	0x7D, 0x94, 0x9A, 0x9B, 0xA3, 0xA0, 0x80, 0x5B, 0x53, 0x5E, 0x5E, 0x61, 0x84, 0xAD, 0xAB, 0x85, 
	0x6D, 0x6F, 0x68, 0x5A, 0x6F, 0xA7, 0xC5, 0xAC, 0x86, 0x72, 0x5C, 0x3A, 0x36, 0x62, 0x90, 0xA2, 
	0xB7, 0xE2, 0xE4, 0x8F, 0x27, 0x0B, 0x2C, 0x3E, 0x41, 0x71, 0xC7, 0xEA, 0xBA, 0x7D, 0x65, 0x56, 
	0x37, 0x2F, 0x5C, 0x97, 0xAD, 0xB0, 0xC0, 0xCA, 0xA7, 0x6E, 0x54, 0x62, 0x75, 0x7B, 0x83, 0x93, 
	0x9A, 0x90, 0x81, 0x7A, 0x78, 0x79, 0x7C, 0x7A, 0x74, 0x74, 0x7C, 0x81, 0x83, 0x8D, 0x9E, 0x9D, 
	0x81, 0x67, 0x61, 0x5F, 0x53, 0x58, 0x7F, 0xAB, 0xB3, 0xA6, 0xA4, 0xA2, 0x7E, 0x4F, 0x4E, 0x79, 
	0x9A, 0xA1, 0xB0, 0xCA, 0xB9, 0x70, 0x33, 0x36, 0x5B, 0x70, 0x83, 0xAB, 0xCC, 0xBE, 0x97, 0x7F, 
	0x6B, 0x40, 0x21, 0x47, 0x9C, 0xCE, 0xC6, 0xB5, 0xB4, 0x9D, 0x67, 0x44, 0x59, 0x82, 0x95, 0x9E, 
	0xB1, 0xBA, 0x9F, 0x78, 0x68, 0x69, 0x62, 0x5C, 0x6D, 0x87, 0x8D, 0x81, 0x7C, 0x80, 0x7E, 0x80, 
	0x94, 0xAA, 0xA4, 0x87, 0x73, 0x6B, 0x5E, 0x51, 0x5B, 0x7B, 0x90, 0x93, 0x9B, 0xAC, 0xA8, 0x86, 
	0x65, 0x60, 0x6B, 0x75, 0x7D, 0x89, 0x8C, 0x80, 0x76, 0x7C, 0x85, 0x8A, 0x90, 0x98, 0x96, 0x86, 
	0x77, 0x6F, 0x65, 0x59, 0x64, 0x89, 0xA6, 0xA2, 0x8E, 0x83, 0x78, 0x64, 0x59, 0x69, 0x84, 0x95, 
	0xA8, 0xC1, 0xBF, 0x89, 0x4C, 0x3F, 0x58, 0x65, 0x69, 0x8B, 0xBC, 0xC0, 0x8D, 0x61, 0x58, 0x4F, 
	0x36, 0x3C, 0x78, 0xB3, 0xBB, 0xA9, 0xA5, 0x9F, 0x74, 0x45, 0x4B, 0x7B, 0x9B, 0xA4, 0xB6, 0xCE, 
	0xBA, 0x78, 0x45, 0x46, 0x5F, 0x6B, 0x76, 0x90, 0xA9, 0xA7, 0x94, 0x87, 0x7C, 0x67, 0x57, 0x60, 
	0x7B, 0x8F, 0x94, 0x95, 0x9A, 0x9C, 0x95, 0x84, 0x71, 0x65, 0x63, 0x62, 0x5D, 0x60, 0x7B, 0xA0, 
	0xAF, 0xAB, 0xAE, 0xB6, 0x9E, 0x63, 0x3C, 0x4E, 0x72, 0x7E, 0x87, 0xAF, 0xD6, 0xBF, 0x7A, 0x4E, 
	0x50, 0x55, 0x4C, 0x5C, 0x90, 0xB6, 0xB0, 0x9D, 0x96, 0x84, 0x58, 0x40, 0x62, 0x97, 0xAB, 0xAA, 
	0xB6, 0xBD, 0x98, 0x5F, 0x4C, 0x5B, 0x5D, 0x57, 0x78, 0xB5, 0xC8, 0x9E, 0x75, 0x72, 0x6B, 0x48, 
	0x3E, 0x6F, 0xA7, 0xAA, 0x95, 0x9C, 0xAB, 0x8F, 0x5B, 0x4B, 0x5F, 0x68, 0x67, 0x86, 0xB6, 0xB9, 
	0x85, 0x5B, 0x5E, 0x6E, 0x73, 0x82, 0xA1, 0xA6, 0x7C, 0x53, 0x52, 0x63, 0x68, 0x74, 0xA0, 0xC7, 
	0xBA, 0x89, 0x5F, 0x4D, 0x4C, 0x6B, 0xAA, 0xD8, 0xCB, 0x9B, 0x78, 0x5F, 0x41, 0x3D, 0x75, 0xBD, 
	0xCA, 0x9C, 0x7C, 0x7C, 0x71, 0x53, 0x55, 0x8B, 0xBF, 0xC3, 0xAB, 0x8F, 0x68, 0x40, 0x3F, 0x6B, 
	0x92, 0x97, 0x98, 0xA4, 0x97, 0x69, 0x53, 0x6F, 0x8A, 0x76, 0x61, 0x78, 0x94, 0x89, 0x7B, 0x9C, 
	0xBC, 0x98, 0x54, 0x44, 0x5E, 0x5B, 0x47, 0x73, 0xCE, 0xEE, 0xAE, 0x68, 0x5A, 0x58, 0x41, 0x48, 
	0x87, 0xBE, 0xB9, 0x9E, 0x96, 0x7E, 0x40, 0x22, 0x5F, 0xB8, 0xD0, 0xB3, 0xA9, 0xAE, 0x8D, 0x55, 
	0x49, 0x72, 0x93, 0x91, 0x8C, 0x8A, 0x70, 0x4B, 0x4E, 0x7E, 0xA7, 0xB0, 0xAB, 0x99, 0x6C, 0x3A, 
	0x3A, 0x6C, 0x95, 0x9F, 0xAB, 0xC3, 0xB9, 0x7D, 0x43, 0x37, 0x4A, 0x66, 0x93, 0xC3, 0xCA, 0xA2, 
	0x81, 0x81, 0x7A, 0x5A, 0x51, 0x78, 0x97, 0x89, 0x7C, 0x9B, 0xBA, 0xA5, 0x81, 0x84, 0x8C, 0x63, 
	0x35, 0x52, 0xA1, 0xC6, 0xB6, 0xB5, 0xC5, 0xA5, 0x55, 0x31, 0x5B, 0x8F, 0x9B, 0xA2, 0xBA, 0xB5, 
	0x7A, 0x44, 0x47, 0x61, 0x6B, 0x7F, 0xAD, 0xC4, 0x98, 0x5C, 0x51, 0x66, 0x6D, 0x71, 0x93, 0xB0, 
	0x95, 0x5F, 0x4E, 0x61, 0x67, 0x63, 0x81, 0xB2, 0xB8, 0x8C, 0x69, 0x66, 0x6A, 0x6E, 0x90, 0xBF, 
	0xC3, 0x94, 0x6F, 0x6A, 0x5F, 0x40, 0x40, 0x71, 0xA1, 0xA4, 0x97, 0x97, 0x8F, 0x6F, 0x61, 0x7B, 
	0x93, 0x86, 0x75, 0x81, 0x8D, 0x7B, 0x6C, 0x85, 0xA1, 0x90, 0x70, 0x74, 0x88, 0x7F, 0x6F, 0x8B, 
	0xB5, 0xA7, 0x6C, 0x50, 0x5E, 0x65, 0x5F, 0x7B, 0xAF, 0xB5, 0x82, 0x59, 0x5B, 0x5B, 0x49, 0x5E, 
	0xAA, 0xE5, 0xD9, 0xAD, 0x93, 0x75, 0x46, 0x38, 0x71, 0xB5, 0xC0, 0xA9, 0xA5, 0x9E, 0x6B, 0x39, 
	0x4D, 0x8E, 0xAC, 0x9C, 0x98, 0xA9, 0x9C, 0x71, 0x62, 0x80, 0x97, 0x8E, 0x82, 0x81, 0x6F, 0x4F, 
	0x4E, 0x77, 0x9A, 0xA0, 0x9E, 0xA0, 0x88, 0x5D, 0x50, 0x70, 0x8B, 0x85, 0x83, 0x9B, 0xA4, 0x81, 
	0x5F, 0x66, 0x7B, 0x79, 0x76, 0x8B, 0x9A, 0x85, 0x70, 0x80, 0x96, 0x89, 0x72, 0x7A, 0x84, 0x6A, 
	0x50, 0x6E, 0xA8, 0xB6, 0x9D, 0x96, 0x9C, 0x77, 0x3B, 0x40, 0x8C, 0xC6, 0xC6, 0xC2, 0xD5, 0xC1, 
	0x6C, 0x22, 0x24, 0x4A, 0x5E, 0x72, 0xA5, 0xC7, 0xA4, 0x67, 0x55, 0x65, 0x66, 0x64, 0x85, 0xB0, 
	0xA8, 0x79, 0x64, 0x76, 0x7F, 0x73, 0x7B, 0x99, 0xA1, 0x83, 0x69, 0x6C, 0x76, 0x7C, 0x8F, 0xAC, 
	0xAD, 0x8B, 0x6E, 0x6A, 0x6B, 0x69, 0x7C, 0xA2, 0xAE, 0x93, 0x7E, 0x85, 0x86, 0x6B, 0x5D, 0x79, 
	0x94, 0x87, 0x71, 0x7C, 0x92, 0x8C, 0x7E, 0x8E, 0xA4, 0x91, 0x6A, 0x65, 0x7E, 0x87, 0x81, 0x90, 
	0xA9, 0x9A, 0x6D, 0x5A, 0x6A, 0x73, 0x71, 0x8D, 0xC1, 0xC7, 0x89, 0x4E, 0x45, 0x4B, 0x40, 0x4A, 
	0x86, 0xBA, 0xAC, 0x7D, 0x68, 0x65, 0x54, 0x4E, 0x79, 0xB4, 0xBF, 0xA5, 0x99, 0x95, 0x74, 0x4E, 
	0x5B, 0x91, 0xA8, 0x94, 0x8C, 0x98, 0x87, 0x57, 0x4B, 0x7A, 0xA2, 0x9E, 0x93, 0x9A, 0x8E, 0x61, 
	0x51, 0x7F, 0xAB, 0x9E, 0x7A, 0x71, 0x6B, 0x4C, 0x4D, 0x9A, 0xEF, 0xEA, 0xA3, 0x7B, 0x7A, 0x62, 
	0x3A, 0x4A, 0x90, 0xB2, 0x90, 0x6B, 0x6A, 0x66, 0x51, 0x61, 0xA4, 0xCA, 0x9F, 0x5F, 0x54, 0x68, 
	0x6C, 0x71, 0x9A, 0xC5, 0xB9, 0x84, 0x59, 0x44, 0x3B, 0x52, 0x98, 0xDB, 0xDB, 0xA8, 0x83, 0x76, 
	0x60, 0x4E, 0x6A, 0xA3, 0xB6, 0x97, 0x81, 0x8D, 0x93, 0x7C, 0x6A, 0x75, 0x7C, 0x6E, 0x6A, 0x87, 
	0xA3, 0x9D, 0x86, 0x7F, 0x7A, 0x62, 0x4F, 0x68, 0xA0, 0xC3, 0xB9, 0x9C, 0x83, 0x74, 0x6A, 0x65, 
	0x6C, 0x7F, 0x93, 0x98, 0x89, 0x78, 0x79, 0x86, 0x8C, 0x8C, 0x92, 0x93, 0x7A, 0x59, 0x59, 0x7C, 
	0x99, 0x9F, 0xA0, 0x9F, 0x7D, 0x47, 0x3C, 0x6B, 0x95, 0x8F, 0x82, 0x90, 0x93, 0x6E, 0x5D, 0x8F, 
	0xC6, 0xB0, 0x71, 0x5F, 0x6C, 0x51, 0x23, 0x42, 0xA5, 0xD6, 0xA9, 0x72, 0x69, 0x5E, 0x3C, 0x49, 
	0x9E, 0xDC, 0xB9, 0x70, 0x51, 0x42, 0x1C, 0x15, 0x68, 0xCF, 0xE0, 0xAB, 0x8B, 0x87, 0x68, 0x47, 
	0x6D, 0xBE, 0xD2, 0x9C, 0x73, 0x7A, 0x71, 0x50, 0x5E, 0xA5, 0xC1, 0x87, 0x52, 0x69, 0x8E, 0x7D, 
	0x6A, 0x98, 0xD0, 0xB5, 0x67, 0x49, 0x65, 0x78, 0x79, 0x96, 0xC1, 0xB5, 0x76, 0x52, 0x65, 0x81, 
	0x8A, 0x9F, 0xC1, 0xBC, 0x83, 0x52, 0x53, 0x68, 0x71, 0x7F, 0x9E, 0xA7, 0x81, 0x56, 0x54, 0x6B, 
	0x78, 0x81, 0x98, 0xA9, 0x93, 0x6D, 0x64, 0x79, 0x87, 0x84, 0x83, 0x8B, 0x8B, 0x7E, 0x72, 0x71, 
	0x76, 0x7C, 0x84, 0x89, 0x8B, 0x90, 0x9A, 0x97, 0x85, 0x74, 0x70, 0x67, 0x56, 0x5B, 0x85, 0xB4, 
	0xBC, 0xA3, 0x88, 0x70, 0x51, 0x3F, 0x59, 0x8D, 0xAB, 0xA5, 0x92, 0x81, 0x6C, 0x5E, 0x6C, 0x8A, 
	0x95, 0x8C, 0x89, 0x8E, 0x84, 0x73, 0x7D, 0x9B, 0xA0, 0x82, 0x69, 0x69, 0x6D, 0x71, 0x94, 0xC8, 
	0xCE, 0x95, 0x62, 0x64, 0x72, 0x62, 0x5C, 0x8C, 0xC2, 0xB6, 0x7E, 0x61, 0x65, 0x64, 0x69, 0x9A, 
	0xD5, 0xCF, 0x8C, 0x5E, 0x65, 0x74, 0x7B, 0x9C, 0xCA, 0xC2, 0x79, 0x3F, 0x43, 0x53, 0x4E, 0x66, 
	0xB3, 0xE0, 0xAB, 0x54, 0x3E, 0x5C, 0x65, 0x64, 0x8E, 0xC4, 0xB2, 0x68, 0x47, 0x65, 0x77, 0x63, 
	0x67, 0x99, 0xB1, 0x86, 0x5D, 0x73, 0x9B, 0x97, 0x82, 0x89, 0x8F, 0x68, 0x3A, 0x47, 0x81, 0x9F, 
	0x98, 0x9B, 0xAB, 0x9A, 0x6B, 0x5B, 0x7C, 0x9B, 0x99, 0x94, 0x9C, 0x8F, 0x62, 0x47, 0x64, 0x93, 
	0xA2, 0x96, 0x95, 0x9A, 0x89, 0x6C, 0x66, 0x79, 0x86, 0x85, 0x84, 0x8A, 0x87, 0x7A, 0x74, 0x7E, 
	0x87, 0x83, 0x7B, 0x7C, 0x84, 0x89, 0x88, 0x83, 0x7F, 0x7D, 0x79, 0x76, 0x79, 0x88, 0x9A, 0x9C, 
	0x8B, 0x79, 0x71, 0x71, 0x79, 0x8C, 0xA4, 0xA8, 0x8F, 0x6C, 0x58, 0x56, 0x64, 0x86, 0xAE, 0xB7, 
	0x99, 0x78, 0x6F, 0x6D, 0x61, 0x63, 0x89, 0xAE, 0xA3, 0x7A, 0x66, 0x6C, 0x68, 0x5F, 0x75, 0x9F, 
	0xA0, 0x76, 0x63, 0x80, 0x97, 0x89, 0x81, 0x9B, 0xA1, 0x6E, 0x39, 0x42, 0x74, 0x91, 0x9B, 0xAB, 
	0xA9, 0x74, 0x39, 0x3F, 0x75, 0x92, 0x93, 0xAE, 0xDB, 0xCB, 0x76, 0x38, 0x49, 0x76, 0x88, 0x91, 
	0xA9, 0xAD, 0x84, 0x5F, 0x6F, 0x97, 0xA4, 0xA1, 0xAB, 0xAA, 0x7C, 0x44, 0x40, 0x67, 0x84, 0x8A, 
	0x96, 0xA1, 0x87, 0x5B, 0x54, 0x76, 0x92, 0x92, 0x95, 0x9F, 0x8D, 0x62, 0x53, 0x72, 0x8E, 0x83, 
	0x75, 0x85, 0x94, 0x81, 0x6C, 0x7E, 0x9E, 0x9C, 0x7C, 0x6D, 0x73, 0x6F, 0x64, 0x72, 0x98, 0xA7, 
	0x8D, 0x70, 0x6B, 0x6B, 0x63, 0x66, 0x85, 0xA6, 0xA8, 0x95, 0x89, 0x86, 0x7C, 0x6E, 0x70, 0x81, 
	0x8B, 0x86, 0x82, 0x8B, 0x94, 0x8C, 0x7A, 0x6F, 0x72, 0x75, 0x76, 0x7C, 0x8A, 0x96, 0x93, 0x83, 
	0x75, 0x70, 0x72, 0x7E, 0x94, 0xA8, 0xA3, 0x87, 0x6C, 0x66, 0x6E, 0x7B, 0x8E, 0xA2, 0x9F, 0x7E, 
	0x5C, 0x5A, 0x6E, 0x79, 0x7E, 0x98, 0xBB, 0xB9, 0x8B, 0x62, 0x64, 0x7B, 0x85, 0x8B, 0x9A, 0x9D, 
	0x7E, 0x5B, 0x5A, 0x73, 0x83, 0x8B, 0x9E, 0xAC, 0x93, 0x65, 0x58, 0x75, 0x8B, 0x84, 0x7E, 0x87, 
	0x7F, 0x60, 0x5A, 0x87, 0xB3, 0xAE, 0x92, 0x8D, 0x8F, 0x6E, 0x46, 0x51, 0x85, 0xA5, 0x9B, 0x8B, 
	0x82, 0x65, 0x3D, 0x3F, 0x79, 0xB0, 0xB5, 0x9D, 0x8A, 0x74, 0x56, 0x4E, 0x6F, 0x96, 0x9F, 0x98, 
	0x9B, 0x98, 0x77, 0x57, 0x63, 0x8B, 0x9A, 0x89, 0x80, 0x88, 0x85, 0x77, 0x7C, 0x95, 0x9C, 0x83, 
	0x6D, 0x71, 0x78, 0x6F, 0x6D, 0x85, 0x9F, 0x9C, 0x87, 0x7D, 0x7D, 0x79, 0x76, 0x81, 0x8E, 0x8A, 
	0x7C, 0x7A, 0x83, 0x86, 0x83, 0x85, 0x8B, 0x85, 0x76, 0x6F, 0x77, 0x7E, 0x82, 0x8D, 0x9D, 0x9B, 
	0x7E, 0x61, 0x5C, 0x63, 0x62, 0x65, 0x84, 0xB1, 0xB8, 0x88, 0x58, 0x60, 0x8E, 0xA2, 0x88, 0x6C, 
	0x6A, 0x68, 0x5A, 0x64, 0x9B, 0xC0, 0x94, 0x40, 0x30, 0x72, 0xAC, 0xA6, 0x95, 0xA9, 0xA8, 0x5A, 
	0x00, 0x0B, 0x72, 0xBF, 0xB5, 0x8C, 0x7E, 0x7A, 0x68, 0x67, 0x8A, 0xA4, 0x86, 0x54, 0x4C, 0x70, 
	0x8E, 0x8E, 0x88, 0x8D, 0x90, 0x88, 0x81, 0x83, 0x85, 0x7F, 0x71, 0x67, 0x71, 0x97, 0xC5, 0xC9, 
	0x98, 0x63, 0x5B, 0x74, 0x83, 0x89, 0x99, 0xA0, 0x78, 0x40, 0x41, 0x85, 0xC5, 0xCA, 0xAC, 0x8E, 
	0x66, 0x36, 0x35, 0x80, 0xCF, 0xCB, 0x86, 0x58, 0x60, 0x74, 0x83, 0xA8, 0xDB, 0xDB, 0x90, 0x40, 
	0x36, 0x62, 0x82, 0x84, 0x84, 0x8D, 0x8B, 0x7A, 0x73, 0x82, 0x91, 0x8A, 0x70, 0x5B, 0x61, 0x82, 
	0xA4, 0xAA, 0x92, 0x78, 0x6F, 0x71, 0x77, 0x87, 0x9E, 0x9E, 0x78, 0x59, 0x6E, 0xA1, 0xB0, 0x8F, 
	0x75, 0x7E, 0x86, 0x73, 0x68, 0x8D, 0xB8, 0xA8, 0x68, 0x4A, 0x6E, 0x9E, 0xA7, 0x9D, 0x9F, 0x9C, 
	0x79, 0x5A, 0x72, 0xAB, 0xB8, 0x83, 0x52, 0x5C, 0x7E, 0x84, 0x7F, 0x9E, 0xC7, 0xB8, 0x72, 0x49, 
	0x6C, 0xA3, 0xAB, 0x90, 0x81, 0x7E, 0x6E, 0x66, 0x8B, 0xC4, 0xC7, 0x89, 0x4F, 0x4E, 0x6E, 0x7E, 
	0x7F, 0x8F, 0xA5, 0xA1, 0x7F, 0x65, 0x6A, 0x7E, 0x87, 0x80, 0x79, 0x82, 0x96, 0x9B, 0x85, 0x68, 
	0x63, 0x73, 0x7E, 0x80, 0x93, 0xB4, 0xB2, 0x77, 0x3A, 0x3A, 0x6A, 0x8E, 0x97, 0x9D, 0x9C, 0x7B, 
	0x50, 0x59, 0x97, 0xBB, 0x95, 0x58, 0x48, 0x56, 0x54, 0x55, 0x85, 0xCA, 0xD2, 0x90, 0x54, 0x58, 
	0x7D, 0x8F, 0x8F, 0x94, 0x91, 0x6F, 0x48, 0x4B, 0x7A, 0xA4, 0xA7, 0x93, 0x86, 0x83, 0x7F, 0x7B, 
	0x7D, 0x85, 0x89, 0x83, 0x7C, 0x82, 0x93, 0x99, 0x81, 0x5E, 0x59, 0x7C, 0x9D, 0x99, 0x84, 0x81, 
	0x85, 0x6F, 0x50, 0x5E, 0x9C, 0xC3, 0xA3, 0x69, 0x59, 0x6D, 0x77, 0x71, 0x7F, 0x96, 0x8B, 0x61, 
	0x57, 0x88, 0xB9, 0xAF, 0x82, 0x6D, 0x73, 0x6C, 0x5C, 0x6B, 0x9B, 0xAE, 0x87, 0x56, 0x53, 0x77, 
	0x93, 0x98, 0x98, 0x91, 0x73, 0x4D, 0x4C, 0x78, 0xA3, 0xA3, 0x84, 0x71, 0x75, 0x7C, 0x7D, 0x86, 
	0x96, 0x93, 0x75, 0x57, 0x5A, 0x7A, 0x97, 0x9D, 0x90, 0x83, 0x7D, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 
	0x7E, 0x77, 0x79, 0x92, 0xB1, 0xAE, 0x84, 0x60, 0x69, 0x89, 0x95, 0x8A, 0x88, 0x8C, 0x77, 0x51, 
	0x52, 0x90, 0xD0, 0xD0, 0x9C, 0x6D, 0x58, 0x4E, 0x57, 0x86, 0xBD, 0xBE, 0x88, 0x5B, 0x62, 0x82, 
	0x91, 0x98, 0xAB, 0xB0, 0x8B, 0x58, 0x4F, 0x75, 0x96, 0x91, 0x7F, 0x7C, 0x83, 0x82, 0x80, 0x8C, 
	0x9D, 0x97, 0x7A, 0x64, 0x6C, 0x85, 0x8F, 0x84, 0x7A, 0x84, 0x94, 0x94, 0x89, 0x84, 0x84, 0x74, 
	0x56, 0x56, 0x86, 0xBB, 0xBE, 0x94, 0x72, 0x6E, 0x73, 0x74, 0x82, 0xA0, 0xA3, 0x76, 0x45, 0x4C, 
	0x80, 0xA6, 0xA5, 0x9E, 0xA0, 0x95, 0x72, 0x5C, 0x73, 0x9E, 0xA5, 0x84, 0x67, 0x6A, 0x7E, 0x89, 
	0x8F, 0x96, 0x94, 0x7A, 0x5C, 0x5E, 0x7F, 0x9B, 0x98, 0x82, 0x71, 0x6A, 0x6B, 0x79, 0x97, 0xB1, 
	0xAD, 0x8C, 0x6D, 0x67, 0x74, 0x80, 0x82, 0x81, 0x81, 0x82, 0x82, 0x83, 0x88, 0x8D, 0x8A, 0x78, 
	0x62, 0x62, 0x7D, 0x98, 0x94, 0x7B, 0x6F, 0x79, 0x7F, 0x78, 0x7C, 0x93, 0x9A, 0x78, 0x51, 0x5C, 
	0x8B, 0xA3, 0x93, 0x81, 0x7E, 0x74, 0x5F, 0x67, 0x96, 0xB1, 0x8C, 0x52, 0x47, 0x67, 0x7C, 0x7D, 
	0x8F, 0xB5, 0xB9, 0x86, 0x54, 0x58, 0x7E, 0x94, 0x92, 0x8D, 0x8A, 0x79, 0x63, 0x65, 0x81, 0x96, 
	0x8F, 0x7C, 0x76, 0x7E, 0x84, 0x81, 0x7C, 0x7D, 0x80, 0x82, 0x82, 0x87, 0x8F, 0x8D, 0x79, 0x61, 
	0x61, 0x7D, 0x98, 0x98, 0x86, 0x79, 0x75, 0x70, 0x73, 0x8A, 0xA7, 0xA5, 0x7E, 0x59, 0x59, 0x74, 
	0x87, 0x8E, 0x92, 0x8F, 0x78, 0x5C, 0x5E, 0x87, 0xB0, 0xB2, 0x90, 0x6D, 0x60, 0x62, 0x6D, 0x80, 
	0x97, 0x9F, 0x8D, 0x74, 0x6E, 0x81, 0x92, 0x8E, 0x7F, 0x77, 0x75, 0x75, 0x78, 0x89, 0x9D, 0x9E, 
	0x86, 0x6E, 0x6D, 0x7D, 0x89, 0x8B, 0x8A, 0x86, 0x79, 0x6A, 0x6C, 0x83, 0x9B, 0x9D, 0x89, 0x78, 
	0x7B, 0x8A, 0x8F, 0x86, 0x7F, 0x82, 0x80, 0x75, 0x72, 0x8A, 0xA6, 0xA1, 0x7E, 0x6A, 0x7A, 0x8F, 
	0x90, 0x8B, 0x8F, 0x87, 0x67, 0x56, 0x7C, 0xB8, 0xC4, 0x99, 0x74, 0x79, 0x7F, 0x6B, 0x61, 0x81, 
	0xA5, 0x97, 0x6C, 0x61, 0x81, 0x9C, 0x9A, 0x96, 0x9D, 0x91, 0x6C, 0x58, 0x73, 0x9E, 0xA5, 0x8C, 
	0x79, 0x7B, 0x7D, 0x78, 0x77, 0x83, 0x8F, 0x8E, 0x84, 0x7D, 0x7F, 0x86, 0x88, 0x7D, 0x6F, 0x74, 
	0x89, 0x96, 0x8B, 0x77, 0x70, 0x6E, 0x66, 0x66, 0x85, 0xAD, 0xB1, 0x8B, 0x69, 0x69, 0x7A, 0x82, 
	0x89, 0x99, 0x99, 0x77, 0x50, 0x55, 0x83, 0xA9, 0xA9, 0x97, 0x8E, 0x86, 0x75, 0x6D, 0x80, 0x9C, 
	0x9D, 0x80, 0x65, 0x64, 0x77, 0x89, 0x93, 0x97, 0x92, 0x81, 0x6E, 0x6A, 0x7B, 0x8E, 0x90, 0x83, 
	0x78, 0x79, 0x80, 0x83, 0x84, 0x88, 0x88, 0x7E, 0x71, 0x74, 0x85, 0x8F, 0x84, 0x72, 0x70, 0x7F, 
	0x8B, 0x8C, 0x8D, 0x92, 0x8F, 0x77, 0x5C, 0x5B, 0x76, 0x8E, 0x8F, 0x82, 0x7E, 0x83, 0x86, 0x85, 
	0x87, 0x85, 0x70, 0x55, 0x56, 0x7D, 0xA3, 0xA5, 0x8E, 0x82, 0x82, 0x78, 0x66, 0x6D, 0x8F, 0x9F, 
	0x83, 0x5E, 0x5B, 0x74, 0x86, 0x8A, 0x91, 0x97, 0x86, 0x67, 0x61, 0x7F, 0x9B, 0x96, 0x81, 0x7A, 
	0x7D, 0x77, 0x6C, 0x74, 0x8C, 0x99, 0x8C, 0x79, 0x75, 0x7F, 0x88, 0x86, 0x7F, 0x7B, 0x7E, 0x85, 
	0x88, 0x88, 0x8A, 0x8C, 0x83, 0x72, 0x6D, 0x81, 0x96, 0x91, 0x7A, 0x71, 0x7F, 0x8B, 0x8D, 0x95, 
	0xA6, 0xA0, 0x74, 0x48, 0x49, 0x6E, 0x8E, 0x94, 0x92, 0x8E, 0x7D, 0x63, 0x61, 0x82, 0xA4, 0xA3, 
	0x87, 0x73, 0x72, 0x78, 0x7B, 0x83, 0x8E, 0x90, 0x82, 0x73, 0x72, 0x81, 0x8F, 0x90, 0x87, 0x7E, 
	0x79, 0x78, 0x7A, 0x81, 0x8B, 0x8C, 0x81, 0x76, 0x7A, 0x89, 0x8D, 0x80, 0x74, 0x79, 0x82, 0x82, 
	0x7F, 0x89, 0x96, 0x8F, 0x78, 0x6D, 0x7C, 0x8F, 0x90, 0x85, 0x7F, 0x7C, 0x74, 0x74, 0x87, 0xA1, 
	0xA2, 0x86, 0x6B, 0x6B, 0x7D, 0x87, 0x86, 0x87, 0x8C, 0x88, 0x79, 0x73, 0x84, 0x9B, 0x9B, 0x85, 
	0x71, 0x70, 0x79, 0x7F, 0x85, 0x8F, 0x90, 0x7E, 0x69, 0x6C, 0x86, 0x9A, 0x97, 0x8C, 0x87, 0x80, 
	0x70, 0x68, 0x77, 0x8F, 0x95, 0x86, 0x7A, 0x7C, 0x81, 0x80, 0x7D, 0x80, 0x82, 0x80, 0x7C, 0x7F, 
	0x86, 0x8A, 0x88, 0x80, 0x76, 0x76, 0x80, 0x8B, 0x88, 0x7D, 0x77, 0x7A, 0x78, 0x76, 0x80, 0x94, 
	0x98, 0x81, 0x6A, 0x6E, 0x83, 0x8C, 0x87, 0x85, 0x84, 0x73, 0x5C, 0x61, 0x85, 0xA1, 0x99, 0x80, 
	0x76, 0x7C, 0x7C, 0x79, 0x81, 0x91, 0x93, 0x7F, 0x6B, 0x6B, 0x7C, 0x8B, 0x90, 0x8F, 0x8A, 0x82, 
	0x79, 0x76, 0x7A, 0x81, 0x83, 0x80, 0x7F, 0x84, 0x8B, 0x8A, 0x82, 0x7C, 0x7B, 0x7A, 0x76, 0x79, 
	0x86, 0x8E, 0x85, 0x75, 0x71, 0x7D, 0x87, 0x86, 0x84, 0x84, 0x7F, 0x75, 0x72, 0x81, 0x91, 0x8E, 
	0x7E, 0x74, 0x76, 0x7C, 0x7F, 0x84, 0x8C, 0x8B, 0x7A, 0x68, 0x68, 0x7B, 0x8C, 0x8D, 0x84, 0x7E, 
	0x7E, 0x7D, 0x79, 0x7D, 0x88, 0x8D, 0x81, 0x6F, 0x6E, 0x7D, 0x8A, 0x8A, 0x86, 0x85, 0x81, 0x78, 
	0x75, 0x80, 0x8C, 0x89, 0x7C, 0x76, 0x79, 0x7C, 0x7C, 0x82, 0x8C, 0x8D, 0x83, 0x78, 0x77, 0x7D, 
	0x82, 0x82, 0x80, 0x7E, 0x7F, 0x83, 0x85, 0x84, 0x83, 0x84, 0x7F, 0x74, 0x71, 0x7F, 0x8E, 0x8A, 
	0x79, 0x75, 0x7F, 0x85, 0x84, 0x8E, 0x9F, 0x98, 0x70, 0x55, 0x6D, 0x9B, 0xA6, 0x88, 0x6F, 0x76, 
	0x84, 0x82, 0x7C, 0x83, 0x8C, 0x84, 0x73, 0x6F, 0x7D, 0x8A, 0x8C, 0x86, 0x82, 0x81, 0x81, 0x81, 
	0x7D, 0x78, 0x79, 0x86, 0x94, 0x93, 0x82, 0x6F, 0x6D, 0x79, 0x83, 0x83, 0x80, 0x81, 0x85, 0x85, 
	0x81, 0x81, 0x83, 0x7E, 0x71, 0x6E, 0x83, 0x9E, 0x9F, 0x84, 0x6B, 0x6B, 0x7F, 0x8C, 0x89, 0x7E, 
	0x74, 0x70, 0x76, 0x83, 0x92, 0x9A, 0x93, 0x81, 0x6D, 0x68, 0x78, 0x8D, 0x92, 0x82, 0x72, 0x76, 
	0x84, 0x8A, 0x84, 0x7D, 0x7C, 0x7C, 0x7A, 0x7B, 0x7F, 0x84, 0x85, 0x84, 0x83, 0x81, 0x7F, 0x7F, 
	0x7D, 0x7A, 0x7A, 0x86, 0x94, 0x93, 0x81, 0x73, 0x78, 0x87, 0x8B, 0x7E, 0x72, 0x75, 0x82, 0x8A, 
	0x89, 0x84, 0x7F, 0x78, 0x6E, 0x6C, 0x7B, 0x8F, 0x93, 0x82, 0x70, 0x74, 0x85, 0x8C, 0x7F, 0x6F, 
	0x70, 0x7C, 0x85, 0x88, 0x8C, 0x8B, 0x80, 0x71, 0x6F, 0x7F, 0x8E, 0x8C, 0x7F, 0x77, 0x78, 0x7E, 
	0x82, 0x84, 0x84, 0x81, 0x7F, 0x80, 0x81, 0x7E, 0x79, 0x7B, 0x84, 0x89, 0x83, 0x7A, 0x77, 0x79, 
	0x78, 0x79, 0x81, 0x8E, 0x90, 0x82, 0x74, 0x76, 0x82, 0x88, 0x7F, 0x74, 0x74, 0x80, 0x8B, 0x8B, 
	0x84, 0x7F, 0x7D, 0x7B, 0x76, 0x76, 0x7F, 0x88, 0x84, 0x77, 0x73, 0x82, 0x91, 0x8D, 0x7A, 0x6F, 
	0x76, 0x82, 0x85, 0x84, 0x86, 0x87, 0x82, 0x79, 0x77, 0x7D, 0x82, 0x82, 0x80, 0x80, 0x82, 0x83, 
	0x82, 0x7F, 0x7B, 0x7B, 0x80, 0x85, 0x83, 0x7C, 0x79, 0x81, 0x89, 0x87, 0x7E, 0x78, 0x79, 0x7B, 
	0x7A, 0x7D, 0x84, 0x87, 0x82, 0x7A, 0x7A, 0x81, 0x87, 0x88, 0x87, 0x86, 0x83, 0x7F, 0x7D, 0x7E, 
	0x7E, 0x7E, 0x81, 0x86, 0x87, 0x7F, 0x77, 0x78, 0x7F, 0x84, 0x83, 0x82, 0x81, 0x7F, 0x7B, 0x7C, 
	0x81, 0x84, 0x80, 0x7B, 0x7A, 0x7E, 0x80, 0x81, 0x83, 0x86, 0x86, 0x81, 0x7C, 0x7C, 0x7F, 0x81, 
	0x80, 0x7F, 0x7F, 0x80, 0x81, 0x81, 0x82, 0x82, 0x7F, 0x7A, 0x79, 0x7F, 0x85, 0x84, 0x7E, 0x7B, 
	0x7C, 0x7E, 0x7E, 0x82, 0x8A, 0x8A, 0x7D, 0x6D, 0x6D, 0x7C, 0x8B, 0x8B, 0x82, 0x7B, 0x7B, 0x7E, 
	0x80, 0x81, 0x82, 0x81, 0x7D, 0x79, 0x79, 0x7E, 0x83, 0x84, 0x82, 0x80, 0x7F, 0x80, 0x80, 0x7E, 
	0x7B, 0x7C, 0x81, 0x87, 0x87, 0x80, 0x79, 0x79, 0x7D, 0x81, 0x81, 0x80, 0x80, 0x81, 0x82, 0x82, 
	0x81, 0x7F, 0x7B, 0x79, 0x7B, 0x82, 0x89, 0x8A, 0x82, 0x78, 0x76, 0x7E, 0x86, 0x84, 0x7D, 0x7A, 
	0x7D, 0x81, 0x82, 0x85, 0x8A, 0x89, 0x7F, 0x77, 0x7A, 0x84, 0x87, 0x80, 0x7A, 0x7C, 0x81, 0x83, 
	0x82, 0x81, 0x81, 0x7F, 0x7D, 0x7E, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x7F, 0x7E, 0x7E, 
	0x7F, 0x82, 0x85, 0x85, 0x81, 0x7C, 0x7B, 0x7F, 0x83, 0x82, 0x7E, 0x7D, 0x80, 0x83, 0x84, 0x82, 
	0x81, 0x81, 0x7E, 0x7A, 0x79, 0x7F, 0x85, 0x84, 0x7F, 0x7C, 0x7F, 0x83, 0x83, 0x7F, 0x7B, 0x7C, 
	0x7F, 0x82, 0x82, 0x82, 0x81, 0x7F, 0x7C, 0x7C, 0x7F, 0x83, 0x83, 0x80, 0x7D, 0x7E, 0x80, 0x81, 
	0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x80, 0x81, 0x81, 0x80, 0x7F, 0x7F, 0x7F, 0x7E, 
	0x7E, 0x80, 0x82, 0x82, 0x7F, 0x7E, 0x7F, 0x81, 0x81, 0x7F, 0x7D, 0x7E, 0x80, 0x81, 0x80, 0x7F, 
	0x7F, 0x7F, 0x7E, 0x7E, 0x7F, 0x81, 0x81, 0x7F, 0x7D, 0x7E, 0x80, 0x81, 0x7F, 0x7E, 0x7E, 0x7F, 
	0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x80, 0x80, 0x80, 
};
