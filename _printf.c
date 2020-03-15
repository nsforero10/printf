#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * str_ln - calculates the lenght of a string
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
 * get_fmt_funct - get the apropiatted function to handle
 * the the conversion
 * @s: the identifier to handle
 * Return: pointer to a function to use
 */
char * (*get_fmt_funct(const char *s))(va_list, char *)
{
	unsigned int i = 0;
	format_t fmts[] = {
		{'c', handle_print_char},
		{'s', handle_print_string}
	};

	while (fmts[i].identifier)
	{
		if (*(s) == fmts[i].identifier)
			return (fmts[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - prints a formatted string on stdout
 * @format: the format string to print on standar output
 * Return: the sie of the stdout
 */
int _printf(const char *format, ...)
{
	char *buff = malloc(sizeof(char) * 2048), *org;
	char *(*funct)(va_list, char *) = NULL;
	va_list args;

	if (!buff)
	{
		free(buff);
		return (0);
	}
	org = buff;
	va_start(args, format);
	if (format)
	{
		while (*format)
		{
			if (*format == '%')
			{
				funct = get_fmt_funct(++format);
				if (funct)
				{
					buff = funct(args, buff);
				}
				else
					*buff = *format, buff++;
			}
			else
				*buff = *format, buff++;
			format++;
		}
	}
	else
	{
		write(2, "zero-length gnu_printf format string\n", 37);
		return (2);
	}
	*buff = '\0', va_end(args), write(1, org, str_ln(org)), free(org);
	return (str_ln(org));
}
