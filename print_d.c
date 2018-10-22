#include "holberton.h"

/**
 * print_d - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 * @buffer: A character buffer storing the overall string to print.
 *
 * Return: The number of characters stored to buffer.
 */
int print_d(va_list list, char *buffer)
{
	int d, d_cpy, digits = 1;

	d = va_arg(list, int);

	if (d < 0)
	{
		*buffer = '-';
		digits++;
		d = -d;
	}

	d_cpy = d;

	while ((d_cpy / 10) > 0)
	{
		digits++;
		d_cpy /= 10;
	}

	buffer += digits - 1;
	print_number(d, buffer);

	return (digits);
}
