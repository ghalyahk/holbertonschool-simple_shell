#include "shell.h"

char **tokenize(char *line)
{
    char **tokens = malloc(sizeof(char *) * 64);
    char *token;
    int i = 0;

    token = strtok(line, " \t\n");
    while (token)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;

    return tokens;
}

void free_tokens(char **tokens)
{
    int i = 0;
    if (!tokens)
        return;

    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}
