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
        int d;
        long int pow;
        int digit;
        unsigned long int n;

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

        d = digit_count(n, 10);

        for (; d - 1 > 0; d--)
        {
                pow = (long int) _pow(10, d - 1);
                digit = n / pow;
                c += _putchar(digit + '0');
                n %= pow;
        }

        c += _putchar(n + '0');

        return (c);
}

