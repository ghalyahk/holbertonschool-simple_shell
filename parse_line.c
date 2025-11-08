#include "shell.h"
#include <stdlib.h>   /* malloc, free, NULL */
#include <string.h>   /* strtok, strlen, strcmp */
#include <stddef.h>   /* NULL أيضا إذا أحببت */

#define TOK_BUFSIZE 64

/**
 * parse_line - splits a line into words (tokens)
 * @line: input string
 *
 * Return: array of strings (tokens), last element NULL
 */
char **parse_line(char *line)
{
    int bufsize = TOK_BUFSIZE, position = 0;
    char **args = malloc(bufsize * sizeof(char *));
    char *token;

    if (!args)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \n\t");
    while (token != NULL)
    {
        args[position++] = token;

        if (position >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            args = realloc(args, bufsize * sizeof(char *));
            if (!args)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \n\t");
    }
    args[position] = NULL;
    return (args);
}

