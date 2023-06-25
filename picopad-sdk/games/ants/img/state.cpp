#include "picopad.h"

// format: 8-bit paletted pixel graphics
// image width: 41 pixels
// image height: 144 lines
// image pitch: 41 bytes
const u16 StateImg_Pal[256] __attribute__ ((aligned(4))) = {
	0xFFFF, 0xFFE0, 0x0000, 0xA14A, 0x552A, 0x294A, 0x03B8, 0x7000, 0xFAAB, 0xA9E8, 0xAA8A, 0x8208, 0xFA4B, 0x91C8, 0x924A, 0x5802, 
	0xED36, 0x9948, 0x91EA, 0x9128, 0x9948, 0x9948, 0x5864, 0xB18A, 0x9948, 0x9847, 0xA0C8, 0xA149, 0xA18A, 0x7A0A, 0xA068, 0xA109, 
	0xA12A, 0xA14A, 0xA14A, 0xA14A, 0xA14A, 0xA16A, 0xA92A, 0xA12A, 0xA94A, 0xA94A, 0xA96B, 0xA1AB, 0xA8EA, 0x992A, 0x8129, 0x898A, 
	0xA22D, 0xA0AA, 0xA12B, 0xA2CF, 0x8A6D, 0xA391, 0x7B8F, 0xA474, 0xFF5F, 0xF81F, 0xD1BA, 0x72AE, 0x9915, 0xD49B, 0x49CB, 0x3108, 
	0x396A, 0x314A, 0x7358, 0x318A, 0x2128, 0x292A, 0x294A, 0x2128, 0x0026, 0x2108, 0x294A, 0x0000, 0x18C8, 0x2109, 0x294A, 0x2108, 
	0x2108, 0x294A, 0x2948, 0x294A, 0x296B, 0x212A, 0x52AF, 0x214A, 0xA558, 0x2148, 0x94FC, 0x214B, 0x192A, 0x7457, 0xC69D, 0x94F4, 
	0x1B37, 0x23B8, 0x6D9E, 0x5B90, 0xB63B, 0x0358, 0x0398, 0x0398, 0x03FA, 0x03D9, 0x03B8, 0x0398, 0x0398, 0x03B8, 0x03B8, 0x0335, 
	0x0BD8, 0x03F9, 0x03B8, 0x0376, 0x043B, 0x03D8, 0x1418, 0x1C7A, 0x0396, 0x03F8, 0x0C39, 0x0C18, 0x13F7, 0x1C38, 0x24DB, 0x2498, 
	0x03F6, 0x3CD8, 0x059E, 0x061F, 0x05DE, 0x05FE, 0x05FE, 0x065F, 0x063F, 0x061F, 0x05FE, 0x228B, 0xCF9F, 0x52CB, 0x230D, 0xA639, 
	0x01C8, 0x01A7, 0x22CB, 0x226A, 0x22CB, 0x22CB, 0x026A, 0x0ACB, 0x22EC, 0x2A8A, 0xAF3D, 0x028A, 0x7C30, 0x4A8A, 0x02AA, 0x028A, 
	0x02AA, 0x02AA, 0x0289, 0x02AA, 0x2A69, 0x1AEA, 0x0144, 0xAEFA, 0x52AA, 0x8DD5, 0x8CB2, 0x52AA, 0x8592, 0xB697, 0x7E32, 0x4D6B, 
	0x3347, 0x754F, 0x5E0C, 0x4CCA, 0x5C6C, 0x4C6A, 0x552A, 0x548A, 0x5C4B, 0x550A, 0x5D4B, 0x4D89, 0x554A, 0x552A, 0x552A, 0x554A, 
	0x554A, 0x554A, 0x552A, 0x550A, 0x550A, 0x54EA, 0x54EA, 0x52AA, 0x46A7, 0x3CC7, 0x44E8, 0x4D08, 0x4D09, 0x556A, 0x552A, 0x552A, 
	0x54E9, 0x44E8, 0x5DAA, 0x5D0A, 0x3E06, 0x744D, 0x6F69, 0x5FE6, 0x77EA, 0x67C7, 0x77A9, 0x77A9, 0x77EA, 0x5CAA, 0x77C9, 0x77AA, 
	0x7FE9, 0x6BC9, 0x2962, 0x31A4, 0x738C, 0x5AEB, 0x52AA, 0x52AA, 0x4224, 0x6307, 0x5AA8, 0x736A, 0xAC8A, 0x51A0, 0x5A00, 0x4980, 
	0x51A0, 0x51A0, 0x5AAA, 0x5140, 0x4920, 0x5100, 0x4A49, 0x930B, 0xCB0A, 0xFAEA, 0xCAAA, 0xCB2C, 0xAB2C, 0xE1E7, 0xFAAA, 0xFAAA, 
};

const u8 StateImg[5904] __attribute__ ((aligned(4))) = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x08, 0x09, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0xF4, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x30, 0x35, 0x2B, 0x1A, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x1F, 0x30, 0x58, 0x5E, 0xFC, 0x19, 0x26, 0x23, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x22, 0x1E, 0x09, 
	0xA9, 0x64, 0x30, 0x28, 0x1B, 0x31, 0x31, 0x31, 0x21, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x27, 0x31, 0xF8, 0xEC, 0x0B, 0x58, 0x9A, 0x33, 0x1E, 0xFA, 0xF8, 
	0x0A, 0x27, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x27, 0x31, 0xF8, 
	0xEC, 0x2F, 0x2C, 0x5F, 0x36, 0x19, 0x2B, 0xEC, 0xEC, 0xF7, 0x27, 0x20, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x22, 0x31, 0xF8, 0xEC, 0x2F, 0x2C, 0x23, 0x0D, 0x1A, 0x2A, 0x35, 
	0x34, 0x2E, 0x2D, 0x20, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x31, 0xF8, 
	0xEC, 0x2F, 0x2C, 0x23, 0x1F, 0x1E, 0x35, 0xA7, 0x9A, 0x35, 0x1E, 0x20, 0x22, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x26, 0x0A, 0x12, 0x2C, 0x21, 0x20, 0x20, 0x37, 0x9A, 
	0x8F, 0x37, 0x35, 0x1A, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x21, 0x31, 0x30, 0x58, 0x33, 0x32, 0x1E, 0x1A, 0x25, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x01, 0x01, 
	0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x03, 0x01, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x01, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x01, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x03, 
	0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 
	0x01, 0x01, 0x01, 0x03, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 
	0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x01, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x01, 0x03, 0x03, 0x01, 0x03, 0x01, 0x03, 
	0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 
	0x03, 0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 
	0xFF, 0x03, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x01, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x03, 
	0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x01, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x1B, 0x1B, 0x1B, 0x1B, 
	0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0xF3, 0xFF, 0x17, 0x13, 0x14, 0x11, 0x14, 0x14, 0x11, 0x14, 0x11, 0x14, 0x14, 0x14, 0x14, 
	0x11, 0x14, 0x15, 0x14, 0x14, 0x11, 0x14, 0x11, 0x14, 0x14, 0x15, 0x14, 0x11, 0x14, 0x14, 0x14, 
	0x14, 0x11, 0x14, 0x11, 0x14, 0x14, 0x11, 0x14, 0x14, 0x18, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x28, 
	0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x1F, 0x1A, 0x1F, 0x28, 0x29, 0x28, 0x28, 0x28, 
	0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x23, 0x03, 0x1A, 
	0x1E, 0x2B, 0x37, 0x33, 0x1E, 0x03, 0x23, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x24, 0x1F, 0x1E, 0x2B, 0x35, 0x8F, 0xA7, 0x8F, 0x33, 0x1A, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x1F, 0x2B, 
	0x37, 0x8F, 0xA7, 0x8F, 0x8F, 0xA7, 0x8F, 0x2A, 0x1F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x1A, 0x33, 0x9A, 0x8F, 0x8F, 0x64, 0x8F, 0xAA, 0xE4, 
	0x1C, 0x26, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x1A, 0x33, 0x8F, 0x8F, 0x8F, 0xAA, 0xEB, 0xE9, 0xE1, 0x1C, 0x26, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x1A, 0x33, 0x64, 0x58, 0xE4, 0xE9, 0xE1, 
	0xE1, 0xEB, 0x1C, 0x26, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x1F, 0x2B, 0x58, 0x58, 0xE1, 0xE1, 0xEB, 0x0E, 0x21, 0x20, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x24, 0x1A, 0x2A, 0x5F, 0xE4, 
	0x12, 0x26, 0x2C, 0x21, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 
	0x00, 0x03, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x00, 0x03, 
	0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 
	0x03, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 
	0xFF, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 
	0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF3, 0xFE, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 
	0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0xF3, 0x0C, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xF5, 0x09, 0xEF, 0xED, 0xF0, 0xF0, 
	0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 
	0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 
	0xF0, 0xF1, 0xF0, 0xEE, 0xD6, 0xDA, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 
	0xDB, 0xDB, 0xDF, 0xD9, 0xD7, 0xDA, 0xDF, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 
	0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDE, 0xDE, 0xD0, 0xD8, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xC8, 0xB1, 0x37, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x36, 0x39, 0x39, 0x3A, 0xCC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x93, 0xDC, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xC2, 0xCC, 0xBD, 0xB2, 0x3A, 0x3C, 0x3C, 
	0x39, 0x9C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0xBD, 0xCA, 0xA7, 0x8C, 0x5E, 0xAE, 0xCA, 0x3B, 0xB4, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xCA, 0xAE, 0x64, 0x5F, 0x5F, 
	0x8F, 0xB1, 0xD4, 0xBB, 0xC4, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0xD1, 0xA7, 0x5F, 0xE4, 0xE4, 0x5F, 0xA9, 0xD1, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xCA, 0xA9, 0x58, 
	0x9C, 0x9C, 0x58, 0xAC, 0xCB, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xBD, 0xC3, 0xA9, 0x8F, 0x8F, 0xAA, 0xCC, 0xBE, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xCC, 
	0x04, 0x8F, 0x5E, 0x58, 0xD5, 0xCB, 0xBF, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0xCE, 0x04, 0xCE, 0xCA, 0xB1, 0xA7, 0xA9, 0xA9, 0xAA, 0xDD, 0xBC, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 
	0xDC, 0x04, 0x04, 0x01, 0x01, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x04, 0x04, 0x04, 0x01, 
	0x04, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x01, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x01, 0x04, 0x04, 0x01, 0x04, 0x04, 0x01, 0x01, 0x04, 0x04, 0x04, 0x04, 0x01, 0x01, 0x04, 
	0x04, 0x01, 0x01, 0x04, 0x04, 0x01, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x99, 0xDC, 0x04, 0x04, 0x01, 0x01, 0x04, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 
	0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x01, 0x01, 0x01, 0x04, 0x01, 0x04, 0x04, 0x01, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 
	0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 
	0x04, 0x04, 0x04, 0x01, 0x04, 0x04, 0x04, 0x04, 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x01, 0x01, 0x01, 0x04, 0x04, 0x04, 0x01, 0x04, 0x04, 0x01, 
	0x04, 0x04, 0x01, 0x01, 0x04, 0x01, 0x04, 0x04, 0x01, 0x01, 0x04, 0x04, 0x01, 0x04, 0x04, 0x01, 
	0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 
	0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x04, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 
	0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0xD2, 0xB7, 0xC5, 0xC6, 0xC5, 0xC5, 0xC6, 0xC5, 0xC6, 
	0xC5, 0xC5, 0xC5, 0xC5, 0xC6, 0xC5, 0xC6, 0xC5, 0xC5, 0xC6, 0xC5, 0xC6, 0xC5, 0xC5, 0xC6, 0xC5, 
	0xC6, 0xC5, 0xC5, 0xC5, 0xC5, 0xC6, 0xC5, 0xC6, 0xC5, 0xC5, 0xC6, 0xC5, 0xD3, 0xB3, 0x99, 0xDC, 
	0x04, 0x04, 0x04, 0x04, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC1, 0xBD, 0xCB, 
	0xC0, 0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
	0xC0, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0xC1, 0xCC, 0xD1, 0xAD, 0xB1, 0xCB, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xCC, 0xC9, 
	0xAD, 0xAD, 0xCC, 0xBD, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xCC, 0xD1, 0xAD, 0xAD, 0xCA, 0xCC, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xBA, 0xBD, 0xD1, 
	0xAD, 0xAD, 0xD1, 0xCC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0xBD, 0xB1, 0xB1, 0xAD, 0xAD, 0xC9, 0xCC, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xBD, 0xBB, 
	0xAA, 0xAA, 0xCB, 0xCC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xBC, 0xB1, 0xD5, 0xB0, 0xB5, 0xCD, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0xC1, 0xB8, 0xCC, 0xB6, 0xB9, 0xCE, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 
	0xDC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x99, 0xDC, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 
	0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x04, 
	0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x00, 0x04, 0x04, 
	0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 
	0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 
	0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 
	0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xDC, 0x04, 0x04, 
	0x00, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
	0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x99, 0xE0, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xA4, 0xAF, 
	0x8B, 0x92, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x92, 0x92, 0x94, 0x94, 0x94, 
	0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 
	0x94, 0x94, 0x94, 0x94, 0x94, 0x95, 0x98, 0x8E, 0x82, 0x84, 0x8A, 0x85, 0x85, 0x85, 0x85, 0x85, 
	0x85, 0x85, 0x85, 0x85, 0x86, 0x86, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 
	0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x89, 0x83, 
	0x80, 0x87, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x96, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0xA2, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x6E, 0x7E, 0x62, 0x5A, 0x77, 0x7A, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6D, 0x68, 0x79, 0x63, 0x3D, 0x81, 0x7A, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x6D, 0x68, 0x71, 0xA6, 0x91, 0x7E, 0x7E, 0x75, 0x6D, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6D, 0x68, 0x71, 0xA6, 0x91, 0x74, 0x77, 0x76, 
	0x6B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x6D, 0x68, 0x71, 0xA6, 0x90, 0x74, 0x69, 0x65, 0x6B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 
	0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x69, 0x72, 0xA6, 0x90, 0x74, 0x69, 0x6D, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x68, 0x91, 0x90, 0x74, 0x69, 0x6D, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x01, 0x06, 0x06, 0x06, 0x01, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 
	0x01, 0x01, 0x06, 0x01, 0x01, 0x06, 0x01, 0x01, 0x06, 0x06, 0x06, 0x01, 0x01, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x01, 0x06, 0x01, 0x06, 0x01, 0x06, 0x06, 
	0x06, 0x01, 0x06, 0x01, 0x06, 0x01, 0x06, 0x01, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 
	0x06, 0x06, 0x01, 0x06, 0x06, 0x06, 0x01, 0x06, 0x01, 0x01, 0x01, 0x06, 0x06, 0x01, 0x01, 0x06, 
	0x01, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x01, 0x06, 0x06, 0x06, 0x01, 
	0x06, 0x01, 0x01, 0x01, 0x06, 0x06, 0x06, 0x01, 0x06, 0x01, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x71, 0x6F, 0x78, 0x78, 0x78, 
	0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x73, 0x73, 0x78, 0x78, 0x78, 0x78, 0x78, 
	0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 
	0x78, 0x78, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x66, 0x6A, 0x66, 
	0x81, 0x7F, 0x66, 0x6A, 0x66, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x6A, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x6B, 0x7D, 0x7F, 0x70, 0x7D, 0x7C, 0x7D, 0x7D, 0x70, 0x7F, 0x76, 0x6B, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6B, 0x70, 0x81, 
	0x7D, 0x65, 0x5A, 0x5D, 0x65, 0x7D, 0x81, 0x75, 0x6B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x72, 0x65, 0x70, 0x79, 0x65, 0x5A, 0x00, 0x3D, 0x42, 0x72, 0x7B, 
	0x70, 0x65, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6B, 0x7D, 
	0x81, 0x67, 0x5A, 0x00, 0x00, 0x38, 0x3D, 0x42, 0x79, 0x81, 0x76, 0x6B, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 
	0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6B, 0x76, 0x7F, 0x61, 0x3D, 0x5A, 0x5A, 0x5A, 0xF7, 
	0x34, 0x76, 0x7F, 0x7B, 0x6B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x65, 0x76, 0x79, 0x60, 0x42, 0x42, 0x3B, 0xE9, 0x6F, 0x7A, 0x76, 0x65, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6B, 0x7F, 0x7B, 0x61, 0x42, 
	0x3B, 0x6F, 0x77, 0x7D, 0x6B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x6B, 0x76, 0x81, 0x7D, 0x7B, 0x7D, 0x76, 0x7A, 0x7D, 0x81, 0x7B, 0x6B, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x6B, 0x7B, 0x70, 0x6E, 
	0x06, 0x81, 0x81, 0x6E, 0x6C, 0x70, 0x7B, 0x65, 0x6C, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x06, 
	0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x00, 
	0x06, 0x00, 0x06, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x06, 0x00, 0x06, 
	0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 
	0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x06, 0x06, 
	0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x88, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 
	0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x06, 
	0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x9F, 0x87, 0x06, 0x06, 0x00, 0x00, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x00, 0x00, 
	0x06, 0x06, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x9F, 0x87, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x9E, 0x80, 0xA2, 0xA2, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0x9F, 0xA5, 0xA5, 0x96, 0xA0, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 
	0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0x9B, 0xA3, 0x97, 0xF6, 0xAB, 0xA8, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0x9D, 0x9D, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 0xAB, 
	0xAB, 0xAB, 0xC7, 0x8D, 0x59, 0xF2, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x4B, 0xE7, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x57, 
	0x4D, 0x07, 0x16, 0x5B, 0x4E, 0x57, 0x55, 0x0F, 0x07, 0x57, 0x57, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 
	0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x5C, 0x3E, 0xFB, 0x0D, 0x4D, 0x55, 0x5C, 0x41, 
	0xFC, 0x09, 0x3F, 0x5B, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x4C, 0x56, 0x8C, 0x9C, 0xEA, 0xE5, 0xF2, 0xE4, 0x9A, 0xA9, 0x47, 0x55, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x4C, 0x56, 0x5E, 0x9C, 0xE9, 0xE9, 
	0xE9, 0xEB, 0x64, 0x5F, 0x44, 0x55, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x4C, 0x56, 0x5E, 0xAA, 0xE8, 0xE3, 0xE2, 0xEA, 0x5E, 0x5F, 0x47, 0x55, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x4C, 0x56, 0x64, 0x36, 
	0xE9, 0xEB, 0xEB, 0xE4, 0x58, 0xAA, 0x44, 0x55, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x00, 0x05, 0x05, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x02, 0xE7, 0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x05, 0x00, 
	0x00, 0x05, 0x00, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x00, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x00, 0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x05, 0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 
	0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x02, 0xE7, 0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x00, 
	0x05, 0x00, 0x05, 0x05, 0x00, 0x05, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x00, 
	0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 0x00, 0x05, 0x00, 0x05, 0x05, 
	0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x43, 
	0x4C, 0x4F, 0x50, 0x4F, 0x4F, 0x49, 0x4F, 0x49, 0x4F, 0x4F, 0x50, 0x4F, 0x49, 0x4F, 0x50, 0x4F, 
	0x4F, 0x49, 0x4F, 0x49, 0x4F, 0x4F, 0x50, 0x4F, 0x49, 0x4F, 0x50, 0x4F, 0x4F, 0x49, 0x4F, 0x49, 
	0x4F, 0x4F, 0x50, 0x4F, 0x4F, 0x4F, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x51, 0x51, 0x51, 0x4C, 0x5C, 0x54, 0x51, 0x51, 0x51, 0x51, 0x51, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 
	0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x4A, 0x4E, 0x48, 0x5D, 0x58, 0x49, 
	0x4E, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x45, 0x4C, 0x5D, 0x38, 0xFC, 0x4D, 0x4E, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x4D, 0x43, 0x10, 0xFB, 
	0x0B, 0x57, 0x53, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x5C, 0x40, 0xFD, 0xFA, 0x0E, 0x55, 0x4E, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x5C, 0x40, 
	0xFA, 0xF8, 0x1D, 0x55, 0x53, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x5C, 0x40, 0xF9, 0x0E, 0x5C, 0x55, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x55, 0x41, 0x1D, 0x41, 0x5C, 0x46, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x46, 0x4E, 0x5C, 0x55, 0x46, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x02, 0xE7, 0x05, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x00, 0x05, 0x05, 0x05, 
	0x00, 0x00, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x00, 0x00, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x02, 0xE7, 0x05, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 
	0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE7, 0x05, 0x00, 0x05, 
	0x05, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x02, 0xE6, 0x05, 0x00, 0x05, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x00, 
	0x05, 0x00, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0xE5, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x52, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
};
