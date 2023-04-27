#include "main.h"
/**
 * digit_count - counts the numbers of digit
 * @b: base of the number
 * @n: number
 * Return: digit count
 */
int digit_count(long int n, int b)
{
	int c = 0;

	if (n == 0)
		return (1);
	while (n != 0)
	{
		c++;
		n = n / b;
	}
	return (c);
}
