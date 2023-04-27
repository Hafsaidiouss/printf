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

	(void) format;
	(void) fc;

	c += _putchar((char) va_arg(*ap, int));
	return (c);
}
