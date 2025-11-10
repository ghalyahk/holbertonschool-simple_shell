#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t read_len;

    while (1)
    {
        write(1, "$ ", 2);

        read_len = _getline(&line, &n);
        if (read_len == -1)
            break;

        /* شيل النيو لاين */
        if (line[read_len - 1] == '\n')
            line[read_len - 1] = '\0';

        /* هنا تفصل التوكنز */
        /* هنا تنفذ الأمر */
    }

    free(line);
    return (0);
}
