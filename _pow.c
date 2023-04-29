/**
 * _pow - calculate power
 * @a: number
 * @b: number
 *
 * Return: a^b
 */
unsigned long int _pow(unsigned long int a, int b)
{
	if (b == 0)
		return (1);
	return (a * _pow(a, b - 1));
}
