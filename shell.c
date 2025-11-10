#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            prompt();

        if (my_getline(&line, &len) == -1)
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

        if (my_strcmp(args[0], "exit") == 0)
        {
            free_tokens(args);
            free(line);
            exit(0);
        }

        if (my_strcmp(args[0], "env") == 0)
        {
            print_env();
            free_tokens(args);
            continue;
        }

        if (find_path(args[0]) == NULL)
        {
            fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
            free_tokens(args);
            free(line);
            exit(127);
        }

        execute(args);

        free_tokens(args);
    }

    free(line);
    return (0);
}

