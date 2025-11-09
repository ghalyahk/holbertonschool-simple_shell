#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char *read_line(void);
char **tokenize(char *line);
int execute(char **args);
int run_command(char *path, char **args);

#endif

