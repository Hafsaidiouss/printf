#include "main.h"

/**
 * print_octal - print number in base 8
 * @n: number
 *
 * Return: number of charater printed
 */
int print_octal(unsigned int n)
{
	int c = 0;

	if (n > 7)
		c = c + print_octal(n / 8);
	_putchar(n % 8 + '0');
	c++;
	return (c);
}
