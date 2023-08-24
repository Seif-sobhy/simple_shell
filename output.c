#include "shell.h"

/**
 * _prerror - Print Custom Error
 * @program_name: Program Name
 * @error_count: Error Count
 * @command: Command
 * Return: Void
 */
void _prerror(char **program_name, int error_count, char **command)
{
	char *error_count_str = _itoa(error_count);

	PRINTER(program_name[0]);
	PRINTER(": ");
	PRINTER(error_count_str);
	PRINTER(": ");
	PRINTER(command[0]);
	PRINTER(": Illegal number: ");
	PRINTER(command[1]);
	PRINTER("\n");

	free(error_count_str);
}
