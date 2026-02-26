#include "shell.h"

/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *inputline, *cmd, *tokens[64];
	size_t lenght;
	ssize_t readline;

	(void)argc;
	inputline = NULL;
	lenght = 0;

	while (1)
	{
		display_prompt();

		readline = read_line(&inputline, &lenght);
		if (readline == -1)
			break;

		if (readline == 1)
			continue;

		cmd = trim_line(inputline, &readline);

		if (*cmd == '\0')
			continue;

		parse_tokens(cmd, tokens);
		execute_cmd(tokens, argv);
	}

	free(inputline);
	return (0);
}
