// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "picopad.h"

// do single conversion with denoise (returns value 0..0xffff; takes 32 us on 48 MHz clock
u16 ADC_SingleDenoise()
{
	int i;
	u16 t = 0;
	for (i = 16; i > 0; i--) t += ADC_Single();
	return t;
}

// do single conversion and recalculate to voltage on 3.3V
float ADC_SingleU()
{
	return ADC_SingleDenoise() * 3.3f / (4096*16);
}

// do single conversion and recalculate to voltage on 3.3V, integer in mV (range 0..3300)
int ADC_SingleUint()
{
	return ADC_SingleDenoise() * 3300 / (4096*16);
}

void ADC_Disable() {
	adc_hw->cs = 0;
}

// decode unsigned number into ASCIIZ text buffer (returns number of digits)
//  sep = thousand separator, 0=none
int DecUNum(char* buf, u32 num, char sep)
{
	// temporary buffer (max. 10 digits + 3 separators + 1 NUL)
	char b[14];

	// decode number
	char* d = &b[13];
	*d = 0;
	int n = 0;
	u32 k;
	int sepn = 0;
	do {
		// thousand separator
		if ((sepn == 3) && (sep != 0))
		{
			sepn = 0;
			d--;
			*d = sep;
			n++;
		}

		k = num / 10;
		num -= k*10;
		d--;
		*d = (char)(num + '0');
		num = k;
		n++;
		sepn++;
	} while (num != 0);

	// copy number to destination buffer
	memcpy(buf, d, n+1);
	return n;
}

void reset_to_bootsel() {
	reset_usb_boot(0, 0);
}

// reset to boot loader
void ResetToBootLoader() {
	watchdog_enable(1, 1);
	while(1);
}