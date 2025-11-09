#include "shell.h"

char **tokenize(char *line)
{
    char **args = malloc(64 * sizeof(char *));
    char *token;
    int i = 0;

    token = strtok(line, " \n");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    return args;
}
