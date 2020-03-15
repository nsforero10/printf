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
	char *buff = malloc(sizeof(char) * 2048), *org, *aux = NULL;
	va_list args;
	unsigned int size = 0, org_s = 0;

	if (!buff)
	{
		free(buff);
		return (0);
	}
	org = buff;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			org_s = str_ln(org);
			aux = get_fmt_funct(++format)(args, buff);
			if (aux)
				size += str_ln(org) - org_s, buff = aux;
			else
				exit(98);
		}
		else
			*buff = *format, buff++,  size++;
		format++;
	}
	va_end(args), write(1, org, size), free(org);
	return (size);
}
