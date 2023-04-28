#include "main.h"
#include <stdarg.h>

/**
 * print_hex_upper - print number in uppercase hexadecimal using _putchar
 * @ap: arg list
 * @format: pointer to a sr
 * @fc: int
 *
 * Return: count
 */
int print_hex_upper(va_list *ap, const char *format, int fc)
{
        int c = 0;
        int d;
	int i;
	int p;
        unsigned long int pow;
        char digit;
        unsigned long int n;

	int hash = flag(format, fc, '#');
	int minus = flag(format, fc, '-');
	int zero = flag(format, fc, '0') * (1 - minus);
	char pc = zero ? '0' : ' ';

	int size = get_size(format, fc);
	int width = get_width(ap, format, fc);
	int precision = get_precision(ap, format, fc);

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

        d = digit_count_unsigned(n, 16);
	p = (precision > d) ? precision - d : 0;
	if (minus == 0)
		c += print_padding(width, d + p + 2 * hash, pc);

	if (hash == 1)
		c += _print_str("0X");
	p = (precision > d) ? precision - d : 0;
        for (i = d; i - 1 > 0; i--)
        {
                pow = (long int) _pow(16, i - 1);
                digit = n / pow;
                n %= pow;
                if (digit > 9)
                        c += _putchar(digit - 10 + 'A');
                else
                        c += _putchar(digit + '0');
        }

        if (n > 9)
                c += _putchar(n - 10 + 'A');
        else
                c += _putchar(n + '0');

	if (minus == 1)
		c += print_padding(width, d + p + 2 * hash, pc);
        return (c);
}

