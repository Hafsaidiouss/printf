#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned_int - print number using _putchar
 * @ap: arg list
 * @format: pointer to a sr
 * @fc: int
 *
 * Return: count
 */
int print_unsigned_int(va_list *ap, const char *format, int fc)
{
	int c = 0;
	int i;
	int p;
	int d;
	unsigned long int pow;
	int digit;
	unsigned long int n;
	int size = get_size(format, fc);
	int width = get_width(ap, format, fc);
	int precision = get_precision(ap, format, fc);
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';

	switch (size)
	{
		case 1:
			n = va_arg(*ap, unsigned long);
			break;
		case 0:
			n = va_arg(*ap, unsigned int);
			break;
		case -1:
			n = (unsigned short) va_arg(*ap, unsigned int);
			break;
	}
	if (n == 0 && precision == 0 && flag(format, fc, '.'))
		return (0);
	d = digit_count_unsigned(n, 10);
	p = (precision > d) ? precision - d : 0;
	if (minus == 0)
		c += print_padding(width, d + p, pc);
	c += print_padding(p, 0, '0');
	for (i = d; i > 0; i--)
	{
		pow = _pow(10, i - 1);
		digit = (n / pow);
		c += _putchar(digit + '0');
		n -= digit * pow;
	}
	if (minus == 1)
		c += print_padding(width, d + p, pc);

	return (c);
}

