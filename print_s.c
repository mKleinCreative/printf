#include "holberton.h"

/**
 * print_s - Prints a string.
 * @list: A va_list pointing to the string to be printed.
 * @buffer: A character buffer to store the string.
 *
 * Return: The number of characters stored to buffer.
 */
int print_s(va_list list, char *buffer)
{
	char *str;
	char *null = "(null)";
	int i;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		for (i = 0; *(null + i); i++)
		{
			*buffer = *(null + i);
			buffer++;
		}

		return (6);
	}

	for (i = 0; *(str + i); i++)
	{
		*buffer = *(str + i);
		buffer++;
	}

	return (i);
}
