#include "main.h"
#include <stdarg.h>

/**
 * print_string - handler for %s
 * @ap: arg list
 * @format: pointer to specifier
 * @fc: flag count
 *
 * Return: caracter count
 */
int print_string(va_list *ap, const char *format, int fc)
{
	int c = 0;
	int width = get_width(ap, format, fc);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';

	char *s = va_arg(*ap, char *);
	if (minus == 0)
		c += print_padding(width, char_counter(s), pc);
	c += _print_str(s);
	if (minus == 1)
                c += print_padding(width, char_counter(s), pc);
	return (c);
}
