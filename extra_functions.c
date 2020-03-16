#include <stdio.h>
#include <stdlib.h>
/**
 * str_ln - calcualte the lenght of a string
 * @p: the string to messure
 * Return: the lenght of the string
 */
int str_ln(char *p)
{
	int i = 0;

	while (*p)
		i++, p++;
	return (i);
}
/**
 * rev_string - reverse a string
 * @s:string to reverse
 * Return: the string reverser
 */

void rev_string(char *s)
{
	int  back, front, len;
	char aux;

	front = 0;
	len = str_ln(s);
	back = len - 1;
	while (back >= len / 2)
	{
		aux = *(s + front);
		*(s + front) = *(s + back);
		*(s + back) = aux;
		back--;
		front++;
	}
}

/**
 * converToStrBase - converts a int
 * into a string with a specificl base
 * @current: the currentber to convert
 * @base: the base to convert the currentber to (max base = 16)
 * @cursor: cursor to write in
 * Return: a pointer to the converted string
 */

char *converToStrBase(unsigned int current, unsigned int base, char *cursor)
{
	char *dict = "0123456789abcdef";
	char *org;

	org = cursor;
	while (current != 0)
	{
		*cursor = dict[current % base];
		current = current / base;
		cursor++;
	}
	rev_string(org);
	return (cursor);
}

/**
 * converToStrPointer - converts a int
 * into a string with a specificl base
 * @current: the currentber to convert
 * @base: the base to convert the currentber to (max base = 16)
 * @cursor: cursor to write in
 * Return: a pointer to the converted string
 */

char *converToStrPointer(long int current, unsigned int base, char *cursor)
{
	char *dict = "0123456789abcdef";
	char *org;

	org = cursor;

	while (current != 0)
	{
		*cursor = dict[current % base];
		current = current / base;
		cursor++;
	}
	*cursor = 'x', cursor++;
	*cursor = '0', cursor++;
	rev_string(org);
	return (cursor);
}

/**
 * converToUprStrBase - converts a int
 * into a string with a specificl base
 * @current: the currentber to convert
 * @base: the base to convert the currentber to (max base = 16)
 * @cursor: cursor to write in
 * Return: a pointer to the converted string
 */

char *converToUprStrBase(unsigned int current, unsigned int base, char *cursor)
{
	char *dict = "0123456789ABCDEF";
	char *org;

	org = cursor;
	while (current != 0)
	{
		*cursor = dict[current % base];
		current = current / base;
		cursor++;
	}
	rev_string(org);
	return (cursor);
}
