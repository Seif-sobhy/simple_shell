#include "shell.h"

/**
 * ex_bl - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
 */

void ex_bl(char **cmd, char *input, char **argv, int c)
{
	int statue;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	for (int i = 0; cmd[1][i]; i++)
	{
		if (_isalphabet(cmd[1][i]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

/**
 * ch_directory - Change Dirctorie
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */

int ch_directory(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_stcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * ds_envir - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */

int ds_envir(__attribute__((unused))char **cmd, __attribute__((unused))int er)
{
	size_t i = 0;
	int len;

	while (environ[i] != NULL)
	{
		len = _stlength(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * dis_hlp - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */

int dis_hlp(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}

	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * echo_bul - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */

int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();
	size_t i = 0;

	if (_stringcmp(cmd[1], "$?", 2) == 0)
	{
		print_no_in(st);
		PRINTER("\n");
	}
	else if (_stringcmp(cmd[1], "$$", 2) == 0)
	{
		print_no(pid);
		PRINTER("\n");
	}
	else if (_stringcmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
	{
		for (; cmd[1][i];)
		{
			if (_isalphabet(cmd[1][i++]) != 0)
			{
				break;
			}
		}
	}
	return (1);
}
