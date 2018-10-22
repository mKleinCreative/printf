#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct formatter - A new type describing a formatter.
 * @letter: A conversion specifier.
 * @f: A function pointer to a print function corresponding to letter.
 */
typedef struct formatter
{
	char *letter;
	void (*f)(const char* format, int spec_len, va_list args);
} format_me;

int _printf(const char *format, ...);
void (*converter(const char *))(const char* format, int spec_len, va_list args);
void print_number(int n);
void print_c(const char* format, int spec_len, va_list args);
void print_s(const char* format, int spec_len, va_list args);
void print_d(const char* format, int spec_len, va_list args);
void print_i(const char* format, int spec_len, va_list args);

#endif
