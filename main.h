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

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
