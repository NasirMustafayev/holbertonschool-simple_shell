#include "shell.h"

/**
 * execute_cmd - executes a command
 * @tokens: array of command and arguments
 * @argv: program arguments (for error messages)
 *
 * Return: void
 */
void execute_cmd(char **tokens, char **argv)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		execve(tokens[0], tokens, environ);
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
