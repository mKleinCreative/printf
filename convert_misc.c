/*
 * File: convert_misc.c
 * Auth: Brennan D Baraban
 */

#include "holberton.h"

unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len);

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len)
{
	char c, width = ' ';
	unsigned int ret = 0;

	c = va_arg(args, int);

	(void)flags;
	(void)prec;
	(void)len;

	while (wid > 1)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	return (ret + _memcpy(output, &c, 1));
}

/**
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len)
{
	char percent = '%', width = ' ';
	unsigned int ret = 0;

	(void)args;
	(void)flags;
	(void)prec;
	(void)len;

	while (wid > 1)
	{
		ret += _memcpy(output, &width, 1);
		wid--;
	}

	return (ret + _memcpy(output, &percent, 1));
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, char wid, char prec, unsigned char len)
{
	char *lead = "0x", *null = "(nil)";
	unsigned long int address;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	_memcpy(output, lead, 2);

	return (2 + convert_ubase(output, address, "0123456789abcdef",
				flags, wid, prec));
}
