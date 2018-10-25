/*
 * File: convert_o.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_o(va_list args, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	return (convert_ubase(output, num, "01234567"));
}
