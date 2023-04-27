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
	char *s = va_arg(*ap, char *);

	c += print_padding(width, char_counter(s), ' ');
	c += _print_str(s);
	return (c);
}
