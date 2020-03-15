#ifndef hol
#define hol

#include <stdarg.h>
#include <stdlib.h>
/**
 * @identifier: character
 * @f: function match
 */
typedef struct fmt 
{
	char *identifier;
	void (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
char handle_print_char(va_list list);
char *handle_print_string(va_list list);


#endif
