// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

// ****************************************************************************
//
//                                CRC Check Sum
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz

#include "lib_crc.h"
#include "hardware/dma.h"

// Calculate CRC-32 Normal (CRC32A), buffer - slow version
u32 Crc32ABufSlow(u32 crc, const void *buf, int len) {
    const u8 *s = (const u8 *) buf;
    int i;

    for (; len > 0; len--) {
        crc ^= (u32) *s++ << 24;
        for (i = 8; i > 0; i--) {
            if ((crc & 0x80000000) == 0)
                crc <<= 1;
            else
                crc = (crc << 1) ^ CRC32A_POLY;
        }
    }
    return crc;
}

// Calculate CRC-32 Normal (CRC32A) - slow version
//   Calculation speed: 790 us per 1 KB
u32 Crc32ASlow(const void *buf, int len) {
    return Crc32ABufSlow(CRC32A_INIT, buf, len);
}

// Calculate CRC-32 Normal (CRC32A) - DMA version (uses DMA_TEMP_CHAN() temporary channel)
//   Calculation speed: 2 us per 1 KB
// Can be used simultaneously in both CPUs, but not simultaneously in an interrupt.
u32 Crc32ADMA(const void *ptr, int len) {
    uint32_t dummy_dest, crc;

    int channel = dma_claim_unused_channel(true);
    dma_channel_config c = dma_channel_get_default_config(channel);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
    channel_config_set_read_increment(&c, true);
    channel_config_set_write_increment(&c, false);
    channel_config_set_sniff_enable(&c, true);

    // Seed the CRC calculation
    dma_hw->sniff_data = 0xffffffff;

    // Mode 1, then bit-reverse the result gives the same result as
    // golang's IEEE802.3 implementation
    dma_sniffer_enable(channel, 0x1, true);
    dma_hw->sniff_ctrl |= DMA_SNIFF_CTRL_OUT_REV_BITS;

    dma_channel_configure(channel, &c, &dummy_dest, ptr, len / 4, true);

    dma_channel_wait_for_finish_blocking(channel);

    // Read the result before resetting
    crc = dma_hw->sniff_data ^ 0xffffffff;

    dma_sniffer_disable();
    dma_channel_unclaim(channel);

    return crc;
}
