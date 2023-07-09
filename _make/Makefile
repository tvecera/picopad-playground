all:	pico-sdk game

apt:
	sudo apt update
	sudo apt install -y git cmake xxd gcc-arm-none-eabi g++ build-essential

clean:
	rm -rf _tmp

pico-sdk:
	mkdir -p _tmp
	if [ ! -d _tmp/pico-sdk ]; then git clone https://github.com/raspberrypi/pico-sdk.git _tmp/pico-sdk; (cd _tmp/pico-sdk && git submodule update --init); fi

rom:
	@if [ ! -f rom.gb ]; then echo "\n\nCopy your ROM file (<name>.gb) into the _make/ subfolder as 'rom.gb' first!\n\n"; /bin/false; fi
	xxd -i rom.gb rom_full.c
	cat rom_full.c  |sed -e 's/unsigned .*//' |sed -e 's/};//' >rom_array_content_only.c

##include <pico/platform.h>
#const unsigned char __in_flash("rom") gameRom[] = {};

game: pico-sdk rom
	(cd ../picopad-sdk/picopad-gb && cmake .)
	(cd ../picopad-sdk/picopad-gb && cmake --build .)
	@echo "\n\nGame content should now be in the ./picopad-sdk/build/PICOPAD-GB.PP2\n\n"

