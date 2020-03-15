#ifndef hol
#define hol

#include <stdarg.h>
#include <stdlib.h>
/**
 * struct fmt - struct for formats
 * @identifier: character
 * @f: function match
 */
typedef struct fmt
{
	char identifier;
	char *(*f)(va_list, char *);
} format_t;

int _printf(const char *format, ...);
char *handle_print_char(va_list list, char *buffer);
char *handle_print_string(va_list list, char *buffer);


#endif
