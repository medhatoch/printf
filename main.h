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

#endif /* MAIN_H */
