# Picopad GameBoy Emulator

This is a GameBoy emulator for the Picopad, based on the Peanut-GB project. The result of the build is a `.PP2` file
that can be uploaded to Picopad via custom bootloader. Please note that the sound is not functional.

Experimental "FULL" GameBoy Color support is available. To enable this, change ```PEANUT_FULL_GBC_SUPPORT 0``` to
```PEANUT_FULL_GBC_SUPPORT 1``` in the main.cpp file.

## Prerequisites

Ensure you have `xxd` installed on your machine. This utility is used for hex dumps and is typically available in
Unix-like operating systems.

## Building the ROM

1. First, a GameBoy (GB) ROM is required. The GB ROM should be contained in the file `./src/rom.c`. This is necessary
   for the compilation.

2. To generate this file, use `xxd` utility as follows:
    ```bash
    xxd -i rom.gb > rom.c
    ```
   This command will convert the binary contents of `rom.gb` into a C array and output it to `rom.c`.

3. The content of the C array must then be copied to the `__in_flash("rom") gameRom[]` array.

## Keys

| Gameboy | Picopad |
|---------|---------|
| RIGHT   | RIGHT   |
| UP      | UP      |
| LEFT    | LEFT    |
| DOWN    | DOWN    |
| A       | A       |
| B       | B       |
| START   | X       |
| SELECT  | Y       |
| QUIT    | A + B   |

## Credits

This project is based on the following works:

- [RP2040-GB](https://github.com/deltabeard/RP2040-GB)
- [Pico-GB](https://github.com/YouMakeTech/Pico-GB/tree/master)

**⚠️ WARNING ⚠️**

This is an alpha version. Any modifications or changes to your Picopad are made at your own risk.

This repository contains a fork of the Picopad SDK, built on the Pico SDK. The goal was to add the capability to use
libraries for the Pico SDK on the Picopad. The project is divided into three parts:
