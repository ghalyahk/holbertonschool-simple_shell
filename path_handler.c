#include "shell.h"

char *get_env_path(void)
{
    int i = 0;

    while (environ[i])
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
            return environ[i] + 5;
        i++;
    }
    return NULL;
}

char *find_path(char *command)
{
    char *path = get_env_path();
    char *copy, *dir, *full;
    int len;

    /* إذا الأمر يحتوي /، نجرب تنفيذه مباشرة */
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)
            return strdup(command);
        return NULL;
    }

    if (!path)
        return NULL;

    copy = strdup(path);
    dir = strtok(copy, ":");

    while (dir)
    {
        len = strlen(dir) + strlen(command) + 2;
        full = malloc(len);
        snprintf(full, len, "%s/%s", dir, command);

        if (access(full, X_OK) == 0)
        {
            free(copy);
            return full;
        }

        free(full);
        dir = strtok(NULL, ":");
    }

    free(copy);
    return NULL;
}

