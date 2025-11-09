#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void prompt(void);
char **tokenize(char *line);
void free_tokens(char **tokens);
char *find_path(char *command);
void execute(char *cmd, char **args);

#endif

