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

	if (current)
		*buffer = current, buffer++;
	return (buffer);
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
	if (!current)
		current = "(null)";
	while (*current)
		*buffer = *current, buffer++, current++;
	return (buffer);
}

/**
 * handle_print_int - handles fill the buffer with chars
 * @list: - va_list to extract the data
 * @buffer: - the buffer to fill
 * Return: the buffer filled
 */
char *handle_print_int(va_list list, char *buffer)
{
	int current = va_arg(list, int);

	if (current)
		buffer = converToStrBase(current, 10, buffer);
	return (buffer);
}