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
		{"d", print_di},
		{"i", print_di},
		{"%", print_percent},
		{"r", print_rev},
		{"b", print_b},
	};
	int i;

	for (i = 0; i < 7; i++)
	{
		if (*symbol == *(func[i].letter))
			return (func[i].f);
	}

	return (NULL);
}
