#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

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
		{'s', handle_print_string},
		{'d', handle_print_int},
		{'i', handle_print_int},
		{'u', handle_print_uint}
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
	char *buff = calloc(2048, 1), *cursor = buff;
	char *(*funct)(va_list, char *) = NULL;
	va_list args;

	if (!cursor)
	{
		free(cursor);
		return (0);
	}
	if (format)
	{
		va_start(args, format);
		while (*format)
		{
			if (*format == '%')
			{
				funct = get_fmt_funct(++format);
				if (funct)
					cursor = funct(args, cursor);
				else
					*cursor = *format, cursor++;
			}
			else
				*cursor = *format, cursor++;
			format++;
		}
		va_end(args);
	}
	else
	{
		write(2, "zero-length gnu_printf format string\n", 37);
		return (2);
	} 
	*cursor = '\0', write(1, buff, str_ln(buff));
	free(buff);
	return (str_ln(buff));
}
