/*
 * File: convert_percent.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
int convert_percent(va_list __attribute__((__unused__)) args, buffer_t *output)
{
	char percent = '%';

	return (_memcpy(output, &percent, 1));
}
