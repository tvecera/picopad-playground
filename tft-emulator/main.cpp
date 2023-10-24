// Includes libraries necessary for the code
#include "emulator/src/lib_drawtft.cpp"
#include "stdio.h"

void sensor(bool connected) {

    // Clear the display with black color
    DrawClear(RGBTO16(135, 165, 5));

    // Draws the sensor image to the display
    //DrawImgRle(SnakeImg_RLE, SnakeImg_Pal, 0, 0, 320, 240);

    // Sets the current font to 8x8.
    SelFont5x8();

    // Set the current font to bold 8x8 and the font height to 8
    //pDrawFont = FontBold8x8;
    //DrawFontHeight = 5;

    // If the sensor is connected, display its readings
    if (connected) {
       		DrawClear(RGBTO16(135, 165, 5));
            
            char score[10];
            char pause[10];

            snprintf(score, sizeof(score), "Score: 256");
            DrawText2(score, 30, 3, COL_BLACK);

            snprintf(pause, sizeof(pause), "Pause");
            DrawText2(pause, 245, 3, COL_BLACK);

            DrawLine (20, 22, 305, 22, COL_BLACK);
            DrawLine (20, 23, 305, 23, COL_BLACK);             
            // Draws the connected icon to the display
            //DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);
            
            //The following block prepares text to display sensor readings: temperature
/*             char temperature[8];
            char fahrentemperature[15];
            char kelvintemperature[15];
            char addressText[40];

            float celsius = 25.4f;
            float fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;
            float kelvin = celsius + 273.15f;
            
            snprintf(temperature, sizeof(temperature), "%.1f `C", 25.4f);
            snprintf(fahrentemperature, sizeof(fahrentemperature), "%.1f `F", fahrenheit);
            snprintf(kelvintemperature, sizeof(kelvintemperature), "%.1f K", kelvin);      
            snprintf(addressText, sizeof(addressText), "Address: 0x28b8e5c5802206e7");

            // Draws the sensor readings to the display
            DrawText2(temperature, 140, 65, COL_WHITE);
            DrawText2(fahrentemperature, 140, 95, COL_WHITE);
            DrawText2(kelvintemperature, 140, 125, COL_WHITE);
            DrawText(addressText, WIDTH / 2 - (strlen(addressText) * 8) / 2, 175, COL_WHITE); */

    }/*    else {
        // If the sensor is not connected, display a disconnected image and a "DISCONNECTED" message
        //DrawImgRle(DconnectedImg_RLE, DconnectedImg_Pal, 284, 8, 30, 30);
        DrawRect(12, 45, 80, HEIGHT - 12, COL_BLACK);
        const char *d = "DISCONNECTED";
        DrawText2(d, (HEIGHT / 2) - (strlen(d) * 8) / 2, (WIDTH / 2) - (strlen(d) * 8) / 2, COL_RED);
    }  */

    // Updates the display with the drawn elements
    DispUpdate();
}


int main() {
    // Creates a frame with given display width and height
    FrameTex.create(DispWidth, DispHeight);
    FrameSprite.setTexture(FrameTex);

    // Presumes sensor connection is established by default
    bool connected = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check if the window was closed, if yes terminate the main loop
            if (event.type == sf::Event::Closed)
                window.close();

            // If a key was pressed
            if (event.type == sf::Event::KeyPressed) {
/*                 // If the 'C' key was pressed
                if (event.key.code == sf::Keyboard::C) {
                    // Toggle the connected variable
                    connected = !connected;
                } */
                if (event.key.code == sf::Keyboard::Y) {
                    window.close();
                    return 0;
                }
            }
        }

        sensor(connected);

        // Clears the window, draws the frame sprite, and displays the window
        window.clear();
        window.draw(FrameSprite);
        window.display();
    }

    return 0;
}
