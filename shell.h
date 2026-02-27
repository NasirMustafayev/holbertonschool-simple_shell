#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
extern int last_status;

void display_prompt(void);
ssize_t read_line(char **lineptr, size_t *n);
char *trim_line(char *inputline, ssize_t *readline);
int parse_tokens(char *cmd, char **tokens);
void execute_cmd(char **tokens, char **argv);
char *find_in_path(char *command);

#endif
