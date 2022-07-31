#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * convert - converts int to appropiate base
 * @num: int to be converted
 * @base: base to be converted into
 * Return: pointer to converted int
 */
char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * int_formatter - prints and converts int to appropiate base
 * @num: int to be printed
 * @base: base to be converted into
 * Return: count of ints printedt
 */
int int_formatter(int num, int base)
{
	int count = 0;

	if (num < 0)
	{
		num = -num;
		_putchar('-');
		count++;
	}
	count += _puts(convert(num, base));
	return (count);
}

/**
 * _printf - Our implementation of the printf function
 * @format: string to be printed, plus specifiers
 *
 * Return: count of chars printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *str;
	va_list arg;

	va_start(arg, format);
	for (str = format; *str != '\0'; str++)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				_putchar((char)va_arg(arg, int));
				count++;
			}
			else if (*str == 's')
				count += _puts(va_arg(arg, char*));
			else if (*str == 'd' || *str == 'i')
				count += int_formatter(va_arg(arg, int), 10);
			else if (*str == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*str);
				count += 2;
			}
		}
		else
		{
			_putchar(*str);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
