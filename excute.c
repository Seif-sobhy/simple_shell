#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @last_execution_status: Status of the last execution
 * Return: -1 on failure, 0 on success (Return: Execute Builtin)
 */

int handle_builtin(char **cmd, int last_execution_status)
{
	bul_t builtin_commands[] = {
		{"cd", ch_directory},
		{"env", ds_envir},
		{"help", dis_hlp},
		{"echo", echo_bul},
		{"history", history_display},
		{NULL, NULL}
	};
	int index = 0;

	while (builtin_commands[index].command != NULL)
	{
		if (_stcmp(cmd[0], builtin_commands[index].command) == 0)
		{
			return (builtin_commands[index].fun(cmd, last_execution_status));
		}
		index++;
	}
	return (-1);
}

/**
 * check_cmd - Execute Simple Shell Command (Fork, Wait, Execute)
 *
 * @cmd: Parsed Command
 * @user_input: User Input
 * @execution_time: Shell Execution Time, in case of command not found
 * @argv: Program Name
 * Return: 1 if command is NULL, -1 if wrong command, 0 if command executed
 */
int check_cmd(char **cmd, char *user_input, int execution_time, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (strncmp(*cmd, "./", 2) != 0 && strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(*cmd, execution_time, argv);
			free(user_input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}

	wait(&status);
	return (0);
}

/**
 * signal_to_handle - Handle SIGINT (^C)
 * @signal_number: Captured Signal
 * Return: Void
 */
void signal_to_handle(int signal_number)
{
	if (signal_number == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
