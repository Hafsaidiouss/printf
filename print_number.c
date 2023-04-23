#include "main.h"

/**
 * print_number - print number using _putchar
 * @n: Number
 * Return: count
 */
int print_number(int n)
{
	unsigned int i = n;
	int c = 0;

	if (n < 0)
	{
		_putchar('-');
		c++;
		i = -i;
	}
	if (i / 10)
	{
		c = c + print_number(i / 10);
	}
	_putchar(i % 10 + '0');
	c++;
	return (c);
}
