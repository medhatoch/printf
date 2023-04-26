#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: character string that contains directives to control the output
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	len = parse_format_string(format, args);

	va_end(args);
	return (len);
}
