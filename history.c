#include "shell.h"

/**
 * history - Save User Input to History File
 * @user_input: User Input String
 * Return: -1 on Failure, 0 on Success
 */
int history(char *user_input)
{
	char *history_filename = ".simple_shell_history";
	ssize_t file_descriptor, write_result;
	int input_length = 0;

	if (!history_filename)
		return (-1);

	file_descriptor = open(history_filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);

	if (user_input)
	{
		while (user_input[input_length])
			input_length++;

		write_result = write(file_descriptor, user_input, input_length);
		if (write_result < 0)
			return (-1);
	}

	return (0);
}

/**
 * free_env - Free Environment Variable Array
 * @env_array: Array of Environment Variables
 * Return: Void
 */
void free_env(char **env_array)
{
	int index = 0;

	while (env_array[index])
	{
		free(env_array[index]);
		index++;
	}
}
