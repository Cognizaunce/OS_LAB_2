#include "myshell.h"

void execute_external_command(char *input) {
    pid_t pid;
    int status;
    char *args[100]; // Array to hold command arguments
    char *token;
    char *delim = " \n";
    int i = 0;
    
    token = strtok(input, delim);
    while (token != NULL && i < 99) {
        args[i++] = token;
        token = strtok(NULL, delim);
    }
    args[i] = NULL;
    
    if (args[0] == NULL) {
        return; // No command entered
    }
    
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    }
    
    if (pid == 0) { // Child process
        setenv("parent", getenv("SHELL"), 1); // Set parent environment variable
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    } else { // Parent process
        waitpid(pid, &status, 0);
    }
}

void execute_command(char *input) {
    char *token;
    char *delim = " \n";
    token = strtok(input, delim);
    if (token != NULL) {
        if (strcasecmp(token, "cd") == 0) {
            token = strtok(NULL, delim);
            change_directory(token);
        } else if (strcasecmp(token, "clr") == 0) {
            clear();
        } else if (strcasecmp(token, "dir") == 0) {
            token = strtok(NULL, delim);
            directory(token);
        } else if (strcasecmp(token, "environ") == 0) {
            environment_variables();
        } else if (strcasecmp(token, "echo") == 0) {
            token = strtok(NULL, delim);
            echo(token);
        } else if (strcasecmp(token, "help") == 0) {
            token = strtok(NULL, delim);
            help(token);
        } else if (strcasecmp(token, "pause") == 0) {
            token = strtok(NULL, delim);
            pause(token);
        } else if (strcasecmp(token, "quit") == 0) {
            quit();
        } else {
            execute_external_command(input); // Handle external commands
        }
    }
}

int main() {
    char input[1024];
    setenv("SHELL", "/bin/myshell", 1); // Set shell environment variable
    
    while (1) {
        printf("MyShell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }
        execute_command(input);
    }
    return 0;
}
