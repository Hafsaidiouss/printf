#include "main.h"
int print_hex_address(unsigned long int n);

/**
 * print_pointer - prints pointer address
 * @p: pointer
 *
 * Return: number of characters printed
 */
int print_pointer(void *p, const char **format, int fc)
{
	int space = 0;
	int plus = 0;
	int str;

	plus = flag(format, fc, '+');
	space = flag(format, fc, ' ') * (1 - plus);
	if (plus == 1 && p != NULL)
		_putchar('+');
	if (space == 1 && p != NULL)
		_putchar(' ');
	if (p == NULL)
		return (print_str("(nil)", NULL, 0));
	str = print_str("0x", NULL, 0;
	return (space + plus + str + print_hex_address((unsigned long int) p));
}

/**
 * print_hex_address - print hex address
 * @n: address number
 * Return: number of characters printed
 */
int print_hex_address(unsigned long int n)
{
	int c = 0;

	if (n > 16)
		c = c + print_hex_address(n / 16);
	if (n % 16 > 9)
		_putchar('a' + n % 16 - 10);
	else
		_putchar(n % 16 + '0');
	c++;
	return (c);
}
