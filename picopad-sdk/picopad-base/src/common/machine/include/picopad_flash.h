#ifndef _PICOPAD_FLASH_H
#define _PICOPAD_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "pico/sync.h"

#define FLASH_TARGET_OFFSET 0x10000

// Returns the boot count stored in flash
uint8_t get_boot_count();

// Increments the boot count stored in flash
void increment_boot_count();

// Returns the sound setting stored in flash
bool get_sound_status();

// Toggles the sound setting stored in flash
void flash_toggle_sound();

#ifdef __cplusplus
}
#endif

#endif //_PICOPAD_FLASH_H
