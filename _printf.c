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
	int i, ret = 0;

	va_start(args, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			i++;

			if (*(format + i) != '%')
			{
				converter(format + i)(args);
				continue;
			}
		}

		write(1, (format + i), 1);
		ret++;
	}

	return (ret);
}
