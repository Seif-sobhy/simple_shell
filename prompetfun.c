#include "shell.h"

/**
 * display_shell_prompt - Display Shell Prompt
 */
void display_shell_prompt(void)
{
	PRINTER("$ ");
}

/**
 * error_display - Display Error Based on Command and Loop Count
 * @cmd: Command causing the error
 * @count: Loop count
 * @args: Program arguments
 * Return: Void
 */
void error_display(char *cmd, int count, char **args)
{
	char *er;

	PRINTER(args[0]);
	PRINTER(": ");
	er = _itoa(count);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(cmd);
	PRINTER(": not found\n");
}
