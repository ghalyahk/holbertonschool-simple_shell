#include <stdio.h>
#include <stdlib.h>

/**
 * read_command - Reads a line from stdin
 *
 * Return: pointer to the line (must be freed by caller), or NULL on EOF/error
 */
char *read_command(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("#cisfun$ ");
    nread = getline(&line, &len, stdin);
    if (nread == -1)
    {
        free(line);
        return (NULL);
    }
    if (line[nread - 1] == '\n')
        line[nread - 1] = '\0';
    return (line);
}

