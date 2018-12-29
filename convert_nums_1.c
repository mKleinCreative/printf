/*
 * File: convert_nums_1.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

int convert_di(va_list args, int flag, buffer_t *output);
int convert_b(va_list args, int flag, buffer_t *output);
int convert_u(va_list args, int flag, buffer_t *output);
int convert_o(va_list args, int flag, buffer_t *output);

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier;.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_di(va_list args, int flag, buffer_t *output)
{
	int d, ret = 0;
	char space = ' ', neg = '-', plus = '+';

	d = va_arg(args, int);

	if (d < 0)
		ret += _memcpy(output, &neg, 1);
	else
	{
		if ((flag & 1) == 1)
			ret += _memcpy(output, &plus, 1);
		else if (((flag >> 1) & 1) == 1)
			ret += _memcpy(output, &space, 1);
	}

	return (ret + convert_sbase(output, d, "0123456789"));
}

/**
 * convert_b - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_b(va_list args, int flag, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)flag;

	return (convert_ubase(output, num, "01"));
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_o(va_list args, int flag, buffer_t *output)
{
	unsigned int num;
	char zero = '0';
	int ret = 0;

	num = va_arg(args, unsigned int);

	if (((flag >> 2) & 1) == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	return (ret + convert_ubase(output, num, "01234567"));
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_u(va_list args, int flag, buffer_t *output)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)flag;

	return (convert_ubase(output, num, "0123456789"));
}
