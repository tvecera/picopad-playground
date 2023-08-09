#include "picopad.h"

#if USE_CONFIG

#include "pico/printf.h"

#define CONFIG_SIZE_WITHOUT_CRC 26

struct config_data_t __attribute__((section(".configdata"))) config_data;

char cr[1] = {CH_CR};
char volumeTxt[8 + 1];
char brightnessTxt[12 + 1];
char screenSleepTxt[14 + 1];
char refreshBatteryTxt[17 + 1];
char batteryAlarmTxt[15 + 1];
char buff[54];
#if USE_SD
sFile cfgFile;
#endif
u32 i;

struct config_data_t get_default_config_data() {
	struct config_data_t default_config = {
			DEFAULT_BRIGHTNESS,
			DEFAULT_VOLUME,
			DEFAULT_SCREEN_SLEEP,
			DEFAULT_REFRESH_BATTERY,
			DEFAULT_BATTERY_ALARM,
			{0},
			0
	};

	return default_config;
}

struct config_data_t load_config_data() {
	// Calculate CRC for the data, excluding the stored CRC itself
	uint32_t calculated_crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);

	// Check if the calculated CRC matches the stored one
	if (calculated_crc == config_data.crc) {
		return config_data;
	} else {
		// If the CRCs don't match, return a config_data_t with default values
		struct config_data_t default_config = get_default_config_data();
		default_config.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);

		return default_config;
	}
}

void save_config_data(struct config_data_t new_config) {
	// Set the new values, excluding the CRC
	config_data.brightness = new_config.brightness;
	config_data.volume = new_config.volume;
	config_data.screen_sleep = new_config.screen_sleep;
	config_data.refresh_battery = new_config.refresh_battery;
	config_data.battery_alarm = new_config.battery_alarm;
	memcpy(config_data.reserved, new_config.reserved, sizeof(config_data.reserved));

	// Calculate and store the new CRC
	config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
}

void save_volume(uint8_t volume) {
	// Update the volume field
	config_data.volume = volume;

	// Recalculate the CRC because the data changed
	config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
#if USE_SD
	save_config_to_file();
#endif
}

void save_brightness(uint8_t brightness) {
	// Update the brightness field
	config_data.brightness = brightness;

	// Recalculate the CRC because the data changed
	config_data.crc = Crc32ADMA(&config_data, CONFIG_SIZE_WITHOUT_CRC);
#if USE_SD
	save_config_to_file();
#endif
}

#if USE_SD
void save_config_to_file() {
	if (DiskMount()) {
		if (!FileExist(CONFIG_FILE)) {
			FileCreate(&cfgFile, CONFIG_FILE);
			FileClose(&cfgFile);
		}
		if (FileOpen(&cfgFile, CONFIG_FILE)) {
			snprintf(volumeTxt, 9, "volume %u", config_data.volume);
			snprintf(brightnessTxt, 13, "brightness %u", config_data.brightness);
			snprintf(screenSleepTxt, 15, "screen_sleep %u", config_data.screen_sleep);
			snprintf(refreshBatteryTxt, 18, "refresh_battery %u", config_data.refresh_battery);
			snprintf(batteryAlarmTxt, 16, "battery_alarm %u", config_data.battery_alarm);

			strcpy(buff, volumeTxt);
			strcat(buff, cr);
			strcat(buff, brightnessTxt);
			strcat(buff, cr);
			strcat(buff, screenSleepTxt);
			strcat(buff, cr);
			strcat(buff, refreshBatteryTxt);
			strcat(buff, cr);
			strcat(buff, batteryAlarmTxt);

			FileWrite(&cfgFile, buff, 70);
			FileClose(&cfgFile);
		}
	}
}
#endif

void load_config_file() {
	struct config_data_t default_config = get_default_config_data();

#if USE_SD
	if (DiskMount()) {
		if (!FileExist(CONFIG_FILE)) {
			FileCreate(&cfgFile, CONFIG_FILE);
			FileClose(&cfgFile);
		}
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
			// Screen sleep
			i = FileRead(&cfgFile, buff, 14);
			if (i == 14) {
				u8 screen_sleep = buff[13] - '0';
				if (screen_sleep >= 0 && screen_sleep <= 9)
					default_config.screen_sleep = screen_sleep;
			}
			// Refresh battery status
			i = FileRead(&cfgFile, buff, 17);
			if (i == 17) {
				u8 refresh_battery = buff[16] - '0';
				if (refresh_battery >= 0 && refresh_battery <= 9)
					default_config.refresh_battery = refresh_battery;
			}
			// Battery alarm ON/OFF
			i = FileRead(&cfgFile, buff, 15);
			if (i == 15) {
				u8 battery_alarm = buff[14] - '0';
				if (battery_alarm >= 0 && battery_alarm <= 1)
					default_config.battery_alarm = battery_alarm;
			}
			FileClose(&cfgFile);
		}
	}
#endif

	save_config_data(default_config);
}

#endif
