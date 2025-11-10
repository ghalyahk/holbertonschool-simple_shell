#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t read_len;
    char **args;
    int last_status = 0;

    while (1)
    {
        prompt();

        read_len = _getline(&line, &n);
        if (read_len == -1)
            break;

        if (line[read_len - 1] == '\n')
            line[read_len - 1] = '\0';

        args = tokenize(line);
        if (!args)
            continue;

        /* تنفيذ الأمر */
        last_status = execute(args);

        free_tokens(args);
    }

    free(line);
    return (0);
}

