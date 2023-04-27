#include "main.h"
/**
 * _print_rev - prints a string, in reverse, followed by a new line.
 * @s: string
 * Return: c
 */
int _print_rev(char *s)
{
	int i = 0;
	int j;
	int c = 0;

	while (*(s + i) != 0)
	{
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(*(s + j));
		c++;
	}
	return (c);
}
