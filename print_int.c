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
	int plus = flag(format, fc, '+');
	int space = flag(format, fc, ' ') * (1 - plus);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';

	int size = get_size(format, fc);
	int precision = get_precision(ap, format, fc);
	int width = get_width(ap, format, fc);

	int i;
	int c = 0;
	int sign = 1;
	int d;
	long int pow;
	int digit;
	long int n;

	(void) precision;

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
	
	d = digit_count_signed(n, 10);
	sign = ((n >= 0) ? 1 : -1);

	if (minus == 0 && zero == 0)
                {
                        if (sign == 1)
                                c += print_padding(width, d, pc);
                        else
                                c += print_padding(width, d + 1, pc);
                }
	if (sign == -1)
	{
		c += _putchar('-');
	}
	else
	{
		if (plus == 1)
			c += _putchar('+');
		else if (space == 1)
			c += _putchar(' ');
	}
	if (minus == 0 && zero == 1)
                {
                        if (sign == 1)
                                c += print_padding(width, d, pc);
                        else
                                c += print_padding(width, d + 1, pc);
                }

	for (i = d; i > 0; i--)
	{
		pow = _pow(10, i - 1);
                digit = (n / pow) * sign;
                c += _putchar(digit + '0');
                n = n +  ((digit * pow) * (-sign));
	}
	if (minus == 1)
	{
		 if (sign == 1)
                                c += print_padding(width, d, pc);
                        else
                                c += print_padding(width, d + 1, pc);
	}
	
	return (c);

}
