/*
 * File: _printf.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * count_one_bits - Counts the number of bits set
 *                  to one in a binary number.
 * @num: The binary number.
 *
 * Return: The number of bits set to one.
 */
unsigned char count_one_bits(unsigned char num)
{
	unsigned char count = 0;

	while (num != 0)
	{
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}

	return (count);
}


/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int i, tmp, ret = 0;
	unsigned char flag, len;
	unsigned int (*f)(va_list, buffer_t *, unsigned char, unsigned char);

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			flag = handle_flags(format + i + 1);
			tmp = count_one_bits(flag);
			len = handle_length(format + i + tmp + 1);
			tmp += (len != 0) ? 1 : 0;
			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flag, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}
