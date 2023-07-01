// Includes necessary libraries
#include "pico/printf.h"

// Graphics and display libraries
#include "st7789.h"
#include "lib_drawtft.h"

// Pico Pad specific libraries
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"

// Utility libraries
#include "sdk_watchdog.h"
#include "hcsr04.h"

// Image resources
#include "images.h"

// Function to delay for specified milliseconds and check for KEY_Y key press to reset to bootloader
void wait(uint16_t ms) {
    for (uint16_t i = 0; i < ms / 10; i++) {
        sleep_ms(10);
        if (KeyGet() == KEY_Y) ResetToBootLoader();
    }
}

int main() {
    // Initialize device
    DeviceInit(true);

    // Initialize HCSR04 sensor with pin 1 as input and pin 0 as output
    HCSR04 my_HCSR04(1, 0);
    sleep_ms(100);

    // Variable to hold the distance reading from the sensor
    float distance;
    // Array to hold the formatted distance as a string
    char distanceText[20];

    // Main loop
    do {
        // Clear the display
        DrawClear(COL_BLACK);
        // Draw sensor image on the display
        DrawImgRle(Hcsr04Img_RLE, Hcsr04Img_Pal, 0, 0, 320, 240);

        // Draw the connected icon on the display
        DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

        // Read the distance from the sensor
        distance = my_HCSR04.read();
        sleep_ms(100);

        // If the distance reading is invalid or out of range, display ----.- CM
        if (distance <= 0 || distance >= 1200) {
            snprintf(distanceText, sizeof(distanceText), "%s CM", "----.-");
        }
            // Otherwise, display the distance reading in CM
        else {
            snprintf(distanceText, sizeof(distanceText), "%0.1f CM", distance);
        }

        // Set the font to bold, height 16
        pDrawFont = FontBoldB8x16;
        DrawFontHeight = 16;
        // Draw the distance text on the display
        DrawText2(distanceText, 105, 120, COL_WHITE);

        // Update the display
        DispUpdate();

        // Delay for 1 second
        wait(1000);

        // Continue this loop until a key press is detected
    } while (KeyGet() == NOKEY);

    // Reset to bootloader when a key is pressed
    ResetToBootLoader();
}
