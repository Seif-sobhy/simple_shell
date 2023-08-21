#include "shell.h"

/**
 * custom_error_print - Print Custom Error
 * @prog_args: Program Arguments
 * @err_count: Error Count
 * @cmd_args: Command Arguments
 * Return: Void
 */
void custom_error_print(char **prog_args, int err_count, char **cmd_args)
{
	char *err_count_str = _itoa(err_count);

	PRINTER(prog_args[0]);
	PRINTER(": ");
	PRINTER(err_count_str);
	PRINTER(": ");
	PRINTER(cmd_args[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd_args[1]);
	PRINTER("\n");

	free(err_count_str);
}
