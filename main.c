#include "shell.h"
#include <stdlib.h>

/**
 * main - Entry point for simple_shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *line;

    while (1)
    {
        line = read_command();
        if (line == NULL) /* EOF or error */
            break;

        execute_command(line);
        free(line);
    }

    return (0);
}

