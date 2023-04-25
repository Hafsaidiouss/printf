#include "main.h"
/**
 * char_counter - char counter
 * @str: char
 * Return: int 
 */
int char_counter(char *str)
{
	int c = 0;

	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		c = c + 1;
		str++;
	}
	return (c);
}
