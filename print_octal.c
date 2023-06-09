#include "main.h"
#include <stdarg.h>

/**
 * print_octal - print number in octal using _putchar
 * @ap: arg list
 * @format: pointer to a sr
 * @fc: int
 *
 * Return: count
 */
int print_octal(va_list *ap, const char *format, int fc)
{
	int c = 0, i, d, p, digit;
	unsigned long int pow, n;
	int hash = flag(format, fc, '#');
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';
	int size = get_size(format, fc);
	int width = get_width(ap, format, fc);
	int precision = get_precision(ap, format, fc);

	if (size == 1)
		n = va_arg(*ap, unsigned long);
	else if (size == 0)
		n = va_arg(*ap, unsigned int);
	else if (size == -1)
		n = (unsigned short) va_arg(*ap, unsigned int);
	if (n == 0 && precision == 0 && flag(format, fc, '.'))
		return (0);
	d = digit_count_unsigned_int(n, 8);
	p = (precision > d) ? precision - d : 0;
	if (minus == 0)
		c += print_padding(width, d + p, pc);
	if (hash == 1 && n != 0)
		c += _putchar('0');
	c += print_padding(p, 0, '0');
	for (i = d; i > 0; i--)
	{
		pow = _pow(8, i - 1);
		digit = (n / pow);
		c += _putchar(digit + '0');
		n -= digit * pow;
	}
	if (minus == 1)
		c += print_padding(width, d + p, pc);
	return (c);
}

