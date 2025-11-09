#include "shell.h"

/**
 * main - simple shell loop
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
	
		if (isatty(STDIN_FILENO))
			printf("$ ");

		line = read_line();
		args = tokenize(line);

		if (args[0] != NULL)
			execute(args);

		free(line);
		free(args);
	}

	return (0);
}

