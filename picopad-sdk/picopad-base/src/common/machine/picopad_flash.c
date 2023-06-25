#include "picopad_flash.h"

#define FLASH_TARGET_ADDRESS (XIP_BASE + FLASH_TARGET_OFFSET)
#define FLASH_DATA_PER_SECTOR (FLASH_SECTOR_SIZE / sizeof(flash_data_t))

// The data structure that will be stored in flash.
typedef struct {
    uint8_t boot_count;         // The boot count.
    uint8_t sound_enabled: 1;  // The sound setting.
    uint8_t unused_1: 1;       // Additional toggle (currently unused).
    uint8_t unused_2: 1;       // Additional toggle (currently unused).
    uint32_t unused_3: 8;      // Unused field for future use.
} flash_data_t;

static void read_flash_data(flash_data_t *data) {
    for (size_t i = 0; i < (FLASH_DATA_PER_SECTOR); ++i) {
        data[i] = *(volatile flash_data_t *) (XIP_BASE + FLASH_TARGET_ADDRESS + i * sizeof(flash_data_t));
    }
}

static void write_flash_data(const flash_data_t *data) {
    uint32_t irq = save_and_disable_interrupts();

    flash_range_erase(FLASH_TARGET_ADDRESS, FLASH_DATA_PER_SECTOR * sizeof(flash_data_t));

    for (size_t i = 0; i < FLASH_DATA_PER_SECTOR; ++i) {
        flash_range_program(FLASH_TARGET_ADDRESS + i * sizeof(flash_data_t), (const uint8_t *) &data[i], sizeof(flash_data_t));
    }

    restore_interrupts(irq);
}

// Reads the last written flash data.
static flash_data_t read_last_data() {
    flash_data_t flash_data[FLASH_SECTOR_SIZE / sizeof(flash_data_t)];
    read_flash_data(flash_data);

    // Scan the sector in reverse order to find the last written data.
    for (int i = FLASH_DATA_PER_SECTOR - 1; i >= 0; --i) {
        if (flash_data[i].boot_count != 0xFF) {
            return flash_data[i];
        }
    }

    // If no valid data is found, return a default structure
    flash_data_t default_data = {0, 1, 0, 0, 0};
    return default_data;
}

// Writes new data to flash.
static void write_new_data(flash_data_t new_data) {
    flash_data_t flash_data[FLASH_DATA_PER_SECTOR];
    read_flash_data(flash_data);

    int write_index = -1;

    for (int i = 0; i < FLASH_DATA_PER_SECTOR; ++i) {
        if (flash_data[i].boot_count == 0xFF) {
            write_index = i;
            break;
        }
    }

    if (write_index == -1) {
        // The sector is full, erase it and write to the first position
        flash_range_erase(FLASH_TARGET_ADDRESS, FLASH_SECTOR_SIZE);
        write_index = 0;
    }

    flash_data[write_index] = new_data;

    write_flash_data(flash_data);
}

// Increments the boot count.
void increment_boot_count() {
    flash_data_t current_data = read_last_data();

    if (current_data.boot_count < UINT8_MAX) {
        current_data.boot_count += 1;
        write_new_data(current_data);
    }
}

// Toggles the sound setting.
void flash_toggle_sound() {
    flash_data_t current_data = read_last_data();

    current_data.sound_enabled = !current_data.sound_enabled;

    write_new_data(current_data);
}

// Returns the sound setting.
bool get_sound_status() {
    flash_data_t current_data = read_last_data();

    return current_data.sound_enabled;
}

// Returns the boot count.
uint8_t get_boot_count() {
    flash_data_t current_data = read_last_data();

    return current_data.boot_count;
}
