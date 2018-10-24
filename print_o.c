#include "holberton.h"

/**
 * print_o - Converts an unsigned int argument to octal.
 * @list: A va_list pointing to the int to be converted.
 * @buffer: A character buffer to store the result in.
 *
 * Return: The number of digits stored to buffer.
 */
int print_o(va_list list, char *buffer)
{
	unsigned int num, num_cpy, digits = 1;

	num = va_arg(list, unsigned int);
	num_cpy = num;

	while (num_cpy / 8)
	{
		digits++;
		num_cpy /= 8;
	}

	buffer += digits - 1;

	while (num / 8)
	{
		*buffer = (num % 8) + '0';
		buffer--;
		num /= 8;
	}

	*buffer = (num % 8) + '0';

	return (digits);
}
