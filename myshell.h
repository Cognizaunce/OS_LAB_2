/*
OS - LAB 2
CRN: 74025
GROUP 17
Iqra Zahid - 100824901
Rhea Mathias - 100825543
Rivka Sagi - 100780926
Julian Olano Medina - 100855732
*/

#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>  // Standard I/O functions
#include <stdlib.h> // Standard library functions
#include <string.h> // String handling functions
#include <unistd.h> // POSIX system API

/* Changes the current working directory:
   - Prints the current directory if no argument is given.
   - Updates the PWD environment variable when a path is provided.
   - Displays an error if the directory does not exist. */
void change_directory(char *path);

/* Clears the terminal screen. */
void clear();

/* Lists the contents of the specified directory.
   - If no path is provided, lists the contents of the current directory. */
void directory(char *path);

/* Lists all environment variables. */
void environ_list();  // Renamed to avoid conflict with `environ`

/* Prints the provided argument to the terminal. */
void echo(int size, char **input);

/* Displays the user manual. */
void help();

/* Pauses the shell until the user presses 'Enter'. */
void pause_shell(); // Renamed to avoid conflict with POSIX `pause()`

/* Exits the shell. */
void quit();

#endif // MYSHELL_H
