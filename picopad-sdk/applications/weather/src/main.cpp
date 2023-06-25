#include "pico/printf.h"
#include "hardware/i2c.h"
#include <string.h>

#include "st7789.h"
#include "lib_drawtft.h"
#include "sdk_bootrom.h"

#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"
#include "sdk_watchdog.h"

#include "bme280.h"
#include "images.h"

int main() {
    DeviceInit();

    DrawClear(COL_BLACK);
    KeyFlush();

    i2c_init(i2c0, 400000);
    gpio_set_function(0, GPIO_FUNC_I2C);
    gpio_set_function(1, GPIO_FUNC_I2C);
    gpio_pull_up(0);
    gpio_pull_up(1);

    BME280 sensor = BME280(i2c0);
    bool connected = sensor.begin();
    bool lastConnected = true;
    sleep_ms(100);

    do {

        DrawClear(COL_BLACK);

        DrawImgRle(SensorImg_RLE, SensorImg_Pal, 0, 0, 320, 240);

        if (!lastConnected && connected) {
            connected = sensor.begin();
            sleep_ms(100);
        }

        char chipId[20];
        snprintf(chipId, sizeof(chipId), "ChipID: 0x%x", sensor.sensorID());

        char address[20];
        snprintf(address, sizeof(address), "A: 0x%x", BME280_ADDRESS);

        SelFont8x8();
        DrawText(chipId, 112, 19, COL_WHITE);
        DrawText(address, 112 + (strlen(chipId) * 8) + 8, 19, COL_WHITE);

        pDrawFont = FontBold8x8; // font 8x8
        DrawFontHeight = 8; // font height

        if (connected) {

            char temperature[8];
            snprintf(temperature, sizeof(temperature), "%.1f`C", sensor.readTemperature());

            char humidity[8];
            snprintf(humidity, sizeof(humidity), "%.1f%%", sensor.readHumidity());

            float pressureValue = sensor.readPressure() / 100.0f;
            char pressure[11];
            snprintf(pressure, sizeof(pressure), "%.1f", pressureValue);

            float altitudeValue = sensor.readAltitude();
            char altitude[20];
            snprintf(altitude, sizeof(altitude), "%.0f m", altitudeValue);

            char sealevel[20];
            snprintf(sealevel, sizeof(sealevel), "%.0f hPa", sensor.seaLevelForAltitude(altitudeValue, pressureValue));

            char waterBoilingPoint[20];
            snprintf(waterBoilingPoint, sizeof(waterBoilingPoint), "%.1f`C", sensor.waterBoilingPoint(pressureValue));

            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

            DrawText2(temperature, 80, 60, COL_WHITE);
            DrawText2(humidity, 80, 118, COL_WHITE);
            DrawText2(pressure, 80, 178, COL_WHITE);
            DrawText2("hPa", 80 + (strlen(pressure) * 16) + 4, 178, COL_WHITE);

            u8 ay = 60;
            u8 dy = 15;
            DrawText("Altitude", 260 - (strlen("Altitude") * 8) / 2, ay, COL_WHITE);
            DrawText(altitude, 260 - (strlen(altitude) * 8) / 2, ay + dy, COL_WHITE);

            DrawText("Sea Level", 260 - (strlen("Sea Level") * 8) / 2, ay + 3 * dy, COL_WHITE);
            DrawText(sealevel, 260 - (strlen(sealevel) * 8) / 2, ay + 4 * dy, COL_WHITE);

            DrawText("WBDP", 260 - (strlen("WBDP") * 8) / 2, ay + 6 * dy, COL_WHITE);
            DrawText(waterBoilingPoint, 260 - (strlen(waterBoilingPoint) * 8) / 2, ay + 7 * dy, COL_WHITE);

        } else {
            DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
            DrawRect(12, 45, 80, HEIGHT - 12, COL_BLACK);
            const char * d = "DISCONNECTED";
            DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8 ) / 2, (WIDTH / 2) - (strlen(d) * 8 ) / 2, COL_RED);
        }

        // redraw display
        DispUpdate();

        sleep_ms(100);

        lastConnected = connected;
        connected = sensor.readSensorId();
    } while (KeyGet() == NOKEY);

    ResetToBootLoader();
}