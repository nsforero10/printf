#include "holberton.h"
#include <stdarg.h>

/**
 * _print - prints a formatted string on stdout
 * @format: the format string to print on standar output
 * Return: the sie of the stdout
 */
int _printf(const char *format, ...)
{
	char *buff = malloc(sizeof(char)*2048);
	unsigned int i = 0;
	va_list args;

	format_t fmts[] = {
		{'c', handle_print_char},
		{'s', handle_print_string}
	}
}
