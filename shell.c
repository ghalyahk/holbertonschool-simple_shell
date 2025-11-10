#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	char *cmd_path;
	int last_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(last_status);
		}

		args = tokenize(line);
		if (!args || !args[0])
		{
			free_tokens(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			free_tokens(args);
			free(line);
			exit(last_status);
		}

		if (strcmp(args[0], "env") == 0)
		{
			print_env();
			free_tokens(args);
			continue;
		}

		cmd_path = find_path(args[0]);

		if (cmd_path == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			free_tokens(args);
			free(line);
			exit(127);
		}

		last_status = execute(cmd_path, args);

		free(cmd_path);
		free_tokens(args);
	}

	free(line);
	return (0);
}
