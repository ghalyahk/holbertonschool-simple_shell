#include "shell.h"

/**
 * tokenize - splits a line into tokens
 * @line: input line from user
 *
 * Return: array of tokens (arguments)
 */
char **tokenize(char *line)
{
	char **args;
	char *token;
	int bufsize = 64, i = 0;

	args = malloc(bufsize * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}

	args[i] = NULL;
	return (args);
}
