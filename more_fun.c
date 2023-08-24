#include "shell.h"
#include "shell.c"
/**
 * _stcp - Copie Source To Destination Char
 * @dest:Destination
 * @src:Source
 * Return: Copie Of Char *
 */

char *_stcp(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _stct - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */

char *_stct(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	for (; *src != '\0'; src++, dest++)
	{
		*dest = *src;
	}
	*dest = '\0';
	return (s);
}

/**
 * _stchar - Locate Charactere In String
 * @s:String Search In
 * @c:Char To Search For
 * Return: Pointer To Char*
 */

char *_stchar(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);

	return (s);
}

/**
 * _stringcmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */

int _stringcmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
		return (-1);
	for (size_t i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _stdp - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */

char *_stdp(char *str)
{
	size_t len = _stlength(str);
	char *str2 = malloc(sizeof(char) * (len + 1));

	if (!str2)
	{
		return (NULL);
	}

	for (size_t i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
