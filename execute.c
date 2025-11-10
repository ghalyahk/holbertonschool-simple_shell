#include "shell.h"

/**
 * execute - creates a child process to execute a command
 * @cmd: command path
 * @args: command arguments
 */
void execute(char *cmd, char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		
		execve(cmd, args, environ);
		perror(args[0]);
		exit(127);
	}
	else
	{
		
		wait(&status);
	}
}
