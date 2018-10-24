#include "holberton.h"

/**
 * print_di - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 * @buffer: A character buffer storing the overall string to print.
 *
 * Return: The number of characters stored to buffer.
 */
int print_di(va_list list, char *buffer)
{
	int d, d_cpy, digits = 1;

	d = va_arg(list, int);

	if (d < 0)
	{
		*buffer = '-';
		digits++;

		if (d == -2147483648)
		{
			*(buffer + 1) = '2';
			digits++;
			d = 147483648;
		}
		else
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
