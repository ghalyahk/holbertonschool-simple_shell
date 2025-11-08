#include "shell.h"

/**
 * main - Simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args = NULL;

	while (1)
	{
		printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		args = parse_line(line);
		if (args == NULL)
			continue;

		if (execute_command(args) == -1)
		{
			free(args);
			break;
		}

		free(args);
	}

	free(line);
	return (0);
}
