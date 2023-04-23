#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_number - print number using _putchar
 * @n: Number
 * Return: count
 */
int print_number(int n)
{
	unsigned int i = n;
	int c = 0;

	if (n < 0)
	{
		_putchar('-');
		c++;
		i = -i;
	}
	if (i / 10)
	{
		c = c + print_number(i / 10);
	}
	_putchar(i % 10 + '0');
	c++;
	return (c);
}
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
 * flag_count - counts flags
 * @str: string
 * Return: flag count
 */
int flag_count(const char *str)
{
	char *init = "#0- +'I";
	int c = 0;
	char *flag;

	while (*str != '\0')
	{
		flag = init;
		while (*flag != '\0')
		{
			if (*str == *flag)
			{
				c++;
				break;
			}
			flag++;
		}
		if (*flag == '\0')
			return (c);
		str++;
	}
	return (c);
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
	int fc;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			c++;
			format++;
		}
		else
		{
			fc = flag_count(++format);
			format = format + fc; 
			switch (*format)
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
				case 'i':
					c = c + print_number(va_arg(ap, int));
					break;
				case 'd':
					c = c + print_number(va_arg(ap, int));
					break;
				case '\0':
					format--;
					c = -1;
					break;
				default:
					_putchar('%');
					c = c + 1;
					format = format - fc - 1;
					break;
			}
			format++;
		}
	}
	va_end(ap);
	return (c);
}
