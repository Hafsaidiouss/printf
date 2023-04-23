#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_hex_lower - print hex lower
 * @n: int
 * Retunr: int
 */
int print_hex_lower (unsigned int n)
{
	int c = 0;

	if (n > 16)
		c = c + print_hex_lower(n / 16);
	if (n % 16 > 9)
		_putchar('a' + n % 16 - 10);
	else
		_putchar(n % 16 + '0');
	c++;
	return (c);
}
