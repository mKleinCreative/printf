/*
 * File: convert_strings.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len);

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", width = ' ';
	unsigned int size, ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	wid -= size;
	while (wid > 0)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	while (prec > 0)
	{
		ret += _memcpy(output, str, 1);
		prec--;
		str++;
	}

	return (ret);
}

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", *zero = "0", width = ' ';
	int size, index;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	wid -= (prec == 0) ? size : prec;
	while (wid > 0)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	for (index = 0; index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(output, hex, 2);

			if (*(str + index) < 16)
				ret += _memcpy(output, zero, 1);

			ret += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF", 0, 0);
			continue;
		}

		ret += _memcpy(output, (str + index), 1);
	}

	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", width = ' ';
	int size, end, i;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	wid -= (prec == 0) ? size : prec;
	while (wid > 0)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	end = size - 1;
	for (i = 0; i < prec; i++)
	{
		ret += _memcpy(output, (str + end), 1);
		end--;
	}

	return (ret);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flag: A flag modifier.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flag, int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)", width = ' ';
	int i, j, size;
	unsigned int ret = 0;

	(void)flag;
	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	wid -= (prec == 0) ? size : prec;
	while (wid > 0)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	for (i = 0; i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ret += _memcpy(output, (rot13 + j), 1);
				break;
			}
		}

		if (j == 52)
			ret += _memcpy(output, (str + i), 1);
	}

	return (ret);
}
