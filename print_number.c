#include "holberton.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 * @buffer: A character buffer to store the integer.
 */
void print_number(int n, char *buffer)
{
	int num = n;

	if ((num / 10) > 0)
		print_number((num / 10), buffer - 1);

	*buffer = (num % 10) + '0';
}
