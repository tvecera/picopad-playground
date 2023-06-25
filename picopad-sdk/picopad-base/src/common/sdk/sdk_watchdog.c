// ****************************************************************************
//
//                              Watchdog Timer
//
// ****************************************************************************
// Picoino SDK: Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#include "sdk_watchdog.h"
#include "pico/bootrom.h"
#include "hardware/watchdog.h"

void reset_to_bootsel() {
    reset_usb_boot(0, 0);
}

// reset to boot loader
void ResetToBootLoader() {
    watchdog_enable(1, 1);
    while(1);
}