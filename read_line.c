#include "shell.h"

/**
 * read_line - reads a line from stdin
 * @lineptr: pointer to line buffer
 * @n: pointer to buffer size
 *
 * Return: number of characters read, or -1 on EOF
 */
ssize_t read_line(char **lineptr, size_t *n)
{
	ssize_t readline;

	readline = getline(lineptr, n, stdin);
	return (readline);
}
