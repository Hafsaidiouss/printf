#include "main.h"

/**
 * print_number - print number using _putchar
 * @n: Number
 * Return: count
 */
int print_number(int n, const  char **format, int fc)
{
	unsigned int i = n;
	int c = 0;
	int plus = 0;
	int space = 0;

	plus = flag(format, fc, '+');
	space = flag(format, fc, ' ');
	if (plus == 1 && n > 0)
		c = c + _putchar('+');
	if (space == 1 && plus == 0 && n > 0)
		c = c + _putchar(' ');
	if (n < 0)
	{
		_putchar('-');
		c++;
		i = -i;
	}
	if (i / 10)
	{
		c = c + print_number(i / 10, format, 0);
	}
	_putchar(i % 10 + '0');
	c++;
	return (c);
}
