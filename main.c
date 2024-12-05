// main.c
// Entry point for the custom shell application.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "command_parser.h"
#include "executor.h"

#define MAX_INPUT 1024

// Display the shell prompt
void display_prompt() {
    printf("> ");
    fflush(stdout);
}

int main() {
    char input[MAX_INPUT];
    display_prompt();
    
    while (fgets(input, MAX_INPUT, stdin)) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Exit if the user enters "quit"
        if (strcmp(input, "quit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // Parse the user input into a command structure
        Command cmd = parse_command(input);
        if (cmd.is_pipe) {
            // Handle piped commands
            execute_pipe(cmd.piped_commands, cmd.num_piped_commands);
        } else {
            // Execute a single command
            execute_command(cmd);
        }

        // Free allocated memory for the command
        free_command(cmd);
        display_prompt();
    }
    return 0;
}
