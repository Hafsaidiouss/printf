#include "main.h"

/**
 * get_precision - get field precision
 * @ap: arg list
 * @format: format
 * @fc: flag count
 *
 * Return: field width
 */
int get_precision(va_list *ap, const char *format, int fc)
{
	int start = 0;
	int precision = 0;
	int i;

	format = format - fc;
	for (i = 0; i < fc; i++)
	{
		if (format[i] == '*' && start == 0 && format[i - 1] == '.')
			return (va_arg(*ap, int));
		else if (_isdigit(format[i]) && start == 0 && format[i - 1] == '.')
			start = 1;
		else if (!_isdigit(format[i]) && start == 1)
			break;

		if (start == 1)
			precision = precision * 10 + (format[i] - '0');
	}
	return (precision);
}
