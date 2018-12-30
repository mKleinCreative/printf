/*
 * File: convert_nums_1.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == SHORT)
		d = (short)d;

	copy = (d < 0) ? -d : d;
	while (copy > 0)
	{
		count++;
		copy /= 10;
	}

	wid -= (d < 0) ? (count + 1) : count;
	while (wid > 0)
	{
		ret += _memcpy(output, &space, 1);
		wid--;
	}

	if (d < 0)
		ret += _memcpy(output, &neg, 1);
	else
	{
		if ((flag & 1) == 1)
			ret += _memcpy(output, &plus, 1);
		else if (((flag >> 1) & 1) == 1)
			ret += _memcpy(output, &space, 1);
	}

	return (ret + convert_sbase(output, d, "0123456789", 0, prec));
}

/**
 * convert_b - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_b(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)flag;
	(void)len;

	return (convert_ubase(output, num, "01", wid, prec));
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (((flag >> 2) & 1) == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	return (ret + convert_ubase(output, num, "01234567", wid, prec));
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	unsigned long int num;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	(void)flag;

	return (convert_ubase(output, num, "0123456789", wid, prec));
}
