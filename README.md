# Picopad Playground

**Clone repository**

```bash
  git clone https://github.com/tvecera/picopad-playground
```

## PyPicoPadImg Generator

This Python program is designed to generate image arrays compatible with Picopad SDK. It takes an image file as input and 
creates a C array of pixel values, ready to be used in your Picopad SDK software. The program utilizes the 
Run-Length Encoding (RLE) compression technique to reduce the memory footprint of the images.

Please note that this software currently only tested on 8-bit PNG images using a color lookup table (palette).

The code of this generator is based on the original Picopad SDK source code.

[Link](./tools/PyPicoPadImg)

## PyConvertLoaderImg

PyConvertLoaderImg is a Python-based tool that is capable of converting images into 16-bit BMP images. This tool
specifically generates images that are compatible with the Picopad loader application.

The tool reads image files, provides some basic information about them, downsamples the images by reducing the bit depth
of each color channel, and saves the resulting image as a 16-bit BMP file.

[Link](./tools/PyConvertLoaderImg)

## PyRaspPicoSnd

PyRaspPicoSnd is a Python utility designed to convert audio files into a C++ array format suitable for the Picopad
SDK. The audio is processed to match a specific format: PCM, mono, 8-bit unsigned, with a sample rate of 22050Hz. This
ensures compatibility and optimal playback on the Picopad handheld devices. The tool requires `ffmpeg` for audio format
decoding.

The generated `.c` output contains the audio data in a compact C++ array format, ready for direct integration into
your Picopad SDK software projects.

[Link](./tools/PyRaspPicoSnd)

## Picopad TFT Display emulator

This project provides an emulator for the TFT display of Picopad handheld devices. It's designed to assist in the
prototyping and development of applications for Picopad handhelds. With this tool, you can easily prepare and test your
display code using the API of the Picopad SDK.

The code of this emulator is based on the original Picopad SDK source code.

[Link](./tools/tft-emulator)

## Custom Picopad Loader

Fork of the Picopad SDK, built on the Pico SDK. The goal was to add the capability to use libraries for the Pico SDK
on the Picopad.

[Link](./picopad-loader)

## Links

- Picopad from Pajenicko e-shop
- [Picopad](https://github.com/Pajenicko/Picopad)
- [PicoLibSDK](https://github.com/Panda381/PicoLibSDK)
