#ifndef USER_CONFIG_H
#define USER_CONFIG_H

#ifndef DEFAULT_BRIGHTNESS
#define DEFAULT_BRIGHTNESS 5
#endif

#ifndef DEFAULT_VOLUME
#define DEFAULT_VOLUME 5
#endif

#ifndef DEFAULT_SCREEN_SLEEP
#define DEFAULT_SCREEN_SLEEP 1
#endif

#ifndef DEFAULT_REFRESH_BATTERY
#define DEFAULT_REFRESH_BATTERY 1
#endif

#ifndef DEFAULT_BATTERY_ALARM
#define DEFAULT_BATTERY_ALARM 1
#endif

// Battery alarm threshold to play alarm battery low sound. Can be 0..12
#ifndef BATTERY_ALARM_THRESHOLD
#define BATTERY_ALARM_THRESHOLD 1
#endif

// Use ST7789 driver. Set to 0 to disable.
#ifndef USE_ST7789
#define USE_ST7789    0
#endif

// Use DRAWTFT driver. Set to 0 to disable.s
#ifndef USE_DRAWTFT
#define USE_DRAWTFT  0
#endif

#ifndef DISP_SPI_BAUD
#define DISP_SPI_BAUD  24000000  // SPI baudrate (max. CLK_PERI/2 = 24 MHz, absolute max. 62.5 MHz)
#endif

// PWM sound
#define USE_PWMSND  4  // 4 - use PWM sound output; set 1.. = number of channels (lib_pwmsnd.c, lib_pwmsnd.h)

#ifndef USE_SD
#define USE_SD 1
#endif

#ifndef USE_FAT
#define USE_FAT 1
#endif

#ifndef USE_CRC
#define USE_CRC 1
#endif

#ifndef USE_CONFIG
#define USE_CONFIG 1
#endif

#ifndef SYSTICK_KEYSCAN
#define SYSTICK_KEYSCAN    1  // call KeyScan() function from SysTick system timer
#endif

#endif //USER_CONFIG_H
