#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_print_char - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_char(va_list list, char *cursor)
{
	char current = va_arg(list, int);

	if (current)
		*cursor = current, cursor++;
	return (cursor);
}

/**
 * handle_print_string - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_string(va_list list, char *cursor)
{
	char *current;

	current = va_arg(list, char *);
	if (!current)
		current = "(null)";
	while (*current)
		*cursor = *current, cursor++, current++;
	return (cursor);
}

/**
 * handle_print_uint - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_uint(va_list list, char *cursor)
{
	unsigned int current = va_arg(list, int);

	if (current)
		cursor = converToStrBase(current, 10, cursor);
	return (cursor);
}
/**
 * handle_print_int - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_int(va_list list, char *cursor)
{
	int current = va_arg(list, int);

	if (current)
	{
		if (current < 0)
			*cursor = '-', current = current * -1, cursor++;
		cursor = converToStrBase(current, 10, cursor);
	}
	return (cursor);
}

/**
 * handle_print_binary - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_binary(va_list list, char *cursor)
{
	unsigned int current = va_arg(list, unsigned int);

	if (current)
		cursor = converToStrBase(current, 2, cursor);
	return (cursor);
}

