/*
 * File: convert_u.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_u(va_list args, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	return (convert_ubase(output, num, "0123456789"));
}
