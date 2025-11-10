#ifndef SHELL_H
#define SHELL_H

/* ===== LIBRARIES YOU MUST INCLUDE ===== */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* لازم نكتب التصريح الخاص بـ environ */
extern char **environ;

/* prototypes */
ssize_t _getline(char **lineptr, size_t *n);
char **tokenize(char *line);
void execute(char **args);
void prompt(void);
char *find_path(char *command);

#endif

