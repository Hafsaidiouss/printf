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
        unsigned long int n = va_arg(*ap, unsigned long int);

	(void) format;
	(void) fc;

        d = digit_count(n, 8);

        for (; d > 0; d--)
        {
                pow = _pow(8, d - 1);
                digit = (n / pow);
                c += _putchar(digit + '0');
                n -= digit * pow;
        }

        return (c);
}

