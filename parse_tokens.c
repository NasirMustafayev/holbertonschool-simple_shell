#include "shell.h"

/**
 * parse_tokens - splits input into tokens
 * @cmd: input string
 * @tokens: array to store tokens
 *
 * Return: number of tokens
 */
int parse_tokens(char *cmd, char **tokens)
{
	char *token;
	int i;

	i = 0;
	token = strtok(cmd, " \t");

	while (token != NULL && i < 63)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	tokens[i] = NULL;

	return (i);
}
