#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf_switch_helper - handle switch cases for _printf function
 * @format: pointer of format
 * @c: pointer to c
 * @fc: flag count value
 * @ap: variadic arg list
 */
void _printf_switch_helper(const char **format, int *c, int fc, va_list *ap)
{
	char *str;

	switch (**format)
	{
		case '%':
			_putchar('%');
			(*c)++;
			break;
		case 'c':
			_putchar((char) va_arg(*ap, int));
			(*c)++;
			break;
		case 's':
			str = va_arg(*ap, char *);
			*c = *c + print_str(str);
			break;
		case 'i':
			*c = *c + print_number(va_arg(*ap, int));
			break;
		case 'd':
			*c = *c + print_number(va_arg(*ap, int));
			break;
		case '\0':
			(*format)--;
			*c = -1;
			break;
		case 'b':
			*c = *c + print_binary(va_arg(*ap, unsigned int));
			break;
		default:
			_putchar('%');
			*c = *c + 1;
			*format = *format - fc - 1;
			break;
	}
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
			_printf_switch_helper(&format, &c, fc, &ap);
			format++;
		}
	}
	va_end(ap);
	return (c);
}
