#ifndef HOLBERTON_H
#define HOLBERTON_H

/*
 * File: holberton.h
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	int len;
} buffer_t;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	char specifier;
	int (*func)(va_list, int, buffer_t *);
} converter_t;

/**
 * struct flag_t - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	char flag;
	int value;
} flag_t;

enum
{
	PLUS = 1,
	SPACE = 2,
	HASH = 4,
	ZERO = 8,
	NEG = 16
};

int _printf(const char *format, ...);

/* Conversion Functions */
int convert_c(va_list args, int flag, buffer_t *output);
int convert_s(va_list args, int flag, buffer_t *output);
int convert_di(va_list args, int flag, buffer_t *output);
int convert_percent(va_list args, int flag, buffer_t *output);
int convert_b(va_list args, int flag, buffer_t *output);
int convert_u(va_list args, int flag, buffer_t *output);
int convert_o(va_list args, int flag, buffer_t *output);
int convert_x(va_list args, int flag, buffer_t *output);
int convert_X(va_list args, int flag, buffer_t *output);
int convert_S(va_list args, int flag, buffer_t *output);
int convert_p(va_list args, int flag, buffer_t *output);
int convert_r(va_list args, int flag, buffer_t *output);
int convert_R(va_list args, int flag, buffer_t *output);

/* Helper Functions */
buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
int handle_flags(const char *flag);
int (*convert(const char *specifier))(va_list, int, buffer_t *);
int _memcpy(buffer_t *output, char *src, unsigned int n);
int convert_sbase(buffer_t *output, int num, char *base);
int convert_ubase(buffer_t *output, unsigned long int num, char *base);

#endif
