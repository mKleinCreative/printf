/*
 * File: convert_s.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_s(va_list args, buffer_t *output)
{
	char *str;
	char *null = "(null)";
	int len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (len = 0; *(str + len);)
		len++;

	return (_memcpy(output, str, len));
}
