#include "shell.h"
/**
 * find_in_path - finds the full path of a command
 * @command: the command to find
 *
 * Return: full path if found, NULL if not found
 */
 /**
 * get_path_from_environ - gets PATH from environ
 *
 * Return: PATH value or NULL
 */
char *get_path_from_environ(void)
{
	int i;
	char *path;

	if (!environ)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;  /* Skip "PATH=" */
			return (path);
		}
	}

	return (NULL);
}
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
	path = get_path_from_environ();
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
