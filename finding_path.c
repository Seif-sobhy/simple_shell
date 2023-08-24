#include "shell.h"

/**
 * find_executable_in_path - Search For Executable Command in PATH
 * @command: Parsed Input Command
 * Return: 1 on Failure, 0 on Success.
 */
int find_executable_in_path(char **command)
{
	char *path_env, *dir, *command_path;
	struct stat buffer;

	path_env = _getenv("PATH");
	dir = strtok(path_env, ":");
	while (dir != NULL)
	{
		command_path = build(*command, dir);
		if (stat(command_path, &buffer) == 0)
		{
			*command = strdup(command_path);
			free(command_path);
			free(path_env);
			return (0);
		}
		free(command_path);
		dir = strtok(NULL, ":");
	}
	free(path_env);

	return (1);
}

/**
 * build - Build Full Path for Command
 * @command_name: Executable Command Name
 * @directory: Directory Containing Command
 * Return: Parsed Full Path Of Command Or NULL on Failure
 */
char *build(char *command_name, char *directory)
{
	char *full_path;
	size_t length;

	length = strlen(directory) + strlen(command_name) + 2;
	full_path = malloc(sizeof(char) * length);
	if (full_path == NULL)
	{
		return (NULL);
	}

	memset(full_path, 0, length);

	full_path = strcat(full_path, directory);
	full_path = strcat(full_path, "/");
	full_path = strcat(full_path, command_name);

	return (full_path);
}

/**
 * _getenv - Get Value of Environment Variable by Name
 * @variable_name: Environment Variable Name
 * Return: The Value of the Environment Variable, or NULL if not found.
 */
char *_getenv(char *variable_name)
{
	size_t name_length, value_length;
	char *variable_value;
	int i = 0, x, j;

	name_length = strlen(variable_name);
	while (environ[i])
	{
		if (strncmp(variable_name, environ[i], name_length) == 0)
		{
			value_length = strlen(environ[i]) - name_length;
			variable_value = malloc(sizeof(char) * value_length);
			if (!variable_value)
			{
				free(variable_value);
				perror("unable to allocate");
				return (NULL);
			}

			j = 0;
			x = name_length + 1;
			while (environ[i][x])
			{
				variable_value[j] = environ[i][x];
				x++;
				j++;
			}
			variable_value[j] = '\0';

			return (variable_value);
		}
		i++;
	}

	return (NULL);
}
