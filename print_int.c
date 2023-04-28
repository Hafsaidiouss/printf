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

	int i;
	int s;
	int p;
	int c = 0;
	int sign = 1;
	int d;
	long int pow;
	int digit;
	long int n;


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
	if (n == 0 && precision == 0 && flag(format, fc, '.'))
		return (0);
	
	d = digit_count_signed(n, 10);
	p = (precision > d) ? precision - d : 0;
	sign = ((n >= 0) ? 1 : -1);
	s = (sign < 0) ? 1 : 0;

	if (minus == 0 && zero == 0)
		c += print_padding(width, d + s + p, pc);
	if (sign == -1)
		c += _putchar('-');
	else
	{
		if (plus == 1)
			c += _putchar('+');
		else if (space == 1)
			c += _putchar(' ');
	}
	if (minus == 0 && zero == 1)
		c += print_padding(width, d + s + p, pc);
	c += print_padding(p, 0, '0');
	for (i = d; i > 0; i--)
	{
		pow = _pow(10, i - 1);
                digit = (n / pow) * sign;
                c += _putchar(digit + '0');
                n = n +  ((digit * pow) * (-sign));
	}
	if (minus == 1)
		c += print_padding(width, d + s + p, pc);

	return (c);

}
