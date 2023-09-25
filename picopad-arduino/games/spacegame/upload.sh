#!/bin/bash

# Directory to search
DIR="build/PP2"

# Find the .pp2 file
FILE_PATH=$(find $DIR -type f -iname "*.pp2" -print -quit)

# Check if the file was found
if [[ -n $FILE_PATH ]]; then
    python3 tools/upload.py "$FILE_PATH"
else
    echo "No .pp2 file found in $DIR."
fi