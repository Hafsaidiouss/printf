#include "main.h"
/**
 * _print_rot - ncodes a string using rot13.
 * @str : string to encode
 * Return: char
 */
int _print_rot(char *str)
{
	char l[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char n[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0;
	int j;
	int c = 0;

	while (str != NULL && str[i] != 0)
	{
		j = 0;
		while (j < 54)
		{
			if (str[i] == l[j])
			{
				_putchar(n[j]);
				c++;
				break;
			}
			j++;
		}
		if (j == 54)
		{
			_putchar(str[i]);
			c++;
		}
		i++;
	}
	return (c);
}
