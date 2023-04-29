#include <stdarg.h>
#include "main.h"

/**
 * print_hex_lower - print number in lowercase hexadecimal using _putchar
 * @ap: arg list
 * @format: pointer to a sr
 * @fc: int
 *
 * Return: count
 */
int print_hex_lower(va_list *ap, const char *format, int fc)
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
	d = digit_count_unsigned_int(n, 16);
	p = (precision > d) ? precision - d : 0;
	if (n == 0 && precision == 0 && flag(format, fc, '.'))
		return (0);
	if (minus == 0)
		c += print_padding(width, d + p + 2 * hash, pc);
	if (hash == 1 && n != 0)
		c += _print_str("0x");
	c += print_padding(p, 0, '0');
	for (i = d; i > 0; i--)
	{
		pow = (long int) _pow(16, i - 1);
		digit = n / pow;
		n %= pow;
		if (digit > 9)
			c += _putchar(digit - 10 + 'a');
		else
			c += _putchar(digit + '0');
	}
	if (minus == 1)
		c += print_padding(width, d + p + 2 * hash, pc);
	return (c);
}

