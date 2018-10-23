#include "holberton.h"

#include <stdio.h>
/**
 * print_rev - Prints a reversed string.
 * @list: A va_list pointing to the integer to be printed.
 * @buffer: A character buffer storing the overall string to print.
 *
 * Return: The number of characters stored to buffer.
 */

int print_rev(va_list list, char *buffer)
{
	int end, length, i;
	char *rev;
	char *null = "(null)";

	rev = va_arg(list, char *);
	if (rev == NULL)
	{
		for(i = 0; *(null + i); i++)
		{
			*buffer = *(null + i);
			buffer++;
		}
		return (6);
	}
	length = 0;
	while (rev[length] != '\0')
		length++;

	for (end = length - 1; end >= 0; end--)
	{
		*buffer = rev[end];
		buffer++;
	}
	return (length);
}
