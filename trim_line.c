#include "shell.h"

/**
 * trim_line - removes leading and trailing whitespace
 * @inputline: input line
 * @readline: pointer to line length
 *
 * Return: pointer to trimmed string
 */
char *trim_line(char *inputline, ssize_t *readline)
{
	char *cmd;

	if (*readline > 0 && inputline[*readline - 1] == '\n')
	{
		inputline[*readline - 1] = '\0';
		(*readline)--;
	}

	while (*readline > 1 &&
		   (inputline[*readline - 2] == ' ' ||
			inputline[*readline - 2] == '\t'))
	{
		(*readline)--;
		inputline[*readline - 1] = '\0';
	}

	cmd = inputline;
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;

	return (cmd);
}
