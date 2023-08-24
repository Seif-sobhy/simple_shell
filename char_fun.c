#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _stringcopy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_stringcopy(char *dest, char *src, int n)
{
	for (int i = 0; i < n && *(src + i); i++)
	{
		*(dest + i) = *(src + i);
	}
	for (int i = _stlength(src); i < n; i++)
	{
		*(dest + i) = '\0';
	}
	return (dest);
}

/**
 * _stlength - lenght of string
 * @s:char
 * Return:int
 */

int _stlength(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */

int _atoi(char *s)
{
	int i = 0;
	int j, n, x;

	n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}

	for (j = i; (s[j] >= '0') && (s[j] <= '9'); j++)
	{
		n = (n * 10) + x * ((s[j]) - '0');
	}
	return (n);
}

/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

}
