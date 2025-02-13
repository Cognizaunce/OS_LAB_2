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

//view the user manual to the terminal screen for the user to view
void help(){
    char command[1024] = "more -d manual.txt";
    system(command);    
}

//pause execution of the shell until certain input is detected
void pause(){
    char *pause;
    printf("pausing shell, press enter key to return to normal execution\n");
   
    while(1){
        scanf("%c", pause);
        if(*pause == '\n'){
            break;
        }
    }

    printf("welcome back!\n");

}

//terminate the shell
void quit(){
    printf("exiting myShell\n");
    exit(0);
}
