// command_parser.h
// Header file for command parsing functionality.

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

typedef struct Command {
    char *name;
    char **args;
    int is_background;
    int input_redirect;
    char *input_file;
    int output_redirect;
    char *output_file;
    int is_pipe;
    struct Command *piped_commands;
    int num_piped_commands;
} Command;

// Parse user input into a command structure
Command parse_command(const char *input);

// Free allocated memory for a command structure
void free_command(Command cmd);

#endif
