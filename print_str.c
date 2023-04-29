#include "main.h"

/**
 * _print_str - prints string
 * @s: string
 *
 * Return: len str
 */
int _print_str(char *s)
{
	int i = 0;

	if (s == NULL)
		return (_print_str("(null)"));
	while (*s != '\0')
	{
		_putchar(*s);
		i++;
		s++;
	}
	return (i);
}
