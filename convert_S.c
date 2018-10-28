/*
 * File: convert_S.c
 * Auth: Brennan D Baraban
 */

#include "holberton.h"

/**
 * convert_S - Converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
int convert_S(va_list args, buffer_t *output)
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

	return (len);
}
