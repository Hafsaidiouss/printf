#include "main.h"

/**
 * print_binary - print binary
 * @n:  a number
 * Return: counter
 */
int print_binary(unsigned int n)
{
	int c = 0;

	if (n > 1)
		c = c + print_binary(n / 2);
	_putchar(n % 2 + '0');
	c++;
	return (c);
}
