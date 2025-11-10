#include "shell.h"

int execute(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return (1);

    pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, environ) == -1)
            perror("hsh");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    return (WEXITSTATUS(status));
}

