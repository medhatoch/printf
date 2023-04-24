#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @args: list of arguments
 *
 * Return: number of printed characters
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: list of arguments
 *
 * Return: number of printed characters
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        len += _putchar(*str);
        str++;
    }
    return (len);
}

/**
 * print_percent - prints a percent sign
 * @args: list of arguments
 *
 * Return: number of printed characters
 */
int print_percent(__attribute__((unused)) va_list args)
{
    return (_putchar('%'));
}
