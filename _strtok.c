#include "shell.h"

/**
 * check_diff - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */

unsigned int check_diff(char c, const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}

	return (0);
}

/**
 * _stringtoken - Token A String Into Token (strtrok)
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */

char *_stringtoken(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i = 0;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	while (ts[i] != '\0')
	{
		if (check_diff(ts[i], delim) == 0)
			break;
		i++;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	i = 0;

	while (nt[i] != '\0')
	{
		if (check_diff(nt[i], delim) == 1)
			break;
		i++;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
	}
