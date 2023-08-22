#include "shell.h"

/**
 * _getline - Read Input From Standard Input
 * Return: Input String
 */
char *_getline()
{
	int index = 0, buffer_size = BUFSIZE, read_result;
	char current_char = 0;
	char *input_buffer = malloc(buffer_size);

	if (input_buffer == NULL)
	{
		free(input_buffer);
		return (NULL);
	}

	while (current_char != EOF && current_char != '\n')
	{
		fflush(stdin);
		read_result = read(STDIN_FILENO, &current_char, 1);
		if (read_result == 0)
		{
			free(input_buffer);
			exit(EXIT_SUCCESS);
		}
		input_buffer[index] = current_char;
		if (input_buffer[0] == '\n')
		{
			free(input_buffer);
			return ("\0");
		}
		if (index >= buffer_size)
		{
			input_buffer = _realloc(input_buffer, buffer_size, buffer_size + 1);
			if (input_buffer == NULL)
			{
				return (NULL);
			}
		}
		index++;
	}
	input_buffer[index] = '\0';
	hashtag_handle(input_buffer);
	return (input_buffer);
}

/**
 * hashtag_handle - Remove characters after #
 * @buffer: Input buffer
 * Return: void
 */
void hashtag_handle(char *buffer)
{
	int index = 0;

	while (buffer[index] != '\0')
	{
		if (buffer[index] == '#')
		{
			buffer[index] = '\0';
			break;
		}
		index++;
	}
}
