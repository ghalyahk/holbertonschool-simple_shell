#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    ssize_t nread;

    while (1)
    {
        /* prompt only if interactive */
        if (isatty(STDIN_FILENO))
            printf("$ ");

        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;

        args = tokenize(line);

        if (args[0] != NULL)
            execute(args);

        free(args);

        /* print prompt again only if interactive */
        /* (DO NOT print prompt in non-interactive mode) */
        /* BUT don't print here; loop will print at top */
    }

    free(line);
    return (0);
}

