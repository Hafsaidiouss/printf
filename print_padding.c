#include "main.h"
/**
 * print_padding - prints padding
 * @width: width
 * @digit: digit
 * @s: padding caratere
 * Return: nub of prints
 */
int print_padding(int width, int digit, char s)
{
	int c = 0;
	int i;
	int diff = 0;

	if (width > digit)
        {
               	diff = width - digit;
               	for (i = 0; i < diff; i++)
                       	c = c + _putchar(s);
        }
	return (c);
}
