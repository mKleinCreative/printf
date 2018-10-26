/*
 * File: convert_base.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

int convert_sbase(buffer_t *output, int num, char *base);
int convert_ubase(buffer_t *output, unsigned long int num, char *base);

/**
 * convert_sbase - Converts a signed int to an inputted base and stores
 *                the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed integer to be converted.
 * @base: A pointer to a string containing the base to convert to.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_sbase(buffer_t *output, int num, char *base)
{
	int len, ret = 1;
	char digit;

	for (len = 0; *(base + len);)
		len++;

	if (num >= len || num <= -len)
		ret += convert_sbase(output, num / len, base);

	digit = base[(num < 0 ? -1 : 1) * (num % len)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * convert_ubase - Converts an unsigned long int to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned integer to be converted.
 * @base: A pointer to a string containing the base to convert to.
 *
 * Return: The number of bytes stored to the buffer.
 */
int convert_ubase(buffer_t *output, unsigned long int num, char *base)
{
	unsigned int len, ret = 1;
	char digit;

	for (len = 0; *(base + len);)
		len++;

	if (num >= len)
		ret += convert_ubase(output, num / len, base);

	digit = base[(num % len)];
	_memcpy(output, &digit, 1);

	return (ret);
}
