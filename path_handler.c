#include "shell.h"
#include <stdlib.h>

char *find_path(char *command)
{
    /* افترض أن PATH موجود في env */
    char **env = environ;
    int i = 0;
    char *copy, *dir;

    while (env[i])
    {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            break;
        i++;
    }
    if (!env[i])
        return NULL;

    copy = my_strdup(env[i] + 5);
    if (!copy)
        return NULL;

    dir = copy; /* لاحقًا يمكن تقسيم باستخدام دالة tokenize خاصة بـ ':' */
    /* هذا مثال مبسط */
    return my_strdup(command); /* مؤقت */
}

