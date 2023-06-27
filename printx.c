#include "main.h"

/**
 * printstr - print a string
 * @str: a string
 *
 * Return: number of characters printed.
 */
int printstr(char *str)
{
	int i, count;

	i = 0;
	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		count++;
		i++;
	}
	return (count);
}
