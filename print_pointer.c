#include "main.h"
int print_hex_address(long unsigned int n);

/**
 * print_pointer - prints pointer address
 * @p: pointer
 *
 * Return: number of characters printed
 */
int print_pointer(void *p)
{
	return (print_str("0x") + print_hex_address((long unsigned int) p));
}

/**
 * print_hex_address - print hex address
 * @n: address number
 * 
 * Return: number of characters printed
 */
int print_hex_address(long unsigned int n)
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
