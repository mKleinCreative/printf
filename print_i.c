#include "holberton.h"

/**
 * print_i - Prints an integer.
 * @list: A va_list pointing to the integer to be printed.
 */
void print_i(va_list list)
{
	int i;

	i = va_arg(list, int);

	print_number(i);
}
