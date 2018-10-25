/*
 * File: convert_r.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_r(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";
	int len, end;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (len = 0; *(str + len);)
		len++;

	for (end = len - 1; end >= 0; end--)
		_memcpy(output, (str + end), 1);

	return (len);
}
