#include "main.h"

/**
 * print_hex_upper - print nnumber in base 16
 * @n: number
 *
 * Return: number of character printed
 */
int print_hex_upper(unsigned int n, const char **format, int fc)
{
	int c = 0;
	int d;
	int hash = 0;

	hash = flag(format, fc, '#'); 
	if (hash)
		c = c + print_str("0X");

	if (n > 15)
		c = c + print_hex_upper(n / 16, format, 0);
	d = n % 16;
	if (d < 10)
		_putchar(d + '0');
	else
		_putchar(d + 'A' - 10);
	c++;
	return (c);
}
