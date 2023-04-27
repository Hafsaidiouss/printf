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
	int c = 0;
	int d;
	int plus = flag(format, fc, '+');
	int space = flag(format, fc, ' ') * (1 - plus);
	int width = get_width(ap, format, fc);
	void *p = va_arg(*ap, void *);

	plus = flag(format, fc, '+');
	space = flag(format, fc, ' ') * (1 - plus);

	if (p == NULL)
        {
                c += print_padding(width, 5, ' ');
                c += _print_str("(nil)");
                return (c);
        }

	d = digit_count_unsigned((unsigned long int) p, 16);
	c += print_padding(width, d, ' ');
	if (plus == 1 && p != NULL)
		c += _putchar('+');
	if (space == 1 && p != NULL)
		c += _putchar(' ');

	c += _print_str("0x");
	c += print_hex_address((unsigned long int) p);
	return (c);
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
