#include "main.h"

/**
 * print_unsigned_int - print number using _putchar
 * @n: Number
 * Return: count
 */
int print_unsigned_int(unsigned int n, const char **format, int fc)
{
	unsigned int i = n;
	int c = 0;
	int width = 0;
	int digit = 0;

	width = width_check(format, fc);
	digit = digit_count(n, 10);
	c = c + print_padding(width, digit, ' ');
	if (i / 10)
	{
		c = c + print_number(i / 10, format, 0);
	}
	_putchar(i % 10 + '0');
	c++;
	return (c);
}
