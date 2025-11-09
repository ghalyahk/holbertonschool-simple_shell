#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    char *cmd_path;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            prompt();

        if (getline(&line, &len, stdin) == -1)
        {
            free(line);
            exit(0);
        }

        args = tokenize(line);
        if (!args || !args[0])
        {
            free_tokens(args);
            continue;
        }

        /* Built-in exit */
        if (strcmp(args[0], "exit") == 0)
        {
            free_tokens(args);
            free(line);
            exit(0);
        }

        cmd_path = find_path(args[0]);

        if (cmd_path == NULL)
        {
            /* اطبع رسالة خطأ مشابهة bash عند PATH فارغ */
            fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
            free_tokens(args);
            continue;
        }

        execute(cmd_path, args);

        free(cmd_path);
        free_tokens(args);
    }

    free(line);
    return 0;
}

