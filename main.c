#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (my_getline(&line, &len) == -1)
			break;
		printf("You typed: %s", line);
	}
	free(line);
	return (0);
}
