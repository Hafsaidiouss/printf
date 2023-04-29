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
	int size = get_size(format, fc);
	int precision = get_precision(ap, format, fc);
	int width = get_width(ap, format, fc);
	int plus = flag(format, fc, '+');
	int space = flag(format, fc, ' ') * (1 - plus);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';
	int i, p, c = 0, sign = 1, d, digit;
	long int pow, n;

	if (size == 1)
		n = va_arg(*ap, unsigned long);
	else if (size == 0)
		n = va_arg(*ap, unsigned int);
	else if (size == -1)
		n = (unsigned short) va_arg(*ap, unsigned int);
	if (n == 0 && precision == 0 && flag(format, fc, '.'))
		return (0);
	d = digit_count_signed_int(n, 10);
	p = (precision > d) ? precision - d : 0;
	sign = ((n >= 0) ? 1 : -1);
	if (minus == 0 && zero == 0)
		c += print_padding(width, d + (sign == -1) + p, pc);
	if (sign == -1)
		c += _putchar('-');
	else
		c += (plus == 1) ? _putchar('+') : ((space == 1) ? _putchar(' ') : 0);
	if (minus == 0 && zero == 1)
		c += print_padding(width, d + (sign == -1) + p, pc);
	c += print_padding(p, 0, '0');
	for (i = d; i > 0; i--)
	{
		digit = (n / _pow(10, i - 1)) * sign;
		c += _putchar(digit + '0');
		n = n +  ((digit * _pow(10, i - 1)) * (-sign));
	}
	if (minus == 1)
		c += print_padding(width, d + (sign == -1) + p, pc);
	return (c);
}
