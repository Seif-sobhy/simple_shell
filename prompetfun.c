#include "shell.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}

/**
 * print_error - Display Error Based on Command and Loop Count
 * @user_input: User Input
 * @loop_counter: Simple Shell Loop Count
 * @program_name: Program Name
 * Return: Void
 */
void print_error(char *user_input, int loop_counter, char **program_name)
{
	char *error_message;

	PRINTER(program_name[0]);
	PRINTER(": ");
	error_message = _itoa(loop_counter);
	PRINTER(error_message);
	free(error_message);
	PRINTER(": ");
	PRINTER(user_input);
	PRINTER(": not found\n");
}
