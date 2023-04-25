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
	switch (**format)
	{
		case '%':
			*c = *c + _putchar('%');
			break;
		case 'p':
			*c = *c + print_pointer(va_arg(*ap, void *), format, fc);
			break;
		case 'c':
			*c = *c + _putchar((char) va_arg(*ap, int));
			break;
		case 's':
			*c = *c + print_str(va_arg(*ap, char *));
			break;
		case 'i':
			*c = *c + print_number(va_arg(*ap,long int), format, fc);
			break;
		case 'd':
			*c = *c + print_number(va_arg(*ap,long int), format, fc);
			break;
		case 'b':
			*c = *c + print_binary(va_arg(*ap, unsigned int), format, fc);
			break;
		case 'u':
			*c = *c + print_unsigned_int(va_arg(*ap,long unsigned int), format, fc);
			break;
		case 'o':
			*c = *c + print_octal(va_arg(*ap, long unsigned int), format, fc);
			break;
		case 'x':
			*c = *c + print_hex_lower(va_arg(*ap, long unsigned int), format, fc);
			break;
		case 'X':
			*c = *c + print_hex_upper(va_arg(*ap, long unsigned int), format, fc);
			break;
		case 'S':
			*c = *c + print_S_string(va_arg(*ap, char *));
			break;
		case 'r':
			*c = *c + print_rev(va_arg(*ap, char *));
			break;
		case 'R':
			*c = *c + print_rot(va_arg(*ap, char *));
			break;
		default:
			*c = *c + _putchar('%');
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
			if (*(format + 1) == '\0')
				return (-1);
			fc = flag_count(++format);
			format = format + fc;
			_printf_switch_helper(&format, &c, fc, &ap);
			format++;
		}
	}
	va_end(ap);
	return (c);
}
