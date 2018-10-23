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
	int i, ret = 0, add = 1;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		exit(1);
	buffer_ptr = buffer;

	va_start(args, format);
	for (i = 0; format && *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == '\0' ||
			    converter(format + i + 1))
			{
				i++;
				if (converter(format + i))
				{
					add = converter(format + i)(args, buffer);
					ret += add;
					buffer += add;

					if (*(format + i + 1) != '%')
						i++;
				}
			}
		}
		*buffer = *(format + i);
		ret++;
		buffer++;
	}
	*buffer = '\0';

	write(1, buffer_ptr, ret);
	va_end(args);
	free(buffer_ptr);

	return (ret);
}
