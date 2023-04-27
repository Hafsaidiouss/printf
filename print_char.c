#include "main.h"
#include <stdarg.h>

/**
 * print_char - handler for %c
 * @ap: arg list
 * @format: pointer to specifier
 * @fc: flag count
 *
 * Return: printed caracter count
 */
int print_char(va_list *ap, const char *format, int fc)
{
	int c = 0;
	int width = get_width(ap, format, fc);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';

	if (minus == 0)
		c += print_padding(width, 1, pc);
	c += _putchar((char) va_arg(*ap, int));
	if (minus == 1)
		c += print_padding(width, 1, pc);
	return (c);
}
