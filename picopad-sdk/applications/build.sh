#!/bin/bash

# Go through each directory in the current directory
for dir in */ ; do
    cd "$dir"

    # Check if 'build' directory exists and delete it
    if [ -d "build" ]; then
        rm -r "build"
    fi

    # Check if 'cmake-build-release' directory exists and delete it
    if [ -d "cmake-build-release" ]; then
        rm -r "cmake-build-release"
    fi

    # Check if 'cmake-build-debug' directory exists and delete it
    if [ -d "cmake-build-debug" ]; then
        rm -r "cmake-build-debug"
    fi

    # Call cmake to generate the build files
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_MAKE_PROGRAM=/Applications/CLion.app/Contents/bin/ninja/mac/ninja \
    -G Ninja \
    -S /Users/ranajkus/devel/pico/picopad-playground/picopad-sdk/applications/"${dir}" \
    -B /Users/ranajkus/devel/pico/picopad-playground/picopad-sdk/applications/"${dir}"/cmake-build-release || exit 1

    # Clean project
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build cmake-build-release --target clean -j 14 || exit 1

    # Build project
    /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build cmake-build-release --target all -j 14 || exit 1

    # Copy the contents of 'build' directory to '../sdcard'
    if [ -d "build" ]; then
        cp -rf build/* ../../sdcard/APPS/
    fi

    # Go back to the parent directory
    cd ..
done
