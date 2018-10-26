/*
 * File: convert_di.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_di(va_list args, buffer_t *output)
{
	int d, ret = 0;
	char neg = '-';

	d = va_arg(args, int);

	if (d < 0)
		ret += _memcpy(output, &neg, 1);

	return (ret + convert_sbase(output, d, "0123456789"));
}
