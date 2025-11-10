#include "shell.h"
#include <stdlib.h>

/* find_path: تبحث عن مسار الأمر في PATH */
char *find_path(char *command)
{
    char **env = environ;
    int i;
    char *copy;

    /* البحث عن PATH في المتغيرات */
    for (i = 0; env[i]; i++)
    {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            break;
    }
    if (!env[i])
        return NULL;

    copy = my_strdup(env[i] + 5);
    if (!copy)
        return NULL;

    /* مؤقتاً: نعيد اسم الأمر نفسه (يمكن تطوير لاحقاً لتقسيم PATH) */
    return my_strdup(command);
}

