#include "picopad_pico_info.h"
#include <malloc.h>

extern char __flash_binary_end; // linker symbol pointing to the end of the flash binary
extern char __boot2_start__; // linker symbol pointing to the start of the bootloader
extern char __boot2_end__; // linker symbol pointing to the end of the bootloader
extern char __data_start__; // linker symbol pointing to the start of the data section in RAM
extern char __StackLimit, __bss_end__;

uint32_t get_total_heap(void) {
    return &__StackLimit  - &__bss_end__;
}

uint32_t get_free_heap(void) {
    struct mallinfo m = mallinfo();
    return get_total_heap() - m.uordblks;
}

void get_memory_usage(MemoryUsage* usage) {
    usage->ram_size = (uint32_t)&__bss_end__ - (uint32_t)&__data_start__;
    usage->total_heap = get_total_heap();
    usage->free_heap = get_free_heap();
}

void get_flash_usage(FlashUsage* usage) {
    usage->total_size = PICO_FLASH_SIZE_BYTES;
    usage->bootloader_size = (uint32_t)&__boot2_end__ - (uint32_t)&__boot2_start__;
    usage->app_flash_size = (uint32_t)&__flash_binary_end - (uint32_t)&__boot2_end__;
}

void get_cpu_info(CpuInfo *info) {
    info->clockSpeedHz = clock_get_hz(clk_sys);
    info->chipVersion = rp2040_chip_version();

    pico_unique_board_id_t tempUniqueId;
    pico_get_unique_board_id(&tempUniqueId);
    for (int i = 0; i < PICO_UNIQUE_BOARD_ID_SIZE_BYTES; i++) {
        sprintf(&info->uniqueId[2*i], "%02x", tempUniqueId.id[i]);
    }

    info->runningCore = get_core_num();
    info->totalCores = 2; // RP2040 always has 2 cores
}
