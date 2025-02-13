#include "string_acquire.h"
// Include implementation-specific headers here and below.
#include <string.h> // For `size_t` and string functions, part of the C standard library
#include <stdio.h>  // For warning message, part of the C standard library

/*
 * Safely reads a string from a stream, handling buffer overflow and newlines.
 * POSIX, ANSI, and ISO C compliant for compiler agnosticism.
 * Returns: The input string `s`, an empty string (default) or NULL on error based on flag.
 * Inputs:
 * - `s`           The buffer to store the string.
 * - `size`        The size of the buffer.
 * - `stream`      The stream to read from (e.g., stdin).
 * - `return_null` If nonzero, return NULL on error; otherwise, return an empty string.
 */
char* string_acquire(char* s, int size, FILE* stream, int return_null) {
    if (s == NULL || size <= 0 || stream == NULL) {
        fprintf(stderr, "Warning: Invalid input parameters to string_acquire.\n");
        return s;  // Return original pointer so caller handles errors
    }

    if (fgets(s, size, stream) == NULL) {
        if (return_null) return NULL;
        s[0] = '\0';  // Return an empty string instead of NULL
        return s;
    }

    size_t i = strlen(s);
    if (i > 0 && s[i - 1] == '\n') {
        s[i - 1] = '\0';  // Remove newline
    } else {
        // Clear remaining input in buffer using fgetc
        int ch;
        while ((ch = fgetc(stream)) != '\n' && ch != EOF);
    }

    return s;
}