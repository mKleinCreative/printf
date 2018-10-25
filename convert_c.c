/*
 * File: convert_c.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_c(va_list args, buffer_t *output)
{
	char c;

	c = va_arg(args, int);

	if (c == '\0')
	{
		(output->buffer)++;
		return (1);
	}

	return (_memcpy(output, &c, 1));
}
