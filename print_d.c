#include "holberton.h"

/**
 * print_d - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 */
void print_d(const char* format, int spec_len, va_list list)
{
	int d;

	d = va_arg(list, int);
	if (spec_len != 0)
		printf("%s", format);
	print_number(d);
}
