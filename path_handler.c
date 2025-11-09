#include "shell.h"

char *find_path(char *command)
{
    char *path_env = getenv("PATH");
    char *path, *dir;
    char full_path[1024];

    if (!path_env)
        return NULL;

    /* إذا كان الأمر فيه / يعتبر path جاهز */
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)
            return strdup(command);
        else
            return NULL;
    }

    path = strdup(path_env);
    dir = strtok(path, ":");

    while (dir)
    {
        sprintf(full_path, "%s/%s", dir, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path);
            return strdup(full_path);
        }

        dir = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}
