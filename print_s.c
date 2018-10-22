#include "holberton.h"

/**
 * print_s - Prints a string.
 * @list: A va_list pointing to the string to be printed.
 */
void print_s(va_list list)
{
	char *str;
	int i;

	str = va_arg(list, char *);
	if (!str)
		exit(1);
	for (i = 0; *(str + i); i++)
		write(1, (str + i), 1);
}
