#include "main.h"

/**
 * flag_count - counts flags
 * @str: string
 * Return: flag count
 */
int flag_count(const char *str)
{
	char *init = "#0- +'I";
	int c = 0;
	char *flag;

	while (*str != '\0')
	{
		flag = init;
		while (*flag != '\0')
		{
			if (*str == *flag)
			{
				c++;
				break;
			}
			flag++;
		}
		if (*flag == '\0')
			return (c);
		str++;
	}
	return (c);
}
