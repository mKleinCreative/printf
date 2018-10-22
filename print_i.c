#include "holberton.h"

/**
 * print_i - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 * @buffer: A character buffer to store the integer in.
 *
 * Return: The number of characters stored to buffer.
 */
int print_i(va_list list, char *buffer)
{
	int i, i_cpy, digits = 1;

	i = va_arg(list, int);

	if (i < 0)
	{
		*buffer = '-';
		buffer++;
		i = -i;
	}

	i_cpy = i;

	while ((i_cpy / 10) > 0)
	{
		digits++;
		i_cpy /= 10;
	}

	buffer += digits - 1;
	print_number(i, buffer);

	return (digits);
}
