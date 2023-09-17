// Includes necessary libraries
#include "pico/printf.h"

// Graphics and display libraries
#include "st7789.h"
#include "lib_drawtft.h"

// Picopad specific libraries
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"

// Utility libraries
#include "sdk_watchdog.h"

int main() {

    // Initialize device
    DeviceInit(true);
    
    // Nastavení pinu PIR senzoru
    const uint pir_pin = 28; // Změňte podle zapojení

    gpio_init(pir_pin);
    gpio_set_dir(pir_pin, GPIO_IN);

    bool motionDetected = false;
    
    char motionText[30];
    char motionDetectText[30];

    do {
        // Clear the display
        DrawClear(COL_BLACK);

        bool motion = gpio_get(pir_pin);

        if (motion && !motionDetected) {
            motionDetected = true;
            
            DrawClear(COL_BLACK);
            snprintf(motionDetectText, sizeof(motionDetectText), "ALARM! Motion detected!");
            DrawText2(motionDetectText, 105, 120, COL_RED);
            DispUpdate();
        } 
        else if (!motion && motionDetected) {
            motionDetected = false;
            DrawClear(COL_BLACK);
            snprintf(motionText, sizeof(motionText), "No motion");
            DrawText2(motionText, 105, 120, COL_WHITE);
            DispUpdate();
        }

        // Continue this loop until a key press is detected
    } while (KeyGet() == NOKEY);

    // Reset to bootloader when a key is pressed
    ResetToBootLoader();
}
