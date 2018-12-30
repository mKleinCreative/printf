/*
 * File: base_converters.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		int wid, int prec);
unsigned int convert_ubase(buffer_t *output,
		unsigned long int num, char *base, int wid, int prec);

/**
 * convert_sbase - Converts a signed long to an inputted base and stores
 *                the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		int wid, int prec)
{
	int size;
	char digit, width = ' ', zero = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				wid - 1, prec - 1);

	else
	{
		while (prec > 1)
		{
			ret += _memcpy(output, &zero, 1);
			prec--;
			wid--;
		}
		while (wid > 1)
		{
			ret += _memcpy(output, &width, 1);
			wid--;
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * convert_ubase - Converts an unsigned long to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, width = ' ', zero = '0';

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				wid - 1, prec - 1);

	else
	{
		while (prec > 1)
		{
			ret += _memcpy(output, &zero, 1);
			prec--;
			wid--;
		}
		while (wid > 1)
		{
			ret += _memcpy(output, &width, 1);
			wid--;
		}
	}

	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
