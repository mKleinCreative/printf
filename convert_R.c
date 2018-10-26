/*
 * File: convert_R.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_R(va_list args, buffer_t *output)
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
		for (j = 0; j < 26; j++)
		{
			if (*(str + i) == *(alphabet + j))
			{
				_memcpy(output, (rot13 + j), 1);
				break;
			}
		}

		if (j == 26)
			_memcpy(output, (str + i), 1);
	}

	return (len);
}
