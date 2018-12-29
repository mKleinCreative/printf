/*
 * File: convert.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * handle_flags - Matches a flag with its corresponding value.
 * @flag: A pointer to the potential flag.
 *
 * Return: If the character is a flag - its integer value.
 *         Otherwise - 0.
 */
int handle_flags(const char *flag)
{
	int i, j, ret = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (ret);
}

/**
 * convert - Matches a conversion specifier with a
 *           corresponding conversion function.
 * @specifier: A pointer to a conversion specifier - a character.
 *
 * Return: If a conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
int (*convert(const char *specifier))(va_list, int, buffer_t *)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
