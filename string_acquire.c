/*
 * Safely reads a string from a stream while handling buffer overflows and newlines.
 *
 * This function reads at most `size - 1` characters from `stream` into `s`, ensuring null termination.
 * Excess characters are discarded to prevent buffer overflows. The newline character, if present, is trimmed.
 *
 * Parameters:
 * - `s`           [char*]  - Pointer to the buffer where the input string is stored.
 * - `size`        [int]    - Maximum number of characters to read, including the null terminator.
 * - `stream`      [FILE*]  - The input stream (e.g., `stdin`).
 * - `return_null` [int]    - If nonzero, returns `NULL` on error; otherwise, returns an empty string.
 *
 * Returns:
 * - On success: Returns `s` containing the input string.
 * - On invalid parameters: Returns the original pointer `s`, allowing the caller to handle errors.
 * - If reading fails: Returns either `NULL` (if `return_null` is set) or an empty string.
 *
 * Behavioural Notes:
 * - Logs a warning to `stderr` if invalid parameters are passed.
 * - Does not log a warning if the provided buffer size is too small, as the caller is responsible for handling this case.
 *
 * Compatibility:
 * - Compliant with ANSI C, ISO C, and POSIX standards.
 */

#include "string_acquire.h" // Include implementation-specific headers below.
#include <string.h> // Provides `size_t` and string functions, part of the C standard library
#include <stdio.h>  // Provides I/O functions, including `fprintf` and `fgets`

 /*
 * Safely reads a string from a stream, handling buffer overflow and newlines:
 *
 *  `Extended documentation is available in the source file.`
 *
 * - On success: Returns `s` containing the input string.
 * - On invalid parameters: Returns the original pointer `s`, allowing the caller to handle errors.
 * - If reading fails: Returns either `NULL` (if `return_null` is set) or an empty string.
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