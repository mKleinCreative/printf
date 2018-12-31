/*
 * File: convert_nums_2.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

unsigned int convert_x(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len);

/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x", space = ' ';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);

	if (NEG_FLAG == 1)
	{
		for (wid -= ret; wid > 0; wid--)
			ret += _memcpy(output, &space, 1);
	}

	return (ret);
}

/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_X(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X", space = ' ';

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	if (NEG_FLAG == 1)
	{
		for (wid -= ret; wid > 0; wid--)
			ret += _memcpy(output, &space, 1);
	}

	return (ret);
}
