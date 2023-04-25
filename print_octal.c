#include "main.h"

/**
 * print_octal - print number in base 8
 * @n: number
 *
 * Return: number of charater printed
 */
int print_octal(long unsigned int n, const char **format, int fc)
{
	int c = 0;
	int hash = 0;
	int width = 0;
	int digit = 0;

	width = width_check(format, fc);
	hash = flag(format, fc, '#');
	digit = digit_count(n, 8) + hash;
	c = c + print_padding(width, digit, ' ');
	if (hash == 1 && n != 0)
		c = c + _putchar('0');
	if (n > 7)
		c = c + print_octal(n / 8, format, 0);
	_putchar(n % 8 + '0');
	c++;
	return (c);
}
