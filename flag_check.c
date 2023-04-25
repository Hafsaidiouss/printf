#include "main.h"
#include <stdio.h>

/**
 * flag - check for flag
 * @format: format
 * @fc: flag count
 * @flag: flag
 *
 * Return: 1 if hash exist, 0 otherwies
 */
int flag(const char **format, int fc, char flag)
{
	for (; fc > 0; fc--)
	{
		if (*((*format) - fc) == flag)
			return (1);
	}
	return (0);
}
