#include "holberton.h"

/**
 * print_b - Converts an unsigned int argument to binary.
 * @list: A va_list pointing to the int to be converted.
 * @buffer: A character buffer to store the result in.
 *
 * Return: The number of digits stored to buffer.
 */
int print_b(va_list list, char *buffer)
{
	unsigned int num, num_cpy, digits = 1;

	num = va_arg(list, unsigned int);
	num_cpy = num;

	while (num_cpy / 2)
	{
		digits++;
		num_cpy /= 2;
	}

	buffer += digits - 1;

	while (num / 2)
	{
		*buffer = (num % 2) + '0';
		buffer--;
		num /= 2;
	}

	*buffer = (num % 2) + '0';

	return (digits);
}
