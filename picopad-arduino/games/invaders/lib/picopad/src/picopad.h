// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#ifndef PICOPAD_HEADER_H
#define PICOPAD_HEADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pico/time.h"
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"
#include "hardware/flash.h"
#include "hardware/dma.h"
#include "pico/sync.h"
#include <math.h>
#include <string.h>
#include "user_config.h"

#ifndef PWMSND_GPIO
#define PWMSND_GPIO  15    // PWM output GPIO pin (0..29)
#endif

#ifndef WIDTH
#define WIDTH  320      // display width
#endif

#ifndef HEIGHT
#define HEIGHT  240      // display height
#endif

#ifndef FRAMESIZE
#define FRAMESIZE (WIDTH*HEIGHT)  // frame size in number of colors
#endif

#ifndef DISP_SPI
#define DISP_SPI  spi0    // SPI used for display
#endif

#ifndef DISP_BLK_PIN
#define DISP_BLK_PIN  16    // backlight pin
#endif

#ifndef DISP_DC_PIN
#define DISP_DC_PIN  17    // data/command pin
#endif

#ifndef DISP_SCK_PIN
#define DISP_SCK_PIN  18    // serial clock pin
#endif

#ifndef DIDP_MOSI_PIN
#define DIDP_MOSI_PIN  19    // master out TX MOSI pin
#endif

#ifndef DISP_RES_PIN
#define DISP_RES_PIN  20    // reset pin
#endif

#ifndef DISP_CS_PIN
#define DISP_CS_PIN  21    // chip selection pin
#endif

#ifndef FONT
#define FONT    FontBold8x16  // default system font
#endif

#ifndef FONTW
#define FONTW    8    // width of system font
#endif

#ifndef FONTH
#define FONTH    16    // height of system font
#endif

// SD card
#ifndef SD_SPI
#define SD_SPI    spi1    // SD card SPI interface
#endif

#ifndef SD_RX
#define SD_RX    12    // SD card RX (MISO input), to DATA_OUT pin 7
#endif

#ifndef SD_CS
#define SD_CS    13    // SD card CS, to CS pin 1
#endif

#ifndef SD_SCK
#define SD_SCK    10  // SD card SCK, to SCLK pin 5
#endif

#ifndef SD_TX
#define SD_TX    11  // SD card TX (MOSI output), to DATA_IN pin 2
#endif

#ifndef SD_BAUDLOW
#define SD_BAUDLOW  250000  // SD card low baud speed (to initialize connection)
#endif

#ifndef SD_BAUD
#define SD_BAUD    2000000 //7000000 // SD card baud speed (should be max. 7-12 Mbit/s; default standard bus speed
//   is 12.5 MB/s, suggested max. bitrate 15 Mbit/s, min. writting speed 2 MB/s)
#endif

// LEDs
#define LED1_PIN  22  // LED1 inverted, blue, on right
#define LED2_PIN  25  // default internal LED pin, on Pico board
// default LED pin on Raspberry Pico
#define LED_PIN 25

// Battery
#define BAT_PIN    29    // input from battery
#define BAT_ADC    ADC_MUX_GPIO29  // ADC input
#define BAT_MUL    3    // voltage multiplier
#define BAT_DIODE_FV_INT  311    // voltage drop in mV on diode
#define BAT_DIODE_FV    0.311f    // voltage drop in mV on diode
#define ADC_MUX_GPIO29  3  // pin GPIO 29

#ifndef BATTERY_FULL
#define BATTERY_FULL  4.2f    // voltage of full battery
#endif

#ifndef BATTERY_FULL_INT
#define BATTERY_FULL_INT 4200    // voltage of full battery
#endif

#ifndef BATTERY_EMPTY
#define BATTERY_EMPTY  3.1f    // voltage of empty battery
#endif

#ifndef BATTERY_EMPTY_INT
#define BATTERY_EMPTY_INT 3100    // voltage of empty battery
#endif

// Gamepad / Buttons GPIO
#define BTN_UP_PIN  4  // up
#define BTN_LEFT_PIN  3  // left
#define BTN_RIGHT_PIN  2  // right
#define BTN_DOWN_PIN  5  // down
#define BTN_X_PIN  9  // X
#define BTN_Y_PIN  8  // Y
#define BTN_A_PIN  7  // A
#define BTN_B_PIN  6  // B

#ifndef KEY_REP_TIME1
#define KEY_REP_TIME1  400  // delta time of first press in [ms] (max 500)
#endif

#ifndef KEY_REP_TIME2
#define KEY_REP_TIME2  100  // delta time of repeat press in [ms] (max 500)
#endif

#define BOOTLOADER_SIZE  0x30000    // size of boot loader 196608
#define BOOTLOADER_DATA  32    // boot loader resident data

#include "picopad_sdk.h"

#include "lib_drawtft.h"
#include "lib_pwmsnd.h"
#include "st7789.h"
#include "lib_crc.h"
#include "lib_fat.h"
#include "lib_sd.h"
#include "picopad_conf.h"
#include "picopad_bat.h"
#include "picopad_key.h"
#include "picopad_led.h"
#include "picopad_init.h"

#ifdef __cplusplus
}
#endif

#endif  // PICOPAD_HEADER_H