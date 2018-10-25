/*
 * File: init_buffer.c
 * Auth: Brennan D Baraban
 *       Michael Klein
 */

#include "holberton.h"

/**
 * init_buffer - Initializes a variable of struct type buffer_t.
 * @output: The buffer_t to be initialized.
 */
void init_buffer(buffer_t *output)
{
	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
		return;
	output->start = output->buffer;
	output->len = 0;
}
