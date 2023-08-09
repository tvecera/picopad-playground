#!/bin/bash

# Go through each directory in the current directory
for dir in */ ; do
    cd "$dir"

    ./build.sh || exit 1
	
    # Go back to the parent directory
    cd ..
done
