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
 * print_unsigned_integer - prints an unsigned integer in base 10
 * @args: the va_list that contains the unsigned integer
 *
 * Return: the number of digits printed
 */
int print_unsigned_integer(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int digits = 0;

    if (n / 10)
    {
        digits += print_unsigned_integer(args);
    }

    _putchar((n % 10) + '0');
    digits++;

    return (digits);
}

/**
 * print_octal - prints an unsigned integer in base 8 (octal)
 * @args: the va_list that contains the unsigned integer
 *
 * Return: the number of digits printed
 */
int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int digits = 0;

    if (n / 8)
    {
        digits += print_octal(args);
    }

    _putchar((n % 8) + '0');
    digits++;

    return (digits);
}

/**
 * print_hexadecimal - prints an unsigned integer in base 16 (hexadecimal)
 * @args: the va_list that contains the unsigned integer
 * @uppercase: if true, print the hexadecimal in uppercase
 *
 * Return: the number of digits printed
 */
int print_hexadecimal(va_list args, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    int digits = 0;
    char hex_digits[16] = "0123456789abcdef";
    int base = 16;

    if (uppercase)
    {
        hex_digits[10] = 'A';
        hex_digits[11] = 'B';
        hex_digits[12] = 'C';
        hex_digits[13] = 'D';
        hex_digits[14] = 'E';
        hex_digits[15] = 'F';
    }

    if (n / base)
    {
        digits += print_hexadecimal(args, uppercase);
    }

    _putchar(hex_digits[n % base]);
    digits++;

    return (digits);
}

/**
 * print_hexadecimal_upper - prints an unsigned integer in base 16 (hexadecimal) in uppercase
 * @args: the va_list that contains the unsigned integer
 *
 * Return: the number of digits printed
 */
int print_hexadecimal_upper(va_list args)
{
    return (print_hexadecimal(args, 1));
}
