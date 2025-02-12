#ifndef MYSHELL_H
#define MYSHELL_H
#include <stdio.h> // Standard I/O functions
#include <stdlib.h> // Standard library for functions like malloc
#include <string.h> // String handling functions
#include <unistd.h> // Provides access to the POSIX operating system API

/*Changes the current default directory:
- Report the current directory if no argument is given
- When argument is given, the PWD environment variable should be update
- If the directory does not exist, the the appropiate error should be reported*/
void change_directory(char *path); // declaration of 'cd' function (cd function prototype)
/*Clears the Screen*/
void clear();
/*Lists the content of the path given as an argument*/
void directory(char *path);
/*Lists all Environment Strings*/
void environ();
/*Displays argument on the display followed by a new line*/
void echo(char* input);
/*Displays the user manual*/
void help();
/*Pauses operation of the shell until 'Enter' is pressed*/
void pause();
/*Quits the shell*/
void quit();
#endif