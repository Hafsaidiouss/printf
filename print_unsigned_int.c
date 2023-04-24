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
	(void) fc; /*to be removed*/

	if (i / 10)
	{
		c = c + print_number(i / 10, format, 0);
	}
	_putchar(i % 10 + '0');
	c++;
	return (c);
}
