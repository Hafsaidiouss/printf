#include "main.h"

/**
 * print_str - prints string
 * @str: string
 * @format: pointer to a string
 * @fc: int
 * Return: len str
 */
int print_str(char *str, const char **format, int fc)
{
	int i = 0;
	int width = 0;
	int char_c = 0;
	int c = 0;

	width = width_check(format, fc);
	char_c = char_counter(str);
	c = c + print_padding(width, char_c, ' ');
	if (str == NULL)
		return (print_str("(null)", NULL, 0));
	while (*str != '\0')
	{
		_putchar(*str);
		i++;
		str++;
	}
	return (i);
}
