#include "shell.h"
#include <stdlib.h>
#include <unistd.h>  /* isatty */
#include <stdio.h>   /* printf */

int main(void)
{
    char *line;

    while (1)
    {
        /* اطبع الـ prompt فقط إذا stdin من terminal */
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");

        line = read_command();
        if (line == NULL) /* EOF أو خطأ */
            break;

        execute_command(line);
        free(line);
    }

    return (0);
}

