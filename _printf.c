#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: character string
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;
char *str;

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
i++;

switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;

case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
count += _puts(str);
break;

case '%':
count += _putchar('%');
break;

default:
count += _putchar('%');
count += _putchar(format[i]);
break;
}
}
else
count += _putchar(format[i]);

i++;
}

va_end(args);

return (count);
}
