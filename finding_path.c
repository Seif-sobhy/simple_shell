#include "shell.h"

/**
 * search_path - Search In $PATH For Executable Command
 * @command: Parsed Input
 * Return: 1 for Failure, 0 for Success.
 */
int search_path(char **command)
{
	char *path, *dir, *command_path;
	struct stat buffer;

	path = get_env("PATH");
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		command_path = build_path(*command, dir);
		if (stat(command_path, &buffer) == 0)
		{
			*command = strdup(command_path);
			free(command_path);
			free(path);
			return (0);
		}
		free(command_path);
		dir = strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * build_path - Build Command Path
 * @command: Executable Command
 * @dir: Directory Containing Command
 * Return: Parsed Full Path Of Command Or NULL In Case Of Failure
 */
char *build_path(char *command, char *dir)
{
	char *path;
	size_t len;

	len = strlen(dir) + strlen(command) + 2;
	path = (char *)malloc(sizeof(char) * len);
	if (path == NULL)
	{
		return (NULL);
	}

	memset(path, 0, len);

	strcat(path, dir);
	strcat(path, "/");
	strcat(path, command);

	return (path);
}

/**
 * get_env - Gets The Value Of Environment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *get_env(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, x, j;

	name_len = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(name, environ[i], name_len) == 0)
		{
			value_len = strlen(environ[i]) - name_len;
			value = (char *)malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = name_len + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
