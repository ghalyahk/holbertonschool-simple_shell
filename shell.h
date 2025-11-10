#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* environ لازم لتعريف execve */
extern char **environ;

/* بروتوتايب الدوال */
ssize_t _getline(char **lineptr, size_t *n);
char **tokenize(char *line);
int execute(char **args);
void prompt(void);
char *find_path(char *command);
void free_tokens(char **tokens);
void print_env(void);

#endif

