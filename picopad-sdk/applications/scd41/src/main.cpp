#include "pico/printf.h"
#include "hardware/i2c.h"
#include <string.h>

#include "st7789.h"
#include "lib_drawtft.h"
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"
#include "sdk_watchdog.h"

#include "scd4x.h"
#include "images.h"

int main() {
    DeviceInit();

    DrawClear(COL_BLACK);
    KeyFlush();
    DrawImgRle(Scd41Img_RLE, Scd41Img_Pal, 0, 0, 320, 240);
    DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
    DrawRect(12, 45, 320, HEIGHT - 80, COL_BLACK);
    DrawText("Connecting...", 112, 19, COL_WHITE);

    DispUpdate();
    SCD4x SCD41;

    i2c_init(i2c0, 400000);
    gpio_set_function(0, GPIO_FUNC_I2C);
    gpio_set_function(1, GPIO_FUNC_I2C);
    gpio_pull_up(0);
    gpio_pull_up(1);

    bool connected = SCD41.begin(false, true);
    SCD41.startLowPowerPeriodicMeasurement();
    sleep_ms(100);

    if (connected) {
        do {
            DrawClear(COL_BLACK);
            DrawImgRle(Scd41Img_RLE, Scd41Img_Pal, 0, 0, 320, 240);
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 8, 30, 30);

            // Prepares text to display the address.
            char address[20];
            snprintf(address, sizeof(address), "Address: 0x%x", SCD4x_ADDRESS);

            SelFont8x8();
            // Draws the address to the display.
            DrawText(address, 112, 19, COL_WHITE);

            char ch = NOKEY;
            do {
                ch = KeyGet();
                sleep_ms(1);
            } while (!SCD41.readMeasurement() && ch == NOKEY);

            if (ch == KEY_Y) ResetToBootLoader();

            int CO2 = SCD41.getCO2();
            char temperature[8];
            snprintf(temperature, sizeof(temperature), "%.1f`C", SCD41.getTemperature());
            char humidity[8];
            snprintf(humidity, sizeof(humidity), "%.1f%%", SCD41.getHumidity());

            int normalizedCO2;
            if (CO2 >= 1500) {
                normalizedCO2 = 100;
            } else {
                normalizedCO2 = (int) ((CO2 / 1500.0) * 100.0);
            }

            u16 gaugeColor;
            if (CO2 < 600) {
                gaugeColor = 0x07E0; // Green
            } else if (CO2 < 1000) {
                gaugeColor = 0xFFE0; // Light yellow
            } else if (CO2 < 1500) {
                gaugeColor = 0xFD20; // Orange
            } else {
                gaugeColor = 0xF800; // Red
            }

            DrawGauge(160, 120, 60, 45, normalizedCO2, COL_WHITE, gaugeColor);

            char co2Text[8];
            snprintf(co2Text, sizeof(co2Text), "%u", CO2);

            pDrawFont = FontBold8x8;
            DrawFontHeight = 8;
            DrawText2(co2Text, 170 - static_cast<int>((strlen(co2Text) + 1) * 8), 120 - 10, COL_WHITE);
            DrawText("ppm", 170 - 20, 120 + 15, COL_WHITE);

            DrawText(temperature, 43 - static_cast<int>((strlen(temperature) * 8) / 2), 160, COL_WHITE);

            DrawText(humidity, 278 - static_cast<int>((strlen(humidity) * 8) / 2), 160, COL_WHITE);

            DispUpdate();

        } while (KeyGet() == NOKEY);
    } else {
        DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
        DrawRect(12, 45, 320, HEIGHT - 80, COL_BLACK);
        const char *d = "DISCONNECTED";
        DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8) / 2, (WIDTH / 2) - (strlen(d) * 8) / 2, COL_RED);
        DispUpdate();
        do {} while (KeyGet() == NOKEY);
        ResetToBootLoader();
    }

    ResetToBootLoader();
}