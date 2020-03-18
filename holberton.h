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

int str_ln(char *p);
void *rev_string(char *s);
char *converToStrBase(unsigned int num, unsigned int base, char *ptr);
char *converToUprStrBase(unsigned int c, unsigned int b, char *cu);
void *_calloc(unsigned int nmemb, unsigned int size);
char *handle_print_pointer(va_list list, char *cursor);
char *converToStrPointer(unsigned long int c, unsigned int b, char *cu);

int _printf(const char *format, ...);
char *handle_print_char(va_list list, char *cursor);
char *handle_print_string(va_list list, char *cursor);
char *handle_print_uint(va_list list, char *cursor);
char *handle_print_int(va_list list, char *cursor);
char *handle_print_binary(va_list list, char *cursor);
char *handle_print_octal(va_list list, char *cursor);
char *handle_print_hexa(va_list list, char *cursor);
char *handle_print_upper_hexa(va_list list, char *cursor);
char *handle_print_reversed_string(va_list list, char *cursor);
char *handle_print_custom_string(va_list list, char *cursor);
char *handle_print_rot13_string(va_list list, char *cursor);

#endif
