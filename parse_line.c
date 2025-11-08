#include "shell.h"

/**
 * parse_line - Split line into arguments
 * @line: input command
 *
 * Return: array of strings
 */
char **parse_line(char *line)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
		return (NULL);

	token = strtok(line, " \n\t");
	while (token)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}

	args[i] = NULL;
	return (args);
}
