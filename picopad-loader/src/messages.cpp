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

#include "include.h"

// Generate an array of error names
const char *RESULT_NAMES[] = {
#define RESULT(e, m1, m2) #e,
		RESULT_CODE_LIST
#undef  RESULT
		"UNKNOWN"
};

// Generate an array of error messages
const char *RESULT_MESSAGES_ONE[] = {
#define RESULT(e, m1, m2) m1,
		RESULT_CODE_LIST
#undef  RESULT
		"Unknown error"
};

// Generate an array of error messages
const char *RESULT_MESSAGES_TWO[] = {
#define RESULT(e, m1, m2) m2,
		RESULT_CODE_LIST
#undef  RESULT
		"Unknown error"
};

result_t get_result_detail(int code) {
	result_t result;
	if (code < 0 || code > RESULT_UNKNOWN) {
		result.code = -1;
		result.name = "INVALID";
		result.message = "Invalid error code";
	} else {
		result.code = code;
		result.name = RESULT_NAMES[code];
		result.message = RESULT_MESSAGES_ONE[code];
		result.message_two = RESULT_MESSAGES_TWO[code];
	}
	return result;
}
