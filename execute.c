#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/**
 * execute_command - Forks a child process and executes a command
 * @command: Absolute path of the command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[2];

    if (command == NULL || command[0] == '\0')
        return (-1);

    argv[0] = command;
    argv[1] = NULL;

    pid = fork();
    if (pid == 0)
    {
        execve(argv[0], argv, environ);
        perror("./shell");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork");
        return (-1);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (0);
}

