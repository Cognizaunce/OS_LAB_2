#include "string_acquire.h"
#include <string.h> // Include implementation-specific headers here

/*
 * Safely reads a string from a stream, handling buffer overflow and newlines.
 * POSIX, ANSI, and ISO C compliant for compiler agnosticism.
 * Returns: The input string `s`, or an empty string on error.
 * Inputs:
 * - `s`     The buffer to store the string.
 * - `size`  The size of the buffer.
 * - `stream` The stream to read from (e.g., stdin).      
 */
char* string_acquire(char* s, int size, FILE* stream) {
    if (s == NULL || size <= 0 || stream == NULL) return s;  // Avoid invalid input

    if (fgets(s, size, stream) == NULL) {
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

int main(){

}