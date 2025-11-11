#include "shell.h"

/**
 * my_getline - reads a line from stdin
 * @lineptr: pointer to store the read line
 * @n: pointer to the size of the allocated buffer
 * Return: number of characters read (including '\n'), or -1 on EOF/error
 */
ssize_t my_getline(char **lineptr, size_t *n)
{
	static char buffer[1024];
	static size_t pos, len;
	ssize_t count = 0;
	char *new_line = NULL;
	char c;

	if (!lineptr || !n)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = 1024;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	while (1)
	{
		if (pos >= len)
		{
			len = read(STDIN_FILENO, buffer, sizeof(buffer));
			pos = 0;
			if (len <= 0)
				return (count > 0 ? count : -1);
		}

		c = buffer[pos++];
		(*lineptr)[count++] = c;

		if ((size_t)(count + 1) >= *n)
		{
			*n *= 2;
			new_line = realloc(*lineptr, *n);
			if (!new_line)
				return (-1);
			*lineptr = new_line;
		}

		if (c == '\n')
			break;
	}

	(*lineptr)[count] = '\0';
	return (count);
}
