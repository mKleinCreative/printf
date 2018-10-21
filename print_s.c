#include "holberton.h"

/**
 * print_s - Prints a string.
 * @list: A va_list pointing to the string to be printed.
 */
void print_s(va_list list)
{
	char *str;
	int index;

	str = va_arg(list, char *);

	for (index = 0; str[index]; index++)
		write(1, str, 1);
}
