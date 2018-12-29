/*
 * File: convert_strings.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

int convert_s(va_list args, int flag, buffer_t *output);
int convert_S(va_list args, int flag, buffer_t *output);
int convert_r(va_list args, int flag, buffer_t *output);
int convert_R(va_list args, int flag, buffer_t *output);

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_s(va_list args, int flag, buffer_t *output)
{
	char *str, *null = "(null)";
	int len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (len = 0; *(str + len);)
		len++;

	(void)flag;

	return (_memcpy(output, str, len));
}

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
int convert_S(va_list args, int flag, buffer_t *output)
{
	char *str, *null = "(null)", *hex = "\\x", *zero = "0";
	int len = 0, index;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (index = 0; *(str + index); index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			len += _memcpy(output, hex, 2);

			if (*(str + index) < 16)
				len += _memcpy(output, zero, 1);

			len += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF");
			continue;
		}

		len += _memcpy(output, (str + index), 1);
	}

	(void)flag;

	return (len);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_r(va_list args, int flag, buffer_t *output)
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

	(void)flag;

	return (len);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_R(va_list args, int flag, buffer_t *output)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (len = 0; *(str + len);)
		len++;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				_memcpy(output, (rot13 + j), 1);
				break;
			}
		}

		if (j == 52)
			_memcpy(output, (str + i), 1);
	}

	(void)flag;

	return (len);
}
