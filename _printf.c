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
		{'u', handle_print_uint},
		{'b', handle_print_binary},
		{'o', handle_print_octal},
		{'x', handle_print_hexa},
		{'X', handle_print_upper_hexa},
		{'p', handle_print_pointer},
		{'r', handle_print_reversed_string},
		{'S', handle_print_custom_string},
		{'R', handle_print_rot13_string}
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

	if (!buff)
		return (free(buff), 1);
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (buff == cursor && !*(format  + 1))
				return (-1);
			funct = get_fmt_funct(format + 1);
			if (funct)
				cursor = funct(args, cursor), format++;
			else
			{
				if (*(format  + 1) == '%')
					format++;
				*cursor = *format, cursor++;
			}
		}
		else
			*cursor = *format, cursor++;
		format++;
	}
	va_end(args);
	*cursor = '\0', write(1, buff, str_ln(buff));
	if (*buff == '\0')
		return (free(buff), 1);
	free(buff);
	return (str_ln(buff));
}
