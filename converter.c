#include "holberton.h"

/**
 * converter - Matches conversion specifier with corresponding print function.
 * @symbol: Conversion specifier to match.
 *
 * Return: A function pointer to the function matched by symbol.
 */
void (*converter(const char *symbol))(const char* format, int spec_list, va_list list)
{
	format_me func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};
	int i, max;

	i = 0, max = sizeof(func)/sizeof(func[0]);

	for (; i < max ; ++i)
	{
		if (*symbol == *(func[i].letter))
			return (func[i].f);
	}
	/*
	switch (symbol) {
		case 'c':
			print_c(list);
			break;
		case 's':
			print_s(list);;
			break;
		case 'd':
			print_d(list);;
			break;
		case 'i':
			print_i(list);;
			break;
	}
	*/
	write(2, "conversion specifier lacks type at end of format", 48);
	exit(1);
}
