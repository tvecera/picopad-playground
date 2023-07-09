// xxd -i rom.gb rom.c

#include <pico/platform.h>
const unsigned char __in_flash("rom") gameRom[] = {
    #include "../../../_make/rom_array_content_only.c"
};