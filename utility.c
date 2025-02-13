/*
OS - LAB 2
CRN: 74025
GROUP 17
Iqra Zahid - 100824901
Rhea Mathias - 100825543
Rivka Sagi - 100780926
Julian Olano Medina - 100855732
*/
    
#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// Change to a specific directory, or if unspecified, print current directory 
void change_directory(char *path) {
    if (path == NULL) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd() error");
        }
    } else {
        if (chdir(path) != 0) {
            perror("myshell");
        }
    }
}

// Clear terminal
void clear() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear screen
    fflush(stdout);
}

// List the contents of a directory
void directory(char* path) {
    DIR *dir;
    struct dirent *entry;

    if (path == NULL) {
        path = "."; // Default to current directory
    }

    dir = opendir(path);
    if (dir == NULL) {
        perror("myshell: Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

// Print list of environment variables in the terminal
void environ_list() {
    system("env");
}

// Print a sentence to the screen
void echo(char *sentence) {
    if (sentence) {
        printf("%s\n", sentence);
    }
}

// View the user manual
void help() {
    if (system("more -d manual.txt") != 0) {
        system("cat manual.txt"); // Fallback for non-Linux systems
    }
}

// Pause execution of the shell until Enter is pressed
void pause_shell() {
    printf("Pausing shell, press Enter key to continue...\n");
    while (getchar() != '\n');
    printf("Welcome back!\n");
}

// Terminate the shell
void quit() {
    printf("Exiting myShell\n");
    exit(0);
}
