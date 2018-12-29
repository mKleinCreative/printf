/*
 * File: convert_nums_2.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

int convert_x(va_list args, int flag, buffer_t *output);
int convert_X(va_list args, int flag, buffer_t *output);

/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_x(va_list args, int flag, buffer_t *output)
{
	unsigned int num;
	char *lead = "0x";
	int ret = 0;

	num = va_arg(args, unsigned int);

	if (((flag >> 2) & 1) == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	return (ret + convert_ubase(output, num, "0123456789abcdef"));
}

/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_X(va_list args, int flag, buffer_t *output)
{
	unsigned int num;
	char *lead = "0X";
	int ret = 0;

	num = va_arg(args, unsigned int);

	if (((flag >> 2) & 1) == 1)
		ret += _memcpy(output, lead, 2);

	return (ret + convert_ubase(output, num, "0123456789ABCDEF"));
}
