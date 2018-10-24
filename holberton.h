#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct formatter - A new type describing a formatter.
 * @letter: A conversion specifier.
 * @f: A function pointer to a print function corresponding to letter.
 */
typedef struct formatter
{
	char *letter;
	int (*f)(va_list list, char *buffer);
} format_me;

int _printf(const char *format, ...);
int (*converter(const char *symbol))(va_list list, char *buffer);
void print_number(int n, char *buffer);
int print_c(va_list list, char *buffer);
int print_s(va_list list, char *buffer);
int print_di(va_list list, char *buffer);
int print_percent(va_list list, char *buffer);
int print_u(va_list list, char *buffer);
int print_o(va_list list, char *buffer);
int print_x(va_list list, char *buffer);
int print_X(va_list list, char *buffer);
int print_b(va_list list, char *buffer);
int print_rev(va_list list, char *buffer);
int print_rot13(va_list list, char *buffer);

#endif
