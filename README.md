## My programs and experiments for [Picopad](https://picopad.eu/cs/index.html) gaming console firmware from [tvecera](https://github.com/tvecera/picopad-playground):

- ### **PyPicoPadImg Generator**

This Python program is designed to generate image arrays compatible with Picopad SDK. It takes an image file as input and 
creates a C array of pixel values, ready to be used in your Picopad SDK software. The program utilizes the 
Run-Length Encoding (RLE) compression technique to reduce the memory footprint of the images.

Please note that this software currently only tested on 8-bit PNG images using a color lookup table (palette).

The code of this generator is based on the original Picopad SDK source code.

**[Link](https://github.com/NetCzech/picopad-playground/tree/848e8973c58df0e720713a50837a7a9e324ac736/tools/PyPicoPadImg)**

- ### **PyConvertLoaderImg**

PyConvertLoaderImg is a Python-based tool that is capable of converting images into 16-bit BMP images. This tool
specifically generates images that are compatible with the Picopad loader application.

The tool reads image files, provides some basic information about them, downsamples the images by reducing the bit depth
of each color channel, and saves the resulting image as a 16-bit BMP file.

**[Link](https://github.com/NetCzech/picopad-playground/tree/848e8973c58df0e720713a50837a7a9e324ac736/tools/PyConvertLoaderImg)**

- ### Picopad TFT Display emulator

This project provides an emulator for the TFT display of Picopad handheld devices. It's designed to assist in the
prototyping and development of applications for Picopad handhelds. With this tool, you can easily prepare and test your
display code using the API of the Picopad SDK.

The code of this emulator is based on the original Picopad SDK source code.

**[Link](https://github.com/NetCzech/picopad-playground/tree/848e8973c58df0e720713a50837a7a9e324ac736/tft-emulator)**

- ### Picopad SDK Pico SDK Fork

Fork of the Picopad SDK, built on the Pico SDK. The goal was to add the capability to use libraries for the Pico SDK 
on the Picopad.

---

[Picopad](https://picopad.eu/cs/index.html) is an open-source gaming console that offers a unique opportunity for young tech enthusiasts. It comes as a kit, allowing children to learn soldering and electronics principles while assembling their own gaming console. Additionally, Picopad supports programming in C, CircuitPython and MicroPython, making it an ideal tool for learning programming skills. With external cards for various educational expansions, Picopad is also a perfect tool for developing STEM (Science, Technology, Engineering, Mathematics) skills.

![Picopad](https://github.com/Pajenicko/Picopad/blob/main/hardware/images/picopad.jpg)

- **GitHub:** [https://github.com/pajenicko/picopad](https://github.com/pajenicko/picopad)
- **www:** [https://picopad.eu/cs/index.html](https://picopad.eu/cs/index.html)
- **Buy:** [https://pajenicko.cz/picopad](https://pajenicko.cz/picopad)
