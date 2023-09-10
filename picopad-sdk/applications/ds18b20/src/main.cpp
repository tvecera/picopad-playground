// Includes necessary libraries
#include "pico/printf.h"
#include <string.h>
#include "stdio.h"

// Graphics and display libraries
#include "st7789.h"
#include "lib_drawtft.h"

// Picopad specific libraries
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"

// Utility libraries
#include "sdk_watchdog.h"
#include "one_wire.h"

// Image resources
#include "images.h"

// Defines the GPIO pin for the DS18B20 temperature sensor
#define DS18B20_GPIO_PIN 26
// Defines a temperature correction factor
#define TEMP_CORRECTION (-0.7f)

// Function to wait for a specified number of milliseconds.
// It also checks for a key press every 10 milliseconds. If the Y key is pressed, it resets to the bootloader.
void wait(uint16_t ms) {
    for (uint16_t i = 0; i < ms / 10; i++) {
        sleep_ms(10);
        if (KeyGet() == KEY_Y) ResetToBootLoader();
    }
}

int main() {
    // Initializes the device
    DeviceInit(true);

    // Creates and initializes an instance of One_wire for the DS18B20 temperature sensor
    One_wire one_wire(DS18B20_GPIO_PIN);
    one_wire.init();
    rom_address_t address{};
    sleep_ms(100);

    // Prepares text variables for the sensor's address and temperature readings
    char addressText[40];
    char temperatureText[15];
    char fahrentemperature[15];
    char kelvintemperature[15];
    bool connected;

    do {
        // Clears the display and draws the background image
        DrawClear(COL_BLACK);
        DrawImgRle(Ds18B20Img_RLE, Ds18B20Img_Pal, 0, 0, 320, 240);

        // Reads the ROM address of the DS18B20 temperature sensor
        one_wire.single_device_read_rom(address);
        sleep_ms(100);
        uint64_t addressValue = One_wire::to_uint64(address);
        // Checks if the sensor is connected by verifying if the address value is greater than 0
        connected = addressValue > 0;

        // If the sensor is connected
        if (connected) {
            // Draws the connected icon to the display.
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

            // Requests a temperature conversion, waits for it to complete, and then reads the temperature
            one_wire.convert_temperature(address, true, false);
            wait(1000);
            float temperature = one_wire.temperature(address) + TEMP_CORRECTION;

            float celsius = temperature;
            float fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;
            float kelvin = celsius + 273.15f;

            // Formats the sensor address and temperature reading into text strings
            snprintf(temperatureText, sizeof(temperatureText), "%3.1f `C", celsius);
            snprintf(fahrentemperature, sizeof(fahrentemperature), "%.1f `F", fahrenheit);
            snprintf(kelvintemperature, sizeof(kelvintemperature), "%.1f K", kelvin);      
            snprintf(addressText, sizeof(addressText), "Address: 0x%llx", addressValue);
            
            // Draws the temperature reading and sensor address on the display
            pDrawFont = FontBoldB8x16;
            DrawFontHeight = 16;
            DrawText2(temperatureText, 140, 65, COL_WHITE);
            DrawText2(fahrentemperature, 140, 95, COL_WHITE);
            DrawText2(kelvintemperature, 140, 125, COL_WHITE);

            pDrawFont = FontBold8x8;
            DrawFontHeight = 8;
            DrawText(addressText, WIDTH / 2 - (strlen(addressText) * 8) / 2, 175, COL_WHITE);
        } else {
            // If the sensor is not connected, display a disconnected image and a "DISCONNECTED" message.
            DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
            DrawRect(12, 45, 200, HEIGHT - 12, COL_BLACK);
            const char *d = "DISCONNECTED";
            DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8) / 2, (WIDTH / 2) - (strlen(d) * 8) / 2, COL_RED);
        }

        // Update the display
        DispUpdate();

        // Delay for 1 second
        wait(1000);

        // Continue this loop until a key press is detected
    } while (KeyGet() == NOKEY);

    // Reset to bootloader when a key is pressed
    ResetToBootLoader();
}
