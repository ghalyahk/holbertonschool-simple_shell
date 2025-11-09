#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    ssize_t nread;

    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;

        args = tokenize(line);
        if (args[0] != NULL)
            execute(args);

        free(args);
    }

    free(line);
    return (0);
}

