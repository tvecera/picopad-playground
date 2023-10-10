/**
* MIT License
*
* Copyright (c) 2023 Tomas Vecera, tomas@vecera.dev
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
* Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* NOTICE FOR DERIVED CODE:
*  Throughout this file, sections marked with the comment "Derived from PicoLibSDK" are based on or derived from the
*  PicoLibSDK by Miroslav Nemecek. The original work can be found at:
*  Copyright (c) 2023 Miroslav Nemecek, Panda38@seznam.cz, hardyplotter2@gmail.com
*  Repository: https://github.com/Panda381/PicoLibSDK
*/

#ifndef BINARY_UPLOAD_H
#define BINARY_UPLOAD_H

#define COL_BIGINFOFG  COL_LTORANGE  // big info text foreground color
#define COL_BIGINFOBG  COL_BLACK  // big info text background color

// Function to flash binary content received from a serial connection.
uint8_t flash_binary_serial();

// Function to flash an application file from storage to memory.
uint8_t flash_file(char *path, char *filename, bool to_ram, int *size);

// Open boot sel dialog
uint8_t show_bootsel_dialog();

// Function to display an error message and waits for a key to be pressed.
uint8_t disp_error_page(uint8_t code);

#endif //BINARY_UPLOAD_H
