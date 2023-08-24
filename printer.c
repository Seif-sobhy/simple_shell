#include "shell.h"

/**
 * print_no - Print Unsigned Integer using putchar
 * @num: The unsigned integer to be printed
 * Return: void
 */
void print_no(unsigned int num)
{
	unsigned int remainder = num;

	while (remainder >= 10)
	{
		unsigned int digit = remainder % 10;

		remainder /= 10;
		_putchar(digit + '0');
	}

	_putchar(remainder + '0');
}

/**
 * print_no_in - Print Integers using putchar
 * @num: The integer to be printed
 * Return: void
 */
void print_no_in(int num)
{
	unsigned int absolute_value = num < 0 ? -num : num;

	if (num < 0)
		_putchar('-');

	print_no(absolute_value);

	_putchar('\n');
}
