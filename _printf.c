#include "holberton.h"

/**
 * _printf - does wonderful things
 * @format: Character string to print - may contain directives.
 *
 * Return: 0 on success
 */
char checker(char *ch)
{
	switch (*ch)
	{
		case 'c':
			print_c(pos, spec_len, args);
			continue;
		case 'i':
		case 'd':
			print_d(pos, spec_len, args);
			continue;
		case 's':
			print_s(pos, spec_len, args);
			continue;
	}
}
int _printf(const char *format, ...)
{
	va_list args;
	char current = format[0];
	int i, last, ret = 0;

	if (format == NULL)
		return (0);
	va_start(args, format);
	for (i = 0; current != '\0'; i++, current = format[i])
	{
		if (current == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				++i;
				continue;
			}
			for (last = i; format[last] != ' ' && format[last] != '\0'; ++last)
			{
				const char *pos = &format[i + 1];
				int spec_len = last - i;

				i = last - 1;
				checker(format[last - 1], spec_len, args);
			}
		}
		write(1, &current, 1);
		++ret;
	}

	return (ret);
}
