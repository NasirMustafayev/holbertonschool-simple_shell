#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main(void)
{
    char *inputline;
    size_t lenght;
    ssize_t readline;
    pid_t pid;
    char *args[2];

    inputline = NULL;
    lenght = 0;

    while(1)
    {
       	if (isatty(STDIN_FILENO))
		    printf("$ ");


        readline = getline(&inputline, &lenght, stdin);

        
        if (readline == -1)
            break;

        if (readline == 1)
            continue;

        inputline[readline - 1] = '\0';

        if (inputline[0] == '\0')
		    continue;

        pid = fork();

        if (pid == 0)
        {
            args[0] = inputline;
            args[1] = NULL;

            execve(inputline, args,  environ);

            perror("./shell");
            exit(1);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror("fork");
        }

    }

    free(inputline);
    return (0);
}
