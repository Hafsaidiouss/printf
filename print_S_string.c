#include "main.h"

/**
 * print_S_string - print nnumber in base 16
 * @str: string
 *
 * Return: number of character printed
 */
int print_S_string(char *str)
{
	int c = 0;

	while (*str != '\0')
	{
		if ((*str < 32 && *str > 0) || *str >= 127)
		{
			print_str("\\x");
			c = c + 2;
			if (*str < 16)
			{
				_putchar('0');
				c++;
				c = c + print_hex_upper(*str);
			}
			else
			{
				c = c + print_hex_upper(*str);
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

