#ifndef PICOPAD_PICO_INFO_H
#define PICOPAD_PICO_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pico.h"
#include "hardware/clocks.h"
#include "pico/unique_id.h"
#include "pico/multicore.h"
#include "pico/printf.h"

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

#ifdef __cplusplus
}
#endif

#endif // PICOPAD_PICO_INFO_H