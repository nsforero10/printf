#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_print_octal - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_octal(va_list list, char *cursor)
{
	unsigned int current = va_arg(list, unsigned int);

	if (current == 0)
	{
		*cursor = '0', cursor++;
		return (cursor);
	}
	if (current)
		cursor = converToStrBase(current, 8, cursor);
	return (cursor);
}

/**
 * handle_print_hexa - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_hexa(va_list list, char *cursor)
{
	unsigned int current = va_arg(list, unsigned int);


	if (current == 0)
	{
		*cursor = '0', cursor++;
		return (cursor);
	}
	if (current)
		cursor = converToStrBase(current, 16, cursor);
	return (cursor);
}

/**
 * handle_print_upper_hexa - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_upper_hexa(va_list list, char *cursor)
{
	unsigned int current = va_arg(list, unsigned int);

	if (current == 0)
	{
		*cursor = '0', cursor++;
		return (cursor);
	}
	if (current)
		cursor = converToUprStrBase(current, 16, cursor);
	return (cursor);
}

/**
 * handle_print_pointer - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_pointer(va_list list, char *cursor)
{
	long int current = va_arg(list, long int);

	*cursor = '0', cursor++;
	*cursor = 'x', cursor++;
	if (current == 0)
	{
		*cursor = '0', cursor++;
		return (cursor);
	}
	if (current)
		cursor = converToStrPointer(current, 16, cursor);
	return (cursor);
}

/**
 * handle_print_reversed_string - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_reversed_string(va_list list, char *cursor)
{
	char *current, *org;

	current = va_arg(list, char *);
	org  = cursor;
	if (!current)
		current = "(null)";
	while (*current)
		*cursor = *current, cursor++, current++;
	rev_string(org);
	return (cursor);
}
