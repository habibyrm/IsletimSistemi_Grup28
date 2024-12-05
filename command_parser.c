// command_parser.c
// Implementation for parsing user input into commands.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_parser.h"

Command parse_command(const char *input) {
    Command cmd = {0};
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, " ");
    
    // Command name
    cmd.name = strdup(token);
    cmd.args = malloc(sizeof(char *) * 10); // Maximum 10 arguments
    int i = 0;

    while (token != NULL) {
        if (strcmp(token, "|") == 0) {
            cmd.is_pipe = 1;
            break;
        } else if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " ");
            cmd.input_redirect = 1;
            cmd.input_file = strdup(token);
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            cmd.output_redirect = 1;
            cmd.output_file = strdup(token);
        } else if (strcmp(token, "&") == 0) {
            cmd.is_background = 1;
        } else {
            cmd.args[i++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }
    cmd.args[i] = NULL;

    if (cmd.is_pipe) {
        cmd.piped_commands = malloc(sizeof(Command) * 10); // Max 10 commands in a pipe
        char *input_copy = strdup(input); // input'un bir kopyasını oluştur
        char *pipe_segment = strtok(input_copy, "|"); // strtok'u kopya üzerinde çalıştır
        int j = 0;
        while (pipe_segment != NULL) {
            cmd.piped_commands[j++] = parse_command(pipe_segment);
            pipe_segment = strtok(NULL, "|");
        }
        cmd.num_piped_commands = j;
    }

    free(input_copy);
    return cmd;
}

void free_command(Command cmd) {
    free(cmd.name);
    for (int i = 0; cmd.args[i] != NULL; i++) {
        free(cmd.args[i]);
    }
    free(cmd.args);
    if (cmd.input_file) free(cmd.input_file);
    if (cmd.output_file) free(cmd.output_file);
    if (cmd.is_pipe) {
        for (int i = 0; i < cmd.num_piped_commands; i++) {
            free_command(cmd.piped_commands[i]);
        }
        free(cmd.piped_commands);
    }
}