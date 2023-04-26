#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_t - Struct format
 *
 * @fmt: The format
 * @f: The function associated
 */
typedef struct format_t
{
        char *fmt;
        int (*f)(va_list);
} format_t;

/* putchar function */
int _putchar(char c);

/* _printf function */
int _printf(const char *format, ...);

/* Functions for printing characters, strings, and % */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/* Functions for printing integers */
int print_int(va_list args);
int print_integer(va_list args);
int print_integer_helper(unsigned int num);


/* Function for printing decimals */
int print_decimal(va_list args);

/* Function for binary*/
int print_binary(va_list args);

/* Functions for printing unsigned integers */
int print_unsigned_integer(va_list args);
int print_octal(va_list args);
int print_hex_lowercase(va_list args);
int print_hex_uppercase(va_list args);


#endif /* MAIN_H */
