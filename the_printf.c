#include "holberton.h"

/**
 * _printf - does wonderful things
 * @format: Character string to print - may contain directives.
 *
 * Return: 0 on success
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;

	va_start(args, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			i++;
			converter(format + i)(args);
		}
		else
		{
			write(1, (format + i), 1);
		}
	}

	return (0);
}
