#include "main.h"
#include <stdarg.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))

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
	int i;
	int cc;
	int width = get_width(ap, format, fc);
	int precision = get_precision(ap, format, fc);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';
	char *s = va_arg(*ap, char *);

	cc = char_counter(s);
        if (flag(format, fc, '.'))
                cc = min(cc, precision);
        if (precision == 0 && flag(format, fc, '.'))
                return (0);
	if (minus == 0)
		c += print_padding(width, cc, pc);
	if (flag(format, fc, '.'))
	{
		for (i = 0; i < cc; i++)
		{
			c += _putchar(s[i]);
		}
	}
	else
		c += _print_str(s);
	if (minus == 1)
                c += print_padding(width, cc, pc);
	return (c);
}
