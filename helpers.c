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

/**
 * print_integer - prints an integer
 * @args: arguments list containing the integer to print
 *
 * Return: the number of digits printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    int digits = 0;
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        num = -n;
        digits++;
    }
    else
    {
        num = n;
    }

    if (num / 10)
    {
        digits += print_integer_helper(num / 10);
    }

    _putchar((num % 10) + '0');
    digits++;

    return (digits);
}

/**
 * print_decimal - prints a decimal number
 * @args: arguments list containing the decimal number to print
 *
 * Return: the number of digits printed
 */
int print_decimal(va_list args)
{
    int n = va_arg(args, int);
    int digits = 0;

    if (n < 0)
    {
        _putchar('-');
        digits++;
        n = -n;
    }

    digits += print_integer_helper(n);

    return (digits);
}

/**
 * print_integer_helper - helper function for print_integer to
 * print each digit recursively
 * @num: the integer to print
 *
 * Return: the number of digits printed
 */
int print_integer_helper(unsigned int num)
{
    int digits = 0;

    if (num / 10)
    {
        digits += print_integer_helper(num / 10);
    }

    _putchar((num % 10) + '0');
    digits++;

    return (digits);
}

/**
 * print_binary - prints an unsigned int in binary format
 * @args: the va_list containing the unsigned int to print
 *
 * Return: the number of digits printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int binary[32];
    int i, j;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    for (i = 0; num > 0; i++)
    {
        binary[i] = num % 2;
        num /= 2;
    }

    for (j = i - 1; j >= 0; j--)
        _putchar(binary[j] + '0');

    return (i);
}

/**
 * print_unsigned_integer_helper - Prints an unsigned integer in a given base
 * @num: The unsigned integer to print
 * @base: The base to print @num in (up to 16)
 *
 * Return: The number of digits printed
 */
int print_unsigned_integer_helper(unsigned int num, unsigned int base)
{
    char digits[] = "0123456789abcdef";
    char buffer[100];
    int i = 0, j;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    while (num)
    {
        buffer[i++] = digits[num % base];
        num /= base;
    }

    for (j = i - 1; j >= 0; j--)
        _putchar(buffer[j]);

    return (i);
}

/**
 * print_unsigned_integer - prints an unsigned integer
 * @args: arguments list containing the unsigned integer to print
 * 
 * Return: the number of digits printed
 */
int print_unsigned_integer(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int digits = 0;

    digits += print_unsigned_integer_helper(n, 10);

    return (digits);
}

/**
 * print_octal - prints an unsigned int in octal format
 * @args: the va_list containing the unsigned int to print
 *
 * Return: the number of digits printed
 */
int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int octal[32];
    int i, j;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    for (i = 0; num > 0; i++)
    {
        octal[i] = num % 8;
        num /= 8;
    }

    for (j = i - 1; j >= 0; j--)
        _putchar(octal[j] + '0');

    return (i);
}

/**
 * print_hex_lowercase - prints an unsigned int in hexadecimal lowercase format
 * @args: the va_list containing the unsigned int to print
 *
 * Return: the number of digits printed
 */
int print_hex_lowercase(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int hex[32];
    int i, j;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    for (i = 0; num > 0; i++)
    {
        hex[i] = num % 16;
        num /= 16;
    }

    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] < 10)
            _putchar(hex[j] + '0');
        else
            _putchar(hex[j] - 10 + 'a');
    }

    return (i);
}

/**
 * print_hex_uppercase - prints an unsigned int in hexadecimal uppercase format
 * @args: the va_list containing the unsigned int to print
 *
 * Return: the number of digits printed
 */
int print_hex_uppercase(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int hex[32];
    int i, j;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    for (i = 0; num > 0; i++)
    {
        hex[i] = num % 16;
        num /= 16;
    }

    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] < 10)
            _putchar(hex[j] + '0');
        else
            _putchar(hex[j] - 10 + 'A');
    }

    return (i);
}
