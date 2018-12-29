/*
 * File: convert_strings.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len);

/**
 * convert_s - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len)
{
	char *str, *null = "(null)";
	unsigned int size;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	(void)flag;
	(void)len;

	return (_memcpy(output, str, size));
}

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", *zero = "0";
	unsigned int size = 0, index;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (index = 0; *(str + index); index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			size += _memcpy(output, hex, 2);

			if (*(str + index) < 16)
				size += _memcpy(output, zero, 1);

			size += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF");
			continue;
		}

		size += _memcpy(output, (str + index), 1);
	}

	(void)flag;
	(void)len;

	return (size);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @flag: A flag modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len)
{
	char *str, *null = "(null)";
	unsigned int size;
	int end;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	for (end = size - 1; end >= 0; end--)
		_memcpy(output, (str + end), 1);

	(void)flag;
	(void)len;

	return (size);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @flag: A flag modifier.
 * @len: A lenth modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(va_list args, buffer_t *output,
		unsigned char flag, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	unsigned int i, j, size;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	for (i = 0; i < size; i++)
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
	(void)len;

	return (size);
}
