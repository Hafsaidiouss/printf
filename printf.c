#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
 * printstr - prints string
 * @str: string
 * Return: len str
 */
int printstr(char *str)
{
	int i = 0;

	if (str == NULL)
		return (printstr("(null)"));
	while (*str != '\0')
	{
		_putchar(*str);
		i++;
		str++;
	}
	return (i);
}
/**
 * _printf - that produces output according to a format
 * @format: print format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int c = 0;
	char *str;

	va_start(ap, format);

	while (format != NULL && *format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			c++;
			format++;
		}
		else
		{
			switch (*(format + 1))
			{
				case '%':
					_putchar('%');
					c++;
					break;
				case 'c':
					_putchar((char) va_arg(ap, int));
					c++;
					break;
				case 's':
					str = va_arg(ap, char *);
					c = c + printstr(str);
					break;
				default:
					_putchar(*format);
					_putchar(*(format + 1));
					break;
			}
			format = format + 2;
		}
	}
	va_end(ap);
	return (c);
}
