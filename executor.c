// executor.c
// Implementation for executing commands.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "executor.h"

void execute_pipe(Command *commands, int num_commands) {
    int pipe_fds[2], input_fd = 0, i;
    for (i = 0; i < num_commands; i++) {
        pipe(pipe_fds);

        if (fork() == 0) {
            dup2(input_fd, STDIN_FILENO);
            if (i < num_commands - 1) {
                dup2(pipe_fds[1], STDOUT_FILENO);
            }
            close(pipe_fds[0]);
            execvp(commands[i].name, commands[i].args);
            perror("Execution failed");
            exit(1);
        } else {
            wait(NULL);
            close(pipe_fds[1]);
            input_fd = pipe_fds[0];
        }
    }
}

void execute_command(Command cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (cmd.input_redirect && cmd.input_file) {
            int fd = open(cmd.input_file, O_RDONLY);
            if (fd == -1) {
                perror("Input file error");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
        }

        if (cmd.output_redirect && cmd.output_file) {
            int fd = open(cmd.output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("Output file error");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }

        execvp(cmd.name, cmd.args);
        perror("Execution failed");
        exit(1);
    } else if (pid > 0) {
        if (cmd.is_background) {
            printf("[Background] PID: %d running\n", pid);
        } else {
            int status;
            waitpid(pid, &status, 0);
            printf("Command exited with status: %d\n", WEXITSTATUS(status));
        }
    } else {
        perror("Fork failed");
    }
}
