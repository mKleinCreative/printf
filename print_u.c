#include "holberton.h"
#include <stdio.h>
/**
 * print_u - Converts an unsigned int agument to unsigned decimal.
 * @list: A va_list pointing to the unsigned int to be converted.
 * @buffer: A character buffer to store the result in.
 *
 * Return: The number of characters stored in buffer.
 */
int print_u(va_list list, char *buffer)
{
	int half1_digits = 1, half2_digits = 1;
	unsigned int num, num_half1, num_half2, num_cpy;

	num = va_arg(list, unsigned int);

	num_half1 = num / 10000;
	num_cpy = num_half1;

	while ((num_cpy / 10) > 0)
	{
		half1_digits++;
		num_cpy /= 10;
	}

	buffer += half1_digits - 1;
	print_number(num_half1, buffer);

	num_half2 = num % 10000;
	num_cpy = num_half2;

	while ((num_cpy / 10) > 0)
	{
		half2_digits++;
		num_cpy /= 10;
	}

	buffer += half2_digits;
	print_number(num_half2, buffer);

	return (half1_digits + half2_digits);
}
