#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_hex_lower - print hex lower
 * @n: int
 * @format: pointer to a char
 * @fc: int
 * Return: int
 */
int print_hex_lower(unsigned int n, const char **format, int fc)
{
	int c = 0;
	int hash = 0;
	int width = 0;
	int digit = 0;

	width = width_check(format, fc);
	hash = flag(format, fc, '#');
	digit = digit_count(n, 16) + hash;
	c = c + print_padding(width, digit, ' ');
	if (hash == 1 && n != 0)
		c = c + print_str("0x", NULL, 0);
	if (n > 16)
		c = c + print_hex_lower(n / 16, format, 0);
	if (n % 16 > 9)
		_putchar('a' + n % 16 - 10);
	else
		_putchar(n % 16 + '0');
	c++;
	return (c);
}
