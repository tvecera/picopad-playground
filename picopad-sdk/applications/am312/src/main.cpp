//Includes necessary libraries
#include "pico/printf.h"

//Picopad specific libraries
#include "picopad_init.h"
#include "picopad_key.h"
#include "picopad_fonts.h"

//Utility libraries
#include "sdk_watchdog.h"

//Graphics and display libraries
#include "st7789.h"
#include "lib_drawtft.h"
#include "images.h"

int main() {

    //Initialize device
    DeviceInit(true);
        
    //Set PIN and GPIO
    const uint pirPin = 28;
    gpio_init(pirPin);
    gpio_set_dir(pirPin, GPIO_IN);

    //Variable for PIR sensor
    bool initialMotion = gpio_get(pirPin);
    bool motionDetected = initialMotion;
    
     //Text array for PIR sensor
    char motionText[30];
    char motionDetectText1[30];
    char motionDetectText2[30];

    //Sensor status after connection
    if (initialMotion) {
            //Clear the display with black color and draws the sensor image and connected icon to the display
            DrawClear(COL_BLACK);
            DrawImgRle(Am132Img_RLE, Am132Img_Pal, 0, 0, 320, 240);
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);
            
            //Prepare text to display sensor readings
            snprintf(motionDetectText1, sizeof(motionDetectText1), "ALARM!");
            snprintf(motionDetectText2, sizeof(motionDetectText2), "Motion detected!");
            
            //Draws the sensor readings to the display
            pDrawFont = FontBold8x8;
            DrawFontHeight = 8;
            DrawText2(motionDetectText1, 175, 75, COL_RED);
            pDrawFont = FontBold8x16;
            DrawFontHeight = 16;            
            DrawText(motionDetectText2, 160, 105, COL_RED);
            DispUpdate();

    } else {
            //Clear the display with black color and draws the sensor image and connected icon to the display
            DrawClear(COL_BLACK);
            DrawImgRle(Am132Img_RLE, Am132Img_Pal, 0, 0, 320, 240);
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

            //Prepare text to display sensor readings
            snprintf(motionText, sizeof(motionText), "No motion");
            
            //Draws the sensor readings to the display
            pDrawFont = FontBold8x16;
            DrawFontHeight = 16;
            DrawText(motionText, 185, 75, COL_YELLOW);
            DispUpdate();
    }

    do {
        //Clear the display with black color and draws the sensor image and connected icon to the display
        DrawClear(COL_BLACK);
        DrawImgRle(Am132Img_RLE, Am132Img_Pal, 0, 0, 320, 240);
        DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

        //PIR sensor status
        bool motion = gpio_get(pirPin);

        //Motion is detected
        if (motion && !motionDetected) {
            motionDetected = true;
            //Clear the display with black color and draws the sensor image and connected icon to the display
            DrawClear(COL_BLACK);
            DrawImgRle(Am132Img_RLE, Am132Img_Pal, 0, 0, 320, 240);
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);            
            
            //Prepare text to display sensor readings
            snprintf(motionDetectText1, sizeof(motionDetectText1), "ALARM!");
            snprintf(motionDetectText2, sizeof(motionDetectText2), "Motion detected!");
            
            //Draws the sensor readings to the display
            pDrawFont = FontBold8x8;
            DrawFontHeight = 8;            
            DrawText2(motionDetectText1, 175, 75, COL_RED);
            pDrawFont = FontBold8x16;
            DrawFontHeight = 16;            
            DrawText(motionDetectText2, 160, 105, COL_RED);
            DispUpdate();
        } 

        //The end of motion detected
        else if (!motion && motionDetected) {
            motionDetected = false;
            //Clear the display with black color and draws the sensor image and connected icon to the display
            DrawClear(COL_BLACK);
            DrawImgRle(Am132Img_RLE, Am132Img_Pal, 0, 0, 320, 240);
            DrawImgRle(ConnectedImg_RLE, ConnectedImg_Pal, 284, 3, 30, 30);

            //Prepare text to display sensor readings
            snprintf(motionText, sizeof(motionText), "No motion");
            
            //Draws the sensor readings to the display
            pDrawFont = FontBold8x16;
            DrawFontHeight = 16;
            DrawText(motionText, 185, 75, COL_YELLOW);
            DispUpdate();
        }

    //Continue this loop until a key press is detected
    } while (KeyGet() == NOKEY);
    //Reset to bootloader when a key is pressed
    ResetToBootLoader();
}
