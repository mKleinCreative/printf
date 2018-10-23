#include "holberton.h"

/**
 * print_rot13 - Print a string encrypted with rot13.
 * @list: A va_list pointing to the string to be converted.
 * @buffer: A character buffer storing the overall string to print.
 * Return: The number of characters stored to buffer.
 */
int print_rot13(va_list list, char *buffer)
{
	char *alphabet, *rot13, *ch;
	char *null = "(null)";
	int i, j, length;

	ch = va_arg(list, char *);
	if (ch == NULL)
	{
		for (i = 0; *(null + i); i++)
		{
			*buffer = *(null + i);
			buffer++;
		}
		return (6);
	}
	length = 0;
	alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == ' ')
		{
			*buffer = ' ';
			buffer++;
			length++;
			continue;
		}
		for (j = 0; alphabet[j] != '\0'; j++)
		{
			if (ch[i] == alphabet[j])
			{
				*buffer = rot13[j];
				buffer++;
				break;
			}
			if (alphabet[j] == 'Z')
			{
				*buffer = ch[i];
				buffer++;
			}
		}
		length++;
	}
	return (length);
}
