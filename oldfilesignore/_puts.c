#include "main.h"

/**
 * _puts - prints a string and new line to stdout
 * @str: pointer to string
 * Return: number of chars printed
 */
int _puts(char *str)
{
int i = 0, count = 0;

while (str[i])
{
_putchar(str[i]);
count++;
i++;
}
return (count);
}
