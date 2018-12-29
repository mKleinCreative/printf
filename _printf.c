/*
 * File: _printf.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"
#include <stdio.h>

/**
 * count_one_bits - Counts the number of bits set to one
 *                  in a binary number.
 * @num: The binary number.
 *
 * Return: The number of bits set to one.
 */
int count_one_bits(int num)
{
	int count = 0;

	while (num != 0)
	{
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}

	return (count);
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
	int i, flag, ret = 0;
	char ch;

	if (format == NULL)
		return (-1);

	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			flag = handle_flags(format + i + 1);
			i += count_one_bits(flag);

			if (convert(format + i + 1) != NULL)
			{
				i++;
				ret += convert(format + i)(args, flag, output);
				continue;
			}
			if (*(format + i + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ch = *(format + i);
		ret += _memcpy(output, &ch, 1);
	}
	write(1, output->start, output->len);
	va_end(args);
	free_buffer(output);

	return (ret);
}
