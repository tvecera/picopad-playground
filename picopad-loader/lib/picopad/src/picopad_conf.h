#if USE_CONFIG

#ifndef PICOPAD_SDK_CONFIG_H
#define PICOPAD_SDK_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#define CONFIG_DATA_SIZE  32    // boot loader resident data

#define CONFIG_FILE "/picopad.cfg"

struct config_data_t {
		u8 brightness;
		u8 volume;
		u8 screen_sleep;
		u8 refresh_battery;
		u8 battery_alarm;
		u8 reserved[21]; // struct padding
		u32 crc;
};
static_assert(sizeof(struct config_data_t) == CONFIG_DATA_SIZE, "configdata must be CONFIG_DATA_SIZE bytes");

struct config_data_t load_config_data();

void save_config_data(struct config_data_t new_config);

void save_volume(uint8_t volume);

void save_brightness(uint8_t brightness);

void load_config_file();

#if USE_SD
void save_config_to_file();
#endif

#ifdef __cplusplus
}
#endif

#endif // PICOPAD_SDK_CONFIG_H

#endif