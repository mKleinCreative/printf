#include "holberton.h"

/**
 * print_c - Prints a character.
 * @list: A va_list pointing to the character to print.
 *
 * Return: function pointer to function matched by symbol
 */
void print_c(const char* format, int spec_len, va_list args)
{
	char ch;

	ch = va_arg(args, int);
	if (!ch)
		exit(1);
	if (spec_len != 0)
		printf("%s", format);
	write(1, &ch, 1);
}
