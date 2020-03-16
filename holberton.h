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

int str_ln (char *p);
void *rev_string(char *s);
char *converToStrBase(unsigned int num, unsigned int base, char *ptr);
void *_calloc(unsigned int nmemb, unsigned int size);

int _printf(const char *format, ...);
char *handle_print_char(va_list list, char *cursor);
char *handle_print_string(va_list list, char *cursor);
char *handle_print_uint(va_list list, char *cursor);
char *handle_print_int(va_list list, char *cursor);



#endif
