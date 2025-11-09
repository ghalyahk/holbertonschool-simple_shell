#include "shell.h"

/**
 * execute - executes a command by searching in PATH
 * @args: array of arguments
 *
 * Return: 1 on success, 0 on failure
 */
int execute(char **args)
{
	char *path, *path_copy, *dir;
	char full_path[1024];
	struct stat st;

	if (args[0] == NULL)
		return (1);


	if (strchr(args[0], '/'))
	{
		if (stat(args[0], &st) == 0)
			return (run_command(args[0], args));
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (0);
		}
	}


	path = getenv("PATH");
	if (!path)
		return (0);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[0]);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (run_command(full_path, args));
		}
		dir = strtok(NULL, ":");
	}

	fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	free(path_copy);
	return (0);
}

/**
 * run_command - runs the command in a new process
 * @path: path to the command
 * @args: arguments array
 *
 * Return: 1 always
 */
int run_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
