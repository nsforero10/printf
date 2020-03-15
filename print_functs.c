#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_print_char - handles fill the buffer with chars
 * @list: - va_list to extract the data
 * @buffer: - the buffer to fill
 * Return: the buffer filled
 */
char *handle_print_char(va_list list, char *buffer)
{
	char current = va_arg(list, int);

	*buffer = current;
	return (++buffer);
}

/**
 * handle_print_string - handles fill the buffer with chars
 * @list: - va_list to extract the data
 * @buffer: - the buffer to fill
 * Return: the buffer filled
 */
char *handle_print_string(va_list list, char *buffer)
{
	char *current;

	current = va_arg(list, char *);
	while (*current)
		*buffer = *current, buffer++, current++;
	return (buffer);
}
