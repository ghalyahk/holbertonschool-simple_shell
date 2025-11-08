#include "shell.h"

/**
 * execute_command - Execute a command
 * @args: command + arguments
 *
 * Return: 0 on success, -1 on exit
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (0);

	/* Built-in exit */
	if (strcmp(args[0], "exit") == 0)
		return (-1);

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
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

	return (0);
}
