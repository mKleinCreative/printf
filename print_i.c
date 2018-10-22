#include "holberton.h"

/**
 * print_i - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 */
void print_i(const char* format, int spec_len, va_list args)
{
	int i;

	i = va_arg(args, int);
	if (spec_len != 0)
		printf("%s", format);
	print_number(i);
}
