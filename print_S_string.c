#include "main.h"

/**
 * print_S_string - print nnumber in base 16
 * @str: string
 * @format: pointer to a str
 * @fc: int
 *
 * Return: number of character printed
 */
int print_S_string(char *str, const char **format, int fc)
{
	int c = 0;
	int width = 0;
	int char_c = 0;

	width = width_check(format, fc);
	char_c = char_counter(str);
	c = c + print_padding(width, char_c, ' ');
	while (*str != '\0')
	{
		if ((*str < 32 && *str > 0) || *str >= 127)
		{
			print_str("\\x", NULL, 0);
			c = c + 2;
			if (*str < 16)
			{
				_putchar('0');
				c++;
				c = c + print_hex_upper(*str, NULL, 0);
			}
			else
			{
				c = c + print_hex_upper(*str, NULL, 0);
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

