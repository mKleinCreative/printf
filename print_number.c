#include "holberton.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	unsigned int num = n;
	char neg = '-';
	char digit;

	if (n < 0)
	{
		write(1, &neg, 1);
		num = -num;
	}

	if ((num / 10) > 0)
		print_number(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
}
