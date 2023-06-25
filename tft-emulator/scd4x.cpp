// Includes libraries necessary for the code.
#include "emulator/src/lib_drawtft.cpp"
#include "scd4x-images.h"

//void sensor(bool connected) {
//
//    // Clear the display with black color.
//    DrawClear(COL_BLACK);
//
//    // Draws the sensor image to the display.
//    DrawImgRle(SensorImg_RLE, SensorImg_Pal, 0, 0, 320, 240);
//
//    // Prepares text to display the chip ID.
//    char chipId[20];
//    snprintf(chipId, sizeof(chipId), "ChipID: 0x%x", 0x60);
//
//    // Prepares text to display the address.
//    char address[20];
//    snprintf(address, sizeof(address), "A: 0x%x", 0x76);
//
//    // Sets the current font to 8x8.
//    SelFont8x8();
//    // Draws the chip ID and address to the display.
//    DrawText(chipId, 112, 19, COL_WHITE);
//    DrawText(address, 112 + (strlen(chipId) * 8) + 8, 19, COL_WHITE);
//
//    // Set the current font to bold 8x8 and the font height to 8.
//    pDrawFont = FontBold8x8;
//    DrawFontHeight = 8;
//
//    // If the sensor is connected, display its readings.
//    if (connected) {
//        // The following block prepares text to display sensor readings: temperature, humidity, pressure, altitude, sea level and water boiling point.
//        char temperature[8];
//        snprintf(temperature, sizeof(temperature), "%.1f`C", 25.4f);
//
//        char humidity[8];
//        snprintf(humidity, sizeof(humidity), "%.1f%%", 48.0);
//
//        char pressure[11];
//        snprintf(pressure, sizeof(pressure), "%.1f", 98025 / 100.0);
//
//        char altitude[20];
//        snprintf(altitude, sizeof(altitude), "%.0f m", 450.0f);
//
//        char sealevel[20];
//        snprintf(sealevel, sizeof(sealevel), "%.0f m", 450.0f);
//
//        char waterBoilingPoint[20];
//        snprintf(waterBoilingPoint, sizeof(waterBoilingPoint), "%.1f`C", 100.0f);
//
//        // Draws the connected icon to the display.
//        DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);
//
//        // Draws the sensor readings to the display.
//        DrawText2(temperature, 80, 60, COL_WHITE);
//        DrawText2(humidity, 80, 118, COL_WHITE);
//        DrawText2(pressure, 80, 178, COL_WHITE);
//        DrawText2("hPa", 80 + (strlen(pressure) * 16) + 4, 178, COL_WHITE);
//
//        u8 ay = 60;
//        u8 dy = 15;
//        DrawText("Altitude", 260 - (strlen("Altitude") * 8) / 2, ay, COL_WHITE);
//        DrawText(altitude, 260 - (strlen(altitude) * 8) / 2, ay + dy, COL_WHITE);
//
//        DrawText("Sea Level", 260 - (strlen("Sea Level") * 8) / 2, ay + 3 * dy, COL_WHITE);
//        DrawText(sealevel, 260 - (strlen(sealevel) * 8) / 2, ay + 4 * dy, COL_WHITE);
//
//        DrawText("WBDP", 260 - (strlen("WBDP") * 8) / 2, ay + 6 * dy, COL_WHITE);
//        DrawText(waterBoilingPoint, 260 - (strlen(waterBoilingPoint) * 8) / 2, ay + 7 * dy, COL_WHITE);
//
//    } else {
//        // If the sensor is not connected, display a disconnected image and a "DISCONNECTED" message.
//        DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
//        DrawRect(12, 45, 80, HEIGHT - 12, COL_BLACK);
//        const char *d = "DISCONNECTED";
//        DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8) / 2, (WIDTH / 2) - (strlen(d) * 8) / 2, COL_RED);
//    }
//
//    // Updates the display with the drawn elements.
//    DispUpdate();
//}


int main() {
    // Creates a frame with given display width and height.
    FrameTex.create(DispWidth, DispHeight);
    FrameSprite.setTexture(FrameTex);

    bool connected = false;
    bool lastConnected = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check if the window was closed, if yes terminate the main loop.
            if (event.type == sf::Event::Closed)
                window.close();

            // If a key was pressed.
            if (event.type == sf::Event::KeyPressed) {
                // If the 'C' key was pressed.
                if (event.key.code == sf::Keyboard::C) {
                    // Toggle the connected variable.
                    connected = !connected;
                }
                if (event.key.code == sf::Keyboard::Y) {
                    window.close();
                    return 0;
                }
            }
        }

        DrawClear(COL_BLACK);
        DrawImgRle(Scd41Img_RLE, Scd41Img_Pal, 0, 0, 320, 240);

        if (!lastConnected && connected) {
            //connected = sensor.begin();
            //sleep_ms(100);
        }

        // Prepares text to display the chip ID.
        char chipId[20];
        snprintf(chipId, sizeof(chipId), "ChipID: 0x%x", 0x60);

        // Prepares text to display the address.
        char address[20];
        snprintf(address, sizeof(address), "A: 0x%x", 0x68);

        SelFont8x8();
        // Draws the chip ID and address to the display.
        DrawText(chipId, 112, 19, COL_WHITE);
        DrawText(address, 112 + (strlen(chipId) * 8) + 8, 19, COL_WHITE);

        if (connected) {
            char temperature[8];
            snprintf(temperature, sizeof(temperature), "%.1f`C", 25.4f);

            char humidity[8];
            snprintf(humidity, sizeof(humidity), "%.1f%%", 48.0);

            int CO2 = 600;

            // Převedeme hodnotu CO2 na rozsah 0-100
            int normalizedCO2;
            if (CO2 >= 1500) {
                normalizedCO2 = 100;
            } else {
                normalizedCO2 = (int)((CO2 / 1500.0) * 100.0);
            }

            // Určíme barvu pro vykreslení grafu na základě úrovně CO2
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
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 8, 30, 30);

            char co2Text[8];
            snprintf(co2Text, sizeof(co2Text), "%u", CO2);

            pDrawFont = FontBold8x8;
            DrawFontHeight = 8;
            DrawText2(co2Text, 170 - static_cast<int>((strlen(co2Text) + 1) * 8), 120 - 10, COL_WHITE);
            DrawText("ppm", 170 - 20, 120 + 15, COL_WHITE);

            DrawText(temperature, 43 - static_cast<int>((strlen(temperature) * 8) / 2), 160, COL_WHITE);

            DrawText(humidity, 278 - static_cast<int>((strlen(humidity) * 8) / 2), 160, COL_WHITE);
        }  else {
            DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
            DrawRect(12, 45, 320, HEIGHT - 80, COL_BLACK);
            const char * d = "DISCONNECTED";
            DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8 ) / 2, (WIDTH / 2) - (strlen(d) * 8 ) / 2, COL_RED);
        }

        DispUpdate();

        //lastConnected = connected;
        //connected = sensor.readSensorId();

        // Clears the window, draws the frame sprite, and displays the window.
        window.clear();
        window.draw(FrameSprite);
        window.display();
    }

    return 0;
}
