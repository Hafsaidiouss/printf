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

	(void) format;
	(void) fc;

	c += _print_str(va_arg(*ap, char *));
	return (c);
}
