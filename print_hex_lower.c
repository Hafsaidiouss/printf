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
        int c = 0;
        int d;
        long int pow;
        char digit;
        unsigned long int n = va_arg(*ap, unsigned long int);

	(void) format;
	(void) fc;

        d = digit_count(n, 16);

        for (; d - 1 > 0; d--)
        {
                pow = (long int) _pow(16, d - 1);
                digit = n / pow;
                n %= pow;
                if (digit > 9)
                        c += _putchar(digit - 10 + 'a');
                else
                        c += _putchar(digit + '0');
        }

        if (n > 9)
                c += _putchar(n - 10 + 'a');
        else
                c += _putchar(n + '0');

        return (c);
}

