#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;
    char *argv[2]; /* argv[0] = command, argv[1] = NULL */

    while (1)
    {
        printf("#cisfun$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            printf("\n");
            break;
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0')
            continue;

        argv[0] = line; /* command */
        argv[1] = NULL;

        pid = fork();
        if (pid == 0)
        {
            execve(argv[0], argv, environ);
            perror("./shell"); /* execve failed */
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("fork");
            free(line);
            exit(EXIT_FAILURE);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    free(line);
    return (0);
}

