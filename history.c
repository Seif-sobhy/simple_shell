#include "shell.h"

/**
 * custom_history - Fill File By User Input
 * @input: User Input
 * Return: -1 Fail, 0 Success
 */
int custom_history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t file_descriptor, written;
	int input_length = 0;

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);
	if (input)
	{
		while (input[input_length])
			input_length++;
		written = write(file_descriptor, input, input_length);
		if (written < 0)
			return (-1);
	}
	return (1);
}

/**
 * free_environment - Free Environment Variable Array
 * @env: Environment variables.
 * Return: Void
 */
void free_environment(char **env)
{
	int index = 0;

	while (env[index])
	{
		free(env[index]);
		index++;
	}
}
