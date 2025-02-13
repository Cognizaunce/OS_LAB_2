#ifndef STRING_ACQUIRE_H
#define STRING_ACQUIRE_H

#include <stdio.h>  // Only include what's necessary for the interface (FILE*)

// Function prototype
char* string_acquire(char* s, int size, FILE* stream);

#endif // STRING_UTILS_H