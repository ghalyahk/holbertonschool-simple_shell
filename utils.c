#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/* my_strdup: نسخ سلسلة */
char *my_strdup(const char *s)
{
    int len = 0;
    int i;
    char *copy;

    while (s[len])
        len++;

    copy = malloc(len + 1);
    if (!copy)
        return NULL;

    for (i = 0; i <= len; i++)
        copy[i] = s[i];

    return copy;
}

/* my_strcmp: مقارنة سلسلتين */
int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/* my_strncmp: مقارنة n حروف من سلسلتين */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;
    for (i = 0; i < (int)n && s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    if (i < (int)n)
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    return 0;
}

/* my_strchr: البحث عن حرف في سلسلة */
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

/* free_tokens: تحرير مصفوفة من السلاسل */
void free_tokens(char **tokens)
{
    int i;

    if (!tokens)
        return;

    for (i = 0; tokens[i]; i++)
        free(tokens[i]);

    free(tokens);
}

