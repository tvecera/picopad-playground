#!/bin/bash

# Get the current directory
CURRENT_DIR=$(pwd)

# Display information about the directory at the start
echo "Starting the update process for directory: $CURRENT_DIR"

# Backup the user_config.h file
cp lib/picopad/include/user_config.h user_config.h.bak

# Delete specified directories
rm -rf lib/picopad lib/no-OS-FatFS-SD-SPI-RPi-Pico tools patches

# Delete specified files
rm -f upload.sh build.sh

# Copy specified directories from ../../../picopad-loader
cp -r ../../../picopad-loader/lib/picopad lib/
cp -r ../../../picopad-loader/lib/no-OS-FatFS-SD-SPI-RPi-Pico lib/
cp -r ../../../picopad-loader/tools .
cp -r ../../../picopad-loader/patches .

# Copy specified files from ../../../picopad-loader
cp ../../../picopad-loader/tools/upload.sh .
cp ../../../picopad-loader/build.sh .
cp ../../../picopad-loader/tools/update_libs.sh .

# Restore the user_config.h file from the backup
cp user_config.h.bak lib/picopad/include/user_config.h

# Delete specified files
rm tools/upload.sh
rm tools/update_libs.sh
rm patches/memmap_default_bootloader.ld
rm tools/copy_loader_build.py
rm tools/patch_loader_memmap.py

# Delete the backup of user_config.h
rm user_config.h.bak

./build.sh

# Display completion message with the directory name
echo "Update complete for directory: $CURRENT_DIR!"
