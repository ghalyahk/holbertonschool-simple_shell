#include "shell.h"
#include <unistd.h>

/* my_getline */
ssize_t my_getline(char **lineptr, size_t *n)
{
    static char buffer[1024];
    static ssize_t buf_pos = 0, buf_len = 0;
    ssize_t i = 0;
    char *buf = *lineptr;

    if (!buf)
    {
        *n = 1024;
        buf = malloc(*n);
        if (!buf)
            return (-1);
        *lineptr = buf;
    }

    while (1)
    {
        if (buf_pos >= buf_len)
        {
            buf_len = read(STDIN_FILENO, buffer, 1024);
            if (buf_len <= 0)
                return (-1);
            buf_pos = 0;
        }
        buf[i] = buffer[buf_pos++];
        if (buf[i] == '\n')
        {
            buf[i + 1] = '\0';
            return i + 1;
        }
        i++;
        if (i >= *n - 1)
        {
            *n *= 2;
            buf = realloc(buf, *n);
            if (!buf)
                return (-1);
            *lineptr = buf;
        }
    }
}

/* my_strcmp */
int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/* my_strncmp */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    for (i = 0; i < n && s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    if (i < n)
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    return 0;
}

/* my_strdup */
char *my_strdup(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    char *copy = malloc(len + 1);
    if (!copy)
        return NULL;
    for (size_t i = 0; i <= len; i++)
        copy[i] = s[i];
    return copy;
}

/* my_strchr */
char *my_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == 0)
        return (char *)s;
    return NULL;
}
