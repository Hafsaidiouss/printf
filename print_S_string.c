#include "main.h"

/**
 * print_hex - print nnumber in base 16
 * @n: number
 * @format: pointer to a str
 * @fc: int
 * Return: number of character printed
 */
int print_hex(unsigned char n)
{
	int c = 0;
	int d;

	if (n > 15)
		c = c + print_hex(n / 16);
	d = n % 16;
	if (d < 10)
		_putchar(d + '0');
	else
		_putchar(d + 'A' - 10);
	c++;
	return (c);
}

/**
 * print_S_string - print nnumber in base 16
 * @ap: arg list
 * @format: pointer to a str
 * @fc: int
 *
 * Return: number of character printed
 */
int print_S_string(va_list *ap, const char *format, int fc)
{
	int c = 0;
	char *str = va_arg(*ap, char *);

	(void) format;
	(void) fc;

	while (*str != '\0')
	{
		if ((*str < 32 && *str > 0) || *str >= 127)
		{
			_print_str("\\x");
			c = c + 2;
			if (*str < 16)
			{
				_putchar('0');
				c++;
				c = c + print_hex(*str);
			}
			else
			{
				c = c + print_hex(*str);
			}
		}
		else
		{
			_putchar(*str);
			c++;
		}
		str++;
	}
	return (c);
}

