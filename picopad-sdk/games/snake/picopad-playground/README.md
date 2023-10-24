Snake game for [Picopad](https://picopad.eu/cs/index.html) from [pajenicko.cz](https://pajenicko.cz).

Fork from the [Picopad Games](https://github.com/tvecera/picopad-playground/tree/main/picopad-sdk/games), game is for custom bootloader from [Tomáš Večeřa](https://github.com/tvecera/picopad-playground).

Inspired by the Snake game from [Parth Sarthi Sharma](https://parthssharma.github.io).

Thanks [Tomáš Večeřa](https://github.com/tvecera/picopad-playground) for the display fix and corrections in the main code.

---

**:black_cat: NOTICE :black_cat:**

The game is still in development.

---

TO-DO LIST:
- ~~sound for eating food and game over~~
- ~~options to restart and end the game~~
- ~~color in "snake style"~~
- ~~larger snake body~~
- the snake's body is now bigger, it is necessary to fix the bug with the inaccuracy of eating food
- ~~pause the game~~
- ~~score~~

---

**⚠️ WARNING ⚠️**

Please DO NOT directly upload the build to Pico / Picopad. The build is specifically designed for the custom
bootloader, which will load it from the SD card into flash memory behind the main bootloader. You must upload the 
contents of the /build directory to an SD card.

Please note, the build does NOT include a BOOT2 section. Directly uploading the build to the Picopad / Pico will
brick your Pico / Picopad.
