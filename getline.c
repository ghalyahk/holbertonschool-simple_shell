#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 1024

/**
 * _getline - custom getline function
 * @lineptr: pointer where the line will be stored
 * @n: buffer size (not used heavily but kept for compatibility)
 * Return: number of bytes read, or -1 on EOF/error
 */
ssize_t _getline(char **lineptr, size_t *n)
{
    static char buffer[READ_SIZE];
    static ssize_t buf_len;
    static ssize_t buf_pos;

    ssize_t i = 0;
    char *line;
    char c;

    if (lineptr == NULL || n == NULL)
        return (-1);

    /* Allocate line buffer if empty */
    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = malloc(*n);
        if (!*lineptr)
            return (-1);
    }

    line = *lineptr;

    while (1)
    {
        /* If buffer empty → fill it using read() */
        if (buf_pos >= buf_len)
        {
            buf_len = read(STDIN_FILENO, buffer, READ_SIZE);
            buf_pos = 0;

            if (buf_len <= 0) /* EOF */
            {
                if (i == 0)
                    return (-1);
                break;
            }
        }

        c = buffer[buf_pos++];

        /* Resize if needed */
        if (i + 1 >= (ssize_t)*n)
        {
            *n *= 2;
            line = realloc(line, *n);
            if (!line)
                return (-1);
            *lineptr = line;
        }

        line[i++] = c;

        if (c == '\n') /* end of line */
            break;
    }

    line[i] = '\0';
    return (i);
}
