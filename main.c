#include "shell.h"

/**
 * main - Simple shell main loop
 *
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    char **args = NULL;
    int status = 1;

    while (status)
    {
        /* Print prompt ONLY if input is from terminal */
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");

        line = read_line();
        if (!line) /* Ctrl+D */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        args = parse_line(line);
        if (!args)
        {
            free(line);
            continue;
        }

        status = execute(args);

        free(line);
        free(args);
    }

    return (0);
}

