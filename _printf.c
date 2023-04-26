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
	int i = 0, j = 0, len = 0;

	format_t formats[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_integer},
		{"d", print_decimal},
		{"b", print_binary},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			for (j = 0; formats[j].fmt != NULL; j++)
			{
				if (*(formats[j].fmt) == format[i])
				{
					len += formats[j].f(args);
					break;
				}
			}
			if (formats[j].fmt == NULL)
			{
				if (format[i] != ' ')
					len += _putchar('%');
				len += _putchar(format[i]);
			}
		}
		else
		{
			len += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (len);
}
