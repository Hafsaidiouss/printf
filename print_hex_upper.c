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
        unsigned long int pow;
        char digit;
        unsigned long int n;

	int hash = flag(format, fc, '#');
	int size = get_size(format, fc);

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

	if (hash == 1)
		c += _print_str("0X");
        for (; d - 1 > 0; d--)
        {
                pow = (long int) _pow(16, d - 1);
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

        return (c);
}

