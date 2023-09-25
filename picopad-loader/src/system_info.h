/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
*
* Portions of this software are derived from the PicoLibSDK:
*   Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
*   Repository: https://github.com/Panda381/PicoLibSDK
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
* Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef PICOPAD_SYSTEM_INFO_H
#define PICOPAD_SYSTEM_INFO_H

#define LOADER_VERSION	"0.51"

#include "pico/unique_id.h"

// Structure to hold memory usage information
typedef struct {
		uint32_t ram_size;
		uint32_t total_heap;
		uint32_t free_heap;
} MemoryUsage;

typedef struct {
		uint32_t total_size;
		uint32_t bootloader_size;
		uint32_t app_flash_size;
} FlashUsage;

typedef struct {
		uint32_t clockSpeedHz;
		uint32_t chipVersion;
		char uniqueId[2 * PICO_UNIQUE_BOARD_ID_SIZE_BYTES + 1];
		uint8_t runningCore;
		uint8_t totalCores;
} CpuInfo;

//__NVIC_GetPendingIRQ
void get_memory_usage(MemoryUsage *usage);

void get_flash_usage(FlashUsage* usage);

void get_cpu_info(CpuInfo *info);

uint8_t show_system_info();

#endif //PICOPAD_SYSTEM_INFO_H
