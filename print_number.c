#include "main.h"

/**
 * print_number - print number using _putchar
 * @n: Number
 * @format: pointer to a str
 * @fc: int
 * Return: count
 */
int print_number(int n, const  char **format, int fc)
{
	char s;
	int c = 0;
	int plus = 0;
	int space = 0;
	int width = 0;
	int digit = 0;

	width = width_check(format, fc);
	plus = flag(format, fc, '+');
	space = flag(format, fc, ' ') * (1 - plus);
	digit = digit_count(n, 10) + plus + space;

	c = c + print_padding(width, digit, ' ');
	if (plus == 1 && n >= 0)
		c = c + _putchar('+');
	if (space == 1 && n >= 0)
		c = c + _putchar(' ');
	s = (n >= 0) - (n < 0);
	if (n < 0)
	{
		_putchar('-');
		c++;
	}
	if (n / 10)
	{
		c = c + print_number((n / 10) * s, format, 0);
	}
	_putchar((n % 10) * s + '0');
	c++;
	return (c);
}
