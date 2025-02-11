#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void change_directory(char *path) {
    if (path == NULL) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd() error");
        }
    }
    else {
        if (chdir(path) != 0) {
            perror("myshell");
        }
    }

}

void clear(){
    printf("\033[H\033[J"); // ANSI escape sequence to clear screen.
    // (move to top, clear everything in front)
    fflush(stdout); //force the output 
    return 0;
}

void directory(char* path){
    
}