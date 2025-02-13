#ifndef STRING_ACQUIRE_H
#define STRING_ACQUIRE_H
// Below, only include the headers necessary to interface with the `string_acquire` function
#include <stdio.h>  // For `FILE*`, part of the C standard library

// Function prototype
char* string_acquire(char* s, int size, FILE* stream);

#endif // STRING_ACQUIRE_H