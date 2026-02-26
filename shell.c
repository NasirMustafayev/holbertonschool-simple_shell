#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char *argv[])
{
    char *inputline, *cmd, *token, *tokens[64];
    size_t lenght;
    ssize_t readline;
    pid_t pid;
    int i;

    inputline = NULL;
    lenght = 0;

    (void)argc;

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

        while (readline > 1 && 
               (inputline[readline - 2] == ' ' || 
                inputline[readline - 2] == '\t'))
        {
            readline--;
            inputline[readline - 1] = '\0';
        }

        cmd = inputline;

        while (*cmd == ' ' || *cmd == '\t')
            cmd++;

        if (*cmd == '\0')
            continue;
        
        i = 0;
        token = strtok(cmd, " \t");

        while (token != NULL && i <63)
        {
            tokens[i] = token;
            i++;
            token = strtok(NULL, " \t");
        }
        tokens[i] = NULL;

        pid = fork();

        if (pid == 0)
        {
            execve(tokens[0], tokens,  environ);

            perror(argv[0]);
            exit(1);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror(argv[0]);
        }

    }

    free(inputline);
    return (0);
}
