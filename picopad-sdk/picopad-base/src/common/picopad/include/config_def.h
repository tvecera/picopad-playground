// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

// Display
#ifndef WIDTH
#define WIDTH	320			// display width
#endif

#ifndef HEIGHT
#define HEIGHT	240			// display height
#endif

#ifndef FRAMESIZE
#define FRAMESIZE (WIDTH*HEIGHT) 	// frame size in number of colors
#endif

#ifndef USE_COLOR
#define USE_COLOR	1		// use color vector (lib_color.c, lib_color.h)
#endif

#ifndef DISP_SPI
#define DISP_SPI	spi0		// SPI used for display
#endif

#ifndef DISP_SPI_BAUD
#define DISP_SPI_BAUD	24000000	// SPI baudrate (max. CLK_PERI/2 = 24 MHz, absolute max. 62.5 MHz)
#endif

#ifndef DISP_BLK_PIN
#define DISP_BLK_PIN	16		// backlight pin
#endif

#ifndef DISP_DC_PIN
#define DISP_DC_PIN	17		// data/command pin
#endif

#ifndef DISP_SCK_PIN
#define DISP_SCK_PIN	18		// serial clock pin
#endif

#ifndef DIDP_MOSI_PIN
#define DIDP_MOSI_PIN	19		// master out TX MOSI pin
#endif

#ifndef DISP_RES_PIN
#define DISP_RES_PIN	20		// reset pin
#endif

#ifndef DISP_CS_PIN
#define DISP_CS_PIN	21		// chip selection pin
#endif

#ifndef USE_CALENDAR
#define USE_CALENDAR	1		// use 32-bit calendar (lib_calendar.c, lib_calendar.h)
#endif

#ifndef USE_CRC
#define USE_CRC		1		// use CRC Check Sum (lib_crc.c, lib_crc.h)
#endif

#ifndef USE_DECNUM
#define USE_DECNUM	1		// use DecNum (decnum.c, decnum.h)
#endif

#ifndef USE_DRAWTFT
#define USE_DRAWTFT	1		// use TFT drawing (lib_drawtft.c, lib_drawtft.h)
#endif

#ifndef FONT
#define FONT		FontBold8x16	// default system font
#endif

#ifndef FONTW
#define FONTW		8		// width of system font
#endif

#ifndef FONTH
#define FONTH		16		// height of system font
#endif

// === SD card
#ifndef USE_SD
#define USE_SD		1		// use SD card (lib_sd.c, lib_sd.h)
#endif

#ifndef USE_FAT
#define USE_FAT		1		// use FAT file system (lib_fat.c, lib_fat.h)
#endif

#ifndef SD_SPI
#define SD_SPI		spi1		// SD card SPI interface
#endif

#ifndef SD_RX
#define SD_RX		12		// SD card RX (MISO input), to DATA_OUT pin 7
#endif

#ifndef SD_CS
#define SD_CS		13		// SD card CS, to CS pin 1
#endif

#ifndef SD_SCK
#define SD_SCK		10	// SD card SCK, to SCLK pin 5
#endif

#ifndef SD_TX
#define SD_TX		11	// SD card TX (MOSI output), to DATA_IN pin 2
#endif

#ifndef SD_BAUDLOW
#define SD_BAUDLOW	250000	// SD card low baud speed (to initialize connection)
#endif

#ifndef SD_BAUD
#define SD_BAUD		2000000 //7000000 // SD card baud speed (should be max. 7-12 Mbit/s; default standard bus speed
//   is 12.5 MB/s, suggested max. bitrate 15 Mbit/s, min. writting speed 2 MB/s)
#endif

#ifndef USE_LIST
#define USE_LIST	1		// use Doubly Linked List (lib_list.c, lib_list.h)
#endif

#ifndef USE_PRINT
#define USE_PRINT	1		// use Formated print (lib_print.c, lib_print.h)
#endif

#ifndef USE_STREAM
#define USE_STREAM	1		// use Data stream (lib_stream.c, lib_stream.h)
#endif

#define USE_PWMSND	4	// use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)

// PWM sound
#ifndef PWMSND_GPIO
#define PWMSND_GPIO	15		// PWM output GPIO pin (0..29)
#endif

// default LED pin on Raspberry Pico
#define LED_PIN 25

#ifndef BATTERY_FULL
#define BATTERY_FULL	4.2f		// voltage of full battery
#endif

#ifndef BATTERY_FULL_INT
#define BATTERY_FULL_INT 4200		// voltage of full battery
#endif

#ifndef BATTERY_EMPTY
#define BATTERY_EMPTY	3.1f		// voltage of empty battery
#endif

#ifndef BATTERY_EMPTY_INT
#define BATTERY_EMPTY_INT 3100		// voltage of empty battery
#endif
