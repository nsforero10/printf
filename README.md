# Printf
* Description: _printf is a function that prints formatted output conversion. In
the most simple case, _printf takes one argument: a string of characters to be
printed. The characters of the string are printed exaclty as they appear. In
order to identify the start of the string, we put a double quote at the front,
and another one to set the end.

The format conversion is marked by the character %, which can take the following
conversion specifiers:
- %c: prints a single character
- %s: prints a decimal strings
- %d: prints a decimal number
- %i: prints an integer in base 10
- %b: prints the unsigned int converted to binary
- %u: prints an unsigned decimal number
- %o: prints a number in octal
- %x: prints a number in hexadecimal
- %X: prints a number in HEXADECIMAL
- %S: prints a string and characters not betwen 0 < ASCII value < 32 or >=127
- %p: prints a pointer argument in hexadecimal

It also handles the following flags:
- + : A sign (+ or -) should always be placed before a number produced by a
signed conversion. By default a sign is used only for negative numbers.
A + overrides a space if both are used
- space: A blanck is left before a positive number, or empty string, introduced
by a signed conversion
- #: The value is converted to an "Alternate form"
- 0: The value is zero padded
- -: The converted value is to be left adjusted on the field boundary
* Other functions are used to handle everything:
- char *handle_print_char(va_list list, char *cursor)
- char *handle_print_string(va_list list, char *cursor)
- char *handle_print_uint(va_list list, char *cursor)
- char *handle_print_int(va_list list, char *cursor)
- char *handle_print_binary(va_list list, char *cursor)
- char *handle_print_octal(va_list list, char *cursor)
- char *handle_print_hexa(va_list list, char *cursor)
- char *handle_print_upper_hexa(va_list list, char *cursor)
- char *handle_print_pointer(va_list list, char *cursor)
- char *handle_print_reversed_string(va_list list, char *cursor)