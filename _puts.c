#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to be printed
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _puts(char *str)
{
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
}
