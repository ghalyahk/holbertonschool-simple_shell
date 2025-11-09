#include "shell.h"

void execute(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
            perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

