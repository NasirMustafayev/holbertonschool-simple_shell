#include "shell.h"
/**
 * execute_cmd - executes a command
 * @tokens: array of command and arguments
 * @argv: program arguments (for error messages)
 * Return: void
 */
void execute_cmd(char **tokens, char **argv)
{
	char *cmd_path;
	pid_t pid;
	int status;

	if (!tokens || !tokens[0])
		return;

	/* Find the command first */
	cmd_path = find_in_path(tokens[0]);

	/* If not found, print error and DON'T fork */
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
		last_status = 127;
		return;  /* Exit without forking */
	}

	/* Command exists, now fork */
	pid = fork();

	if (pid == 0)
	{
		execve(cmd_path, tokens, environ);
		perror(argv[0]);
		exit(127);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))  /* Add these lines */
			last_status = WEXITSTATUS(status);
	}
	else
	{
		perror(argv[0]);
		last_status = 1;
	}
}
