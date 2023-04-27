#include "main.h"
int print_hex_address(unsigned long int n);

/**
 * print_pointer - prints pointer address
 * @ap: arg list
 * @format: format
 * @fc: flag count
 *
 * Return: number of characters printed
 */
int print_pointer(va_list *ap, const char *format, int fc)
{
	int space = 0;
	int plus = 0;
	int str;
	void *p = va_arg(*ap, void *);

	plus = flag(format, fc, '+');
	space = flag(format, fc, ' ') * (1 - plus);
	if (plus == 1 && p != NULL)
		_putchar('+');
	if (space == 1 && p != NULL)
		_putchar(' ');
	if (p == NULL)
		return (_print_str("(nil)"));
	str = _print_str("0x");
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
