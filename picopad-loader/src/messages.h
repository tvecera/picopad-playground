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
*/

#ifndef MESSAGES_H
#define MESSAGES_H

#define RESULT_CODE_LIST \
    RESULT(OK,                     "No error", "") \
    RESULT(CANCEL,                 "User Canceled", "") \
    RESULT(ERROR_LARGE_FILE,       "File too large!", "Resize & retry") \
    RESULT(ERROR_SERIAL_TIMEOUT,   "Serial", "Timeout!") \
    RESULT(ERROR_OPEN_FILE,        "Can't open", "file!") \
    RESULT(ERROR_ERASE_FLASH,      "Failed to", "erase flash") \
    RESULT(ERROR_FLASH_PROGRAM,    "Failed to", "load file") \
    RESULT(ERROR_INVALID_CRC,      "CRC doesn't", "match!") \
    RESULT(ERROR_INVALID_SEQUENCE, "Invalid start", "sequence!")

enum {
#define RESULT(e, m1, m2) RESULT_##e,
		RESULT_CODE_LIST
#undef  RESULT
		RESULT_UNKNOWN
};

typedef struct {
		int code;
		const char *name;
		const char *message;
		const char *message_two;
} result_t;

result_t get_result_detail(int code);

#endif //MESSAGES_H
