#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    char *cmd_path;

    while (1)
    {
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

        cmd_path = find_path(args[0]);

        if (cmd_path == NULL)
        {
            perror("Command not found");
            free_tokens(args);
            continue;   /* لا نسوي fork */
        }

        execute(cmd_path, args);

        free(cmd_path);
        free_tokens(args);
    }

    free(line);
    return 0;
}

