#include "shell.h"

void execute(char *cmd, char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execve(cmd, args, environ);
        perror(args[0]);
        exit(127);
    }
    else if (pid > 0)
    {
        int status;
	wait(&status);
    }
}

