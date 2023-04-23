#include "main.h"

/**
 * print_str - prints string
 * @str: string
 * Return: len str
 */
int print_str(char *str)
{
	int i = 0;

	if (str == NULL)
		return (print_str("(null)"));
	while (*str != '\0')
	{
		_putchar(*str);
		i++;
		str++;
	}
	return (i);
}
