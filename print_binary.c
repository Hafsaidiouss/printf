#include "main.h"

/**
 * print_binary - print binary
 * @n:  a number
 * @format: ^poiter to a str
 * @fc: int
 * Return: counter
 */
int print_binary(unsigned int n, const char **format, int fc)
{
	int c = 0;

	if (n > 1)
		c = c + print_binary(n / 2, format, fc);
	_putchar(n % 2 + '0');
	c++;
	return (c);
}
