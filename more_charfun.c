#include "shell.h"

/**
 * _stcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */

int _stcmp(char *s1, char *s2)
{
	int cmp = 0, i = 0, len1, len2;

	len1 = _stlength(s1);
	len2 = _stlength(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			i++;
	}
	return (cmp);
}

/**
 * _isalphabet - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */

int _isalphabet(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlength(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	for (; n / 10; i++)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
	}
	s[i] = (n % 10) + '0';
	arr_rv(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 *  arr_rv - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
 */

void arr_rv(char *arr, int len)
{
	for (int i = 0; i < (len / 2); i++)
	{
		char tmp = arr[i];

		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlength - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */

int intlength(int num)
{
	int len = 0;

	for (; num != 0; len++)
	{
		num /= 10;
	}
	return (len);
}
