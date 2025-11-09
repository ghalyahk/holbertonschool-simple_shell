#include "shell.h"

void execute(char *cmd, char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execve(cmd, args, environ);
        perror("execve");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
}

