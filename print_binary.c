#include "main.h"
#include <stdarg.h>

/**
 * print_binary - print number in binary using _putchar
 * @ap: arg list
 * @format: pointer to a sr
 * @fc: int
 *
 * Return: count
 */
int print_binary(va_list *ap, const char *format, int fc)
{
        int c = 0;
        int d;
        unsigned long int pow;
        int digit;
        long unsigned int n = va_arg(*ap, long unsigned int);

	(void) (format);
        (void) (fc);


        d = digit_count_unsigned(n, 2);

        for (; d - 1 > 0; d--)
        {
                pow = 1 << (d - 1);
                digit = n & pow ? 1 : 0;
                c += _putchar(digit + '0');
        }

        c += _putchar(n & 1 ? '1' : '0');

        return (c);
}

