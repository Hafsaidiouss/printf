#include "main.h"

/**
 * get_size - get format size
 * @format: format
 * @fc: flag count
 *
 * Return: 1 if l -1 if h 0 otherwise
 */
int get_size(const char *format, int fc)
{
	if (flag(format, fc, 'l'))
		return (1);
	if (flag(format, fc, 'h'))
		return (-1);
	return (0);
}
