#include "main.h"
#include <stdio.h>

/**
 * width_check - check the value of the width
 * @format: format
 * @fc: flag count
 *
 * Return: the value of the width
 */
int width_check(const char **format, int fc)
{
	int i;
	int width = 0;
	int d = 1;
	int c = 0;
	char n;
	
	for (i = 1; i <= fc; i++)
	{
		n = *((*format) - i) - '0';
		if (n >= 0 && n <= 9)
		{
			c = 1;
			width = width + n * d;
			d = d * 10;
		}
		else 
			if (c == 1)
				break;
	}
	return (width);
}
