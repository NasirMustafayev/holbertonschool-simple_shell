#include "shell.h"

/**
 * display_prompt - displays shell prompt in interactive mode
 *
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}
