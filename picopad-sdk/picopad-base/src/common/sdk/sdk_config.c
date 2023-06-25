#include "sdk_config.h"
#include "pico/printf.h"
#include "lib_crc.h"
#include "lib_fat.h"
#include "lib_sd.h"
#include <string.h>

#define CONFIG_SIZE_WITHOUT_CRC 26

struct config_data_t __attribute__((section(".configdata"))) config_data;

char cr[1] = { CH_CR };
char volumeTxt[8 + 1];
char brightnessTxt[12 + 1];
char buff[21];
sFile cfgFile;
u32 i;

struct config_data_t load_config_data() {
    // Calculate CRC for the data, excluding the stored CRC itself
    uint32_t calculated_crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);

    // Check if the calculated CRC matches the stored one
    if (calculated_crc == config_data.crc) {
        return config_data;
    } else {
        // If the CRCs don't match, return a config_data_t with default values
        struct config_data_t default_config = {DEFAULT_BRIGHTNESS, DEFAULT_VOLUME, {0}, 0};
        default_config.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);

        return default_config;
    }
}

void save_config_data(struct config_data_t new_config) {
    // Set the new values, excluding the CRC
    config_data.brightness = new_config.brightness;
    config_data.volume = new_config.volume;
    memcpy(config_data.reserved, new_config.reserved, sizeof(config_data.reserved));

    // Calculate and store the new CRC
    config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
}

void save_volume(uint8_t volume) {
    // Update the volume field
    config_data.volume = volume;

    // Recalculate the CRC because the data changed
    config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
    save_config_to_file();
}

void save_brightness(uint8_t brightness) {
    // Update the brightness field
    config_data.brightness = brightness;

    // Recalculate the CRC because the data changed
    config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
    save_config_to_file();
}

void save_config_to_file() {
    if (FileOpen(&cfgFile, CONFIG_FILE)) {
        snprintf(volumeTxt, 9, "volume %u", config_data.volume);
        snprintf(brightnessTxt, 13, "brightness %u", config_data.brightness);

        strcpy(buff, volumeTxt);
        strcat(buff, cr);
        strcat(buff, brightnessTxt);

        FileWrite(&cfgFile, buff, 21);
        FileClose(&cfgFile);
    }
}

void load_config_from_sd_card() {
    struct config_data_t default_config = {DEFAULT_BRIGHTNESS, DEFAULT_VOLUME, {0}, 0};

    if (DiskMount()) {
        if (FileOpen(&cfgFile, CONFIG_FILE)) {
            // Load volume
            i = FileRead(&cfgFile, buff, 9);
            if (i == 9) {
                u8 volume = buff[7] - '0';
                if (volume >= 0 && volume <= 5)
                    default_config.volume = volume;
            }
            // Load brightness
            i = FileRead(&cfgFile, buff, 12);
            if (i == 12) {
                u8 brightness = buff[11] - '0';
                if (brightness >= 0 && brightness <= 5)
                    default_config.brightness = brightness;
            }
            FileClose(&cfgFile);
        }
    }

    save_config_data(default_config);
}