#include "holberton.h"

/**
 * converter - Matches conversion specifier with corresponding print function.
 * @symbol: Conversion specifier to match.
 *
 * Return: A function pointer to the function matched by symbol.
 */
int (*converter(const char *symbol))(va_list list, char *buffer)
{
	format_me func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (*symbol == *(func[i].letter))
			return (func[i].f);
	}

	write(2, "conversion specifier lacks type at end of format", 48);
	exit(1);
}
