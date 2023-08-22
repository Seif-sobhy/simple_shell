#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *user_input, **command_tokens;
	int execution_count = 0, status = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (status)
	{
		execution_count++;
		if (isatty(STDIN_FILENO))
			prompt();
		user_input = _getline();
		if (user_input[0] == '\0')
		{
			continue;
		}
		history(user_input);
		command_tokens = parse_cmd(user_input);
		if (_strcmp(command_tokens[0], "exit") == 0)
		{
			exit_bul(command_tokens, user_input, argv, execution_count);
		}
		else if (is_builtin(command_tokens) == 0)
		{
			st = handle_builtin(command_tokens, st);
			free_all(command_tokens, user_input);
			continue;
		}
		else
		{
			st = check_cmd(command_tokens, user_input, execution_count, argv);
		}
		free_all(command_tokens, user_input);
	}
	return (status);
}

/**
 * is_builtin - Check if a command is a built-in command
 *
 * @cmd: command to check
 * Return: 0 Success, -1 Fail
 */
int is_builtin(char **cmd)
{
	bul_t builtin_functions[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}

	while ((builtin_functions + i)->command)
	{
		if (_strcmp(cmd[0], (builtin_functions + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * creat_environment - Create Array of Environment Variables
 * @envi: Array of Environment Variables
 * Return: Void
 */
void creat_environment(char **envi)
{
	int i = 0;

	while (environ[i])
	{
		envi[i] = _strdup(environ[i]);
		i++;
	}
	envi[i] = NULL;
}
