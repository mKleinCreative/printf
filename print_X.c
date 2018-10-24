#include "holberton.h"

/**
 * print_X - Converts an unsigned int argument to hex, using ABCDEF.
 * @list: A va_list pointing to the int to be converted.
 * @buffer: A character buffer to store the result in.
 *
 * Return: The number of digits stored to the buffer.
 */
int print_X(va_list list, char *buffer)
{
	unsigned int num, num_cpy, digits = 1;

	num = va_arg(list, unsigned int);
	num_cpy = num;

	while (num_cpy / 16)
	{
		digits++;
		num_cpy /= 16;
	}

	buffer += digits - 1;

	while (num / 16)
	{
		if ((num % 16) < 10)
			*buffer = (num % 16) + 48;
		else
			*buffer = (num % 16) + 55;

		buffer--;
		num /= 16;
	}

	if ((num % 16) <  10)
		*buffer = (num % 16) + 48;
	else
		*buffer = (num % 16) + 55;

	return (digits);
}
