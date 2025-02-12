#include "myshell.h"

void execute_command(char *input) {
    char *token;
    char *delim = " \n";
    token = strtok(input, delim);
    if (token != NULL) {
        if (strncasecmp(token, "cd") == 0) { //cd
            token = strtok(NULL, delim); // Get next part (directory path)
            change_directory(token);
        } else if (strncasecmp(token, "clr")== 0){ //clr
            clear();
        } else if(strncasecmp(token, "dir") == 0){ // dir
            token = strtok(NULL, delim);
            directory(token);
        } else if(strncasecmp(token, "environ") == 0){ //environ
            environment_variables();
        } else if(strncasecmp(token, "echo") == 0){ //echo
            token = strtok(NULL, delim);
            echo(token);
        } else if(strncasecmp(token, "help") ==0){ // help
            token = strtok(NULL, delim);
            help(token);
        } else if (strncasecmp(token, "pause") == 0){ // pause
            token = strtok(NULL, delim);
            pause(token);
        }else if (strncasecmp(token, "quit") == 0){ // quit
            quit();
        }
        else {
        printf("Command not recognized.\n");
        }
    }
}

/*A function to safely extract user input, used for all processes*/
static char* get_input(){

}

int main() {
char input[1024]; // Buffer for user input
while (1) {
    printf("MyShell> ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        break; // Exit on EOF
    }
    execute_command(input); // Process the input
}
return 0;
}