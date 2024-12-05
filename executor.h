// executor.h
// Header file for command execution functionality.

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "command_parser.h"

// Execute a single command
void execute_command(Command cmd);

// Execute a pipeline of commands
void execute_pipe(Command *commands, int num_commands);

#endif
