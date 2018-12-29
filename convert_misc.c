/*
 * File: convert_misc.c
 * Auth: Brennan D Baraban
 */

#include "holberton.h"

int convert_c(va_list args, int flag, buffer_t *output);
int convert_percent(va_list args, int flag, buffer_t *output);
int convert_p(va_list args, int flag, buffer_t *output);

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_c(va_list args, int flag, buffer_t *output)
{
	char c;

	c = va_arg(args, int);

	(void)flag;

	return (_memcpy(output, &c, 1));
}

/**
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
int convert_percent(va_list args, int flag, buffer_t *output)
{
	char percent = '%';

	(void)args;
	(void)flag;

	return (_memcpy(output, &percent, 1));
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flag: A flag modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_p(va_list args, int flag, buffer_t *output)
{
	char *lead = "0x", *null = "(nil)";
	unsigned long int address;

	address = va_arg(args, unsigned long int);

	if (address == '\0')
		return (_memcpy(output, null, 5));

	_memcpy(output, lead, 2);

	(void)flag;

	return (2 + convert_ubase(output, address, "0123456789abcdef"));
}
