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
        int c = 0;
        int d;
        long int pow;
        int digit;
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
			n =(unsigned short) va_arg(*ap, unsigned int);
			break;
	}

        d = digit_count(n, 8);

	if (hash == 1 && n != 0)
		c += _putchar('0');
        for (; d > 0; d--)
        {
                pow = _pow(8, d - 1);
                digit = (n / pow);
                c += _putchar(digit + '0');
                n -= digit * pow;
        }

        return (c);
}

