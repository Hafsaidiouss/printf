#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - handler for %i and %d
 * @ap: arg list
 * @format: format
 * @fc: flag count
 *
 * Return: char count
 */
int print_int(va_list *ap, const char *format, int fc)
{

	/* FLAGS */
	int size = get_size(format, fc);
	int precision;
	int lenght;

	int c = 0;
	int sign = 1;
	int d;
	long int pow;
	int digit;
	long int n;

	(void) precision;
	(void) lenght;

	switch (size)
	{
		case 1:
			n = va_arg(*ap, long);
			break;
		case -1:
			n = (short) va_arg(*ap, int);
			break;
		case 0:
			n = va_arg(*ap, int);
			break;
	}
	
	d = digit_count(n, 10);
	sign = ((n >= 0) ? 1 : -1);

	if (sign == -1)
		c += _putchar('-');
	for (; d > 0; d--)
	{
		pow = _pow(10, d - 1);
                digit = (n / pow) * sign;
                c += _putchar(digit + '0');
                n = n +  ((digit * pow) * (-sign));
	}
	
	return (c);

}
