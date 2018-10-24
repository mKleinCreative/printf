#include "holberton.h"

/**
 * _printf - does wonderful things
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of character printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *buffer, *buffer_ptr;
	int i, percents = 0, ret, len = 0, add = 0;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL || format == NULL)
		return (-1);
	buffer_ptr = buffer;

	va_start(args, format);
	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			percents++;
			if (converter(format + i + 1))
			{
				i++;
				add = converter(format + i)(args, buffer);
				buffer += add;
				len += add;
				ret = len;
				percents--;
				continue;
			}
			if (*(format + i + 1) == '\0' && percents == 1)
			{
				ret = -1;
				break;
			}
		}
		*buffer = *(format + i);
		len++;
		buffer++;
		ret = len;
	}
	write(1, buffer_ptr, len);
	va_end(args);
	free(buffer_ptr);
	return (ret);
}
