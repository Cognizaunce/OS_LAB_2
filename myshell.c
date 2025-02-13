#include "myshell.h"
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *input) {
    char *args[100]; // Array to store command arguments
    char *token;
    char *delim = " \n";
    int i = 0;

    token = strtok(input, delim);
    if (token == NULL) return;

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, delim);
    }
    args[i] = NULL; // NULL-terminate the argument list

    // Built-in commands
    if (strcasecmp(args[0], "cd") == 0) {
        change_directory(args[1]);
    } else if (strcasecmp(args[0], "clr") == 0) {
        clear();
    } else if (strcasecmp(args[0], "dir") == 0) {
        directory(args[1]);
    } else if (strcasecmp(args[0], "environ") == 0) {
        environment_variables();
    } else if (strcasecmp(args[0], "echo") == 0) {
        echo(args[1]);
    } else if (strcasecmp(args[0], "help") == 0) {
        help();
    } else if (strcasecmp(args[0], "pause") == 0) {
        pause();
    } else if (strcasecmp(args[0], "quit") == 0) {
        quit();
    } else {
        // External commands using fork() and execvp()
        pid_t pid = fork();
        if (pid == 0) { // Child process
            if (execvp(args[0], args) == -1) {
                perror("myshell");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("myshell: Fork failed");
        } else { // Parent process
            wait(NULL); // Wait for the child process to finish
        }
    }
}

void execute_batch_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("myshell: Unable to open batch file");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        execute_command(line);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    char input[1024];

    // Batch Mode: If a file is provided as an argument, execute its commands
    if (argc == 2) {
        execute_batch_file(argv[1]);
        return 0;
    }

    // Interactive Mode
    while (1) {
        printf("MyShell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }
        execute_command(input);
    }
    return 0;
}
