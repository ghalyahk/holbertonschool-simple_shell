#include "shell.h"

/**
 * read_line - reads a line from stdin
 *
 * Return: pointer to the line read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		else
		{
			perror("getline");
			free(line);
			exit(1);
		}
	}
	return (line);
}
