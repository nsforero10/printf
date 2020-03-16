#include <stdio.h>
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

char *rev_string(char *s)
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
	return (s);
}

/**
 * converToStrBase - converts a int
 * into a string with a specificl base
 * @num: the number to convert
 * @base: the base to convert the number to (max base = 16)
 * Return: a pointer to the converted string
 */

char *converToStrBase(int num, unsigned int base, char *ptr)
{
	char dict[] = "0123456789abcdef";
	char *org;

	org = ptr;
	while (num != 0)
	{
		*ptr = dict[num % base];
		num = num / base;
		ptr++;
	}
	rev_string(org);
	return (ptr);
}
