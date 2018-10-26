/*
 * File: convert_p.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_p(va_list args, buffer_t *output)
{
	char *lead = "0x", *null = "(nil)";
	unsigned long int address;

	address = va_arg(args, unsigned long int);

	if (address == '\0')
		return (_memcpy(output, null, 5));

	_memcpy(output, lead, 2);

	return (2 + convert_ubase(output, address, "0123456789abcdef"));
}
