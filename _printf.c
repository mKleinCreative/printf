#include "holberton.h"

/**
 * _printf - does wonderful things
 * @format: character string that contains directives of how to print
 * Return: 0 on success
 */

int _printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);

	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%')
		{
			converter(format + ++i)(args);
		} else
		{
			write(1, format + i, 1);
		}
	}
	return (0);
}
