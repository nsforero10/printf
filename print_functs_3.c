#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_print_custom_string - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */

char *handle_print_custom_string(va_list list, char *cursor)
{
	char *current;

	current = va_arg(list, char *);
	if (!current)
		current = "(null)";
	while (*current)
	{
		if (*current < 32 || *current >= 127)
		{
			*cursor = '\\', cursor++;
			*cursor = 'x', cursor++;
			if (*current < 16)
				*cursor = '0', cursor++;
			cursor = converToUprStrBase(*current, 16, cursor);
			current++;
		}
		else
			*cursor = *current, cursor++, current++;
	}
	return (cursor);
}

/**
 * handle_print_rot13_string - handles fill the cursor with chars
 * @list: - va_list to extract the data
 * @cursor: - the cursor to fill
 * Return: the cursor filled
 */
char *handle_print_rot13_string(va_list list, char *cursor)
{
	char *current;
	int i = 0, found;
	char *dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *dict2 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	current = va_arg(list, char *);
	if (!current)
		current = "(null)";
	while (*current)
	{
		i = 0, found = 0;
		while (dict[i])
		{
			if (*current == dict[i])
			{
				*cursor = dict2[i], cursor++, current++;
				found = 1;
				break;
			}
			i++;
		}
		if (found == 0)
			*cursor = *current, cursor++, current++;
	}
	return (cursor);
}
