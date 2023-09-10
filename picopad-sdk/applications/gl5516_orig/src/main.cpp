// Includes necessary libraries
#include "pico/printf.h"
#include <string.h>

// Graphics and display libraries
#include "st7789.h"
#include "lib_drawtft.h"

// Pico Pad specific libraries
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"

// Utility libraries
#include "sdk_watchdog.h"
#include "sdk_adc.h"

// Image resources
#include "images.h"

// Constants for ADC reading and lux calculation
#define KNOWN_RESISTOR 1000
#define LUX_CONVERSION_CONSTANT 29634400
#define LDR_LUX_POWER_VALUE 1.6689
#define PICO_MAX_ADC_READING 4095

// GL5516 LDR (Light Dependent Resistor) specific constants
#define GL5516_PIN 26
#define GL5516_ADC 0

int main() {
    // Initialize device
    DeviceInit(true);

    float resistanceRatio, ldrResistance, lightIntensityLux;
    int rawADCValue;
    char rawText[8];
    char luxText[10];

    // Initialize ADC and GL5516 GPIO
    ADC_Init();
    ADC_PinInit(GL5516_PIN);

    do {
        // Switch ADC to GL5516 input
        ADC_Mux(GL5516_ADC);

        // Clear display and draw GL5516 image
        DrawClear(COL_BLACK);
        DrawImgRle(Gl5516Img_RLE, Gl5516Img_Pal, 0, 0, 320, 240);

        // Set font and size
        pDrawFont = FontBold8x8;
        DrawFontHeight = 8;

        // Read ADC value
        rawADCValue = ADC_Single();

        // Avoid division by zero by capping the raw ADC reading
        if (rawADCValue > 4095)
            rawADCValue = 4095;

        // Calculate resistance ratio based on raw ADC value
        resistanceRatio = (PICO_MAX_ADC_READING / (float) rawADCValue) - 1;

        // Calculate the actual resistance of the LDR
        ldrResistance = KNOWN_RESISTOR * resistanceRatio;

        // Calculate the light intensity in Lux
        lightIntensityLux = LUX_CONVERSION_CONSTANT / (float) pow(ldrResistance, LDR_LUX_POWER_VALUE);

        // Calculate positions for text display
        uint8_t y = 155;
        uint8_t lx = WIDTH / 4;

        // Format and display light intensity and raw ADC value
        snprintf(luxText, sizeof(luxText), "%0.1f", lightIntensityLux);
        DrawText2(luxText, lx - static_cast<int>(strlen(luxText) * 16) / 2, y, COL_WHITE);
        DrawText("LUX", lx - (3 * 8) / 2, y + 25, COL_WHITE);

        snprintf(rawText, sizeof(rawText), "%d", rawADCValue);
        DrawText2(rawText, (lx * 3) - static_cast<int>(strlen(rawText) * 16) / 2, y, COL_WHITE);
        DrawText("RAW", (lx * 3) - (3 * 8) / 2, y + 25, COL_WHITE);

        // Update the display
        DispUpdate();

        // Delay for 100 milliseconds
        sleep_ms(100);

        // Continue this loop until a key press is detected
    } while (KeyGet() == NOKEY);

    // Reset to bootloader when a key is pressed
    ResetToBootLoader();
}
