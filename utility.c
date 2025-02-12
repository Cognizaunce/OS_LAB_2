#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//change to a specific directory, or if unspecified print current directory 
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

//clear terminal
void clear(){
    printf("\033[H\033[J"); // ANSI escape sequence to clear screen.
    // (move to top, clear everything in front)
    fflush(stdout); //force the output 
    return 0;
}

//list the contents of directory
void directory(char* path){
    //if no path is specified then list the contents of current directory
    if(path == NULL) {
        system("ls");
    }else{
        //if path is specified then list the contents of specified path
        char command[1024] = "ls ";
        strcat(command, path);
        system(command);
    }
}

// print list of environment variables in the terminal
void environment_variables(){
    system("env");

}

//print something to the screen
void echo(char *sentence){
    char command[1024] = "echo ";
    strcat(command, sentence);
    strcat(command, "\n");
    system(command);
}

//print the manual 
void help(){
    char command[1024] = "more -d manual.txt";
    system(command);    
}


void pause(char *path){

}


void quit(){

}