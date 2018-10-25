/*
 * File: _printf.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t output;
	va_list args;
	int i, ret = 0;
	char ch;

	if (format == NULL)
		return (-1);

	init_buffer(&output);
	if (output.buffer == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (convert(format + i + 1) != NULL)
			{
				i++;
				ret += convert(format + i)(args, &output);
				continue;
			}
			if (*(format + i + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}

		ch = *(format + i);
		ret += _memcpy(&output, &ch, 1);
	}

	write(1, output.start, output.len);
	va_end(args);
	free(output.start);

	return (ret);
}
