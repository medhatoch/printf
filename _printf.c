#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
    char buf[1024] = {0};
    int buf_len = 0;

    format_t formats[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_percent},
        {"i", print_integer},
        {"d", print_decimal},
        {"b", print_binary},
        {"u", print_unsigned_integer},
        {"o", print_octal},
        {"x", print_hex_lowercase},
        {"X", print_hex_uppercase},
        {NULL, NULL}
    };

    va_start(args, format);

    while (*format)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            for (j = 0; formats[j].fmt != NULL; j++)
            {
                if (formats[j].fmt[0] == *format)
                {
                    int n = formats[j].f(args);
                    if (n < 0)
                        return (-1);
                    buf_len += n;
                    break;
                }
            }
            if (formats[j].fmt == NULL)
            {
                if (format[i] != ' ')
                    buf_len += _putchar_buf(buf + buf_len, sizeof(buf) - buf_len, '%');
                buf_len += _putchar_buf(buf + buf_len, sizeof(buf) - buf_len, format[i]);
            }
        }
        else
        {
            buf_len += _putchar_buf(buf + buf_len, sizeof(buf) - buf_len, format[i]);
        }
        i++;
    }

    va_end(args);

    /* write any remaining characters to stdout */
    if (buf_len > 0)
    {
        len = write(1, buf, buf_len);
        if (len < 0)
            return (-1);
    }

    return (buf_len);
}

