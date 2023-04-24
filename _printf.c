#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format
 * @format: a string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}
