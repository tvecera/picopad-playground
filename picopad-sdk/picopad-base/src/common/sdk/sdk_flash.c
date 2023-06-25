// ****************************************************************************
//
//                                Flash memory
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "sdk_flash.h"
#include "lib_crc.h"
#include "hardware/flash.h"
#include "hardware/sync.h"

// check boot 2 crc code, if it is valid
Bool NOINLINE Boot2Check()
{
	u32 crc = Crc32ASlow(Boot2, BOOT2_SIZE_BYTES-4);
	return crc == Boot2[BOOT2_SIZE_BYTES/4-1];
}

// erase flash memory
//  addr = start address to erase (offset from start of flash XIP_BASE; must be aligned to 4 KB FLASH_SECTOR_SIZE)
//  count = number of bytes to erase (must be multiple of 4 KB FLASH_SECTOR_SIZE)
// If core 1 is running, lockout it or reset it!
Bool NOFLASH(FlashErase)(u32 addr, u32 count)
{
	// check boot 2 loader (this function can be run from Flash memory)
	Bool ok = Boot2Check();

    if ((addr < ERASE_ADDR_MIN) || (addr + count >= FLASH_ADDR_MAX)) {
        // Outside flash
        return false;
    }

    if ((addr & (FLASH_SECTOR_SIZE - 1)) || (count & (FLASH_SECTOR_SIZE - 1))) {
        // Must be aligned
        return false;
    }

    uint32_t uirq_status = save_and_disable_interrupts();

    flash_range_erase(addr, count);

    restore_interrupts(uirq_status);

    return true;
}

// program flash memory
//  addr = start address to program (offset from start of flash XIP_BASE; must be aligned to 256 B FLASH_PAGE_SIZE)
//  data = pointer to source data to program (must be in RAM)
//  count = number of bytes to program (must be multiple of 256 B FLASH_PAGE_SIZE)
// If core 1 is running, lockout it or reset it!
Bool NOFLASH(FlashProgram)(u32 addr, const u8* data, u32 count)
{
	// check boot 2 loader (this function can be run from Flash memory)
	Bool ok = Boot2Check();

    if ((addr < WRITE_ADDR_MIN) || (addr + count >= FLASH_ADDR_MAX)) {
        // Outside flash
        return false;
    }

    if ((addr & (FLASH_PAGE_SIZE - 1)) || (count & (FLASH_PAGE_SIZE -1))) {
        // Must be aligned
        return false;
    }

    if (count > MAX_DATA_LEN) {
        return false;
    }

    uint32_t uirq_status = save_and_disable_interrupts();

    flash_range_program(addr, data, count);

    restore_interrupts(uirq_status);

    return true;
}
