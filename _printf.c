#include "holberton.h"

/**
 * _printf - does wonderful things
 * @format: character string that contains directives of how to print
 * Return: 0 on success
 */

int _printf(const char *format, ...)
{
	int i;

	for (i = 0; *(format + i) != '\0'; i++)
		write(1, format + i, 1);
	return (0);
}
