#include "shell.h"
/**
 * find_in_path - finds the full path of a command
 * @command: the command to find
 *
 * Return: full path if found, NULL if not found
 */
char *find_in_path(char *command)
{
	char *path, *path_copy, *dir;
	static char full_path[1024];

	if (!command || command[0] == '\0')
		return (NULL);

	/* If command has /, use it as-is */
	if (strchr(command, '/'))
		return (command);

	/* Get the PATH */
	path = getenv("PATH");
	if (!path)
		return (NULL);

	/* Make a copy because strtok modifies it */
	path_copy = strdup(path);

	/* Searcing throught each directory */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		sprintf(full_path, "%s/%s", dir, command);
		
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
