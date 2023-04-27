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

	c += print_padding(width, 1, ' ');
	c += _putchar((char) va_arg(*ap, int));
	return (c);
}
