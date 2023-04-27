#include "main.h"

/**
 * print_rot_string - print string in reverse
 * @ap: arg list
 * @format: format
 * @fc: flag count
 *
 * Return: char count
 */
int print_rot_string(va_list *ap, const char *format, int fc)
{
        char *s = va_arg(*ap, char *);

	(void) format;
	(void) fc;

        return (_print_rot(s));
}
