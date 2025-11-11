#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* environ لتعريف execve */
extern char **environ;

/* دوال المساعدة */
ssize_t my_getline(char **lineptr, size_t *n);
char **tokenize(char *line);
int execute(char **args);
void prompt(void);
char *find_path(char *command);
void free_tokens(char **tokens);
void print_env(void);
ssize_t my_getline(char **lineptr, size_t *n);

/* دوال خاصة لتجنب الدوال المحظورة */
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strdup(const char *s);
char *my_strchr(const char *s, int c);

#endif

