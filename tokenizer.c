#include "shell.h"
#include <stdlib.h>

/* tokenize: تقسيم السطر إلى كلمات حسب الفراغ */
char **tokenize(char *line)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char **tokens;
    char *start;

    if (!line)
        return NULL;

    /* عد الكلمات */
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        {
            if (i == 0 || line[i-1] == ' ' || line[i-1] == '\t' || line[i-1] == '\n')
                count++;
        }
        i++;
    }

    tokens = malloc(sizeof(char *) * (count + 1));
    if (!tokens)
        return NULL;

    i = 0;
    j = 0;
    while (line[i])
    {
        while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            i++;
        if (line[i] == '\0')
            break;
        start = &line[i];
        while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            i++;
        line[i] = '\0';
        tokens[j++] = my_strdup(start);
        i++;
    }
    tokens[j] = NULL;
    return tokens;
}

