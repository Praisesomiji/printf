#include "main.h"
#include <string.h>

void _itostr(const int num, int sz, int *len, char **const str);

/**
 * tostring - convert int to string
 * @num: decimal number
 *
 * Return: Length of string excluding \0.
 */
char *tostring(int num)
{
	int len, size, sign;
	char *str;

	len = 0;
	size = 0;
	str = NULL;
	sign = 1;

	if (num < 0)
	{
		sign = -1;
		len = 1;
		size = 1;
		num *= sign;
	}

	_itostr(num, size, &len, &str);

	if (sign == -1)
		str[0] = '-';

	return (str);
}

/**
 * _itostr - convert decimal number to string
 * @num: the decimal number
 * @sz: keeps tab on size of string
 * @len: indexes each string from 0 up, final index+1 is the length.
 * @str: pointer to the converted string
 *
 * Return: Length of Converted String (excepting '\0')
 */
void _itostr(const int num, int sz, int *len, char **str)
{
	int n, m;
	char ch;

	if (num >= 10)
	{
		n = num / 10;
		_itostr(n, sz, len, str);
	}
	else /* num (same as m) would be first digit from the left */
	{
		*str = malloc(sz + 1);
		if (!str)
			exit(98);
		(*str)[0] = 0;
		(*str)[sz] = '\0';
	}
	/* base case */
	m = num % 10;
	ch = m + '0';
	(*str)[*len] = ch;
	*len += 1;
}

/**
 * _chbase - change the base of a number
 * @num: the number
 * @base: the base
 * @count: counts up from zero and raises the power of each digit
 * @sumptr: pointer to the accumulated result
 *
 * Return: Nothing.
 */
void _chbase(const int num, const int base, const int count, int *const sumptr)
{
	int n, m;

	if (num > 10)
	{
		n = num / 10;
		_chbase(n, base, count + 1, sumptr);
	}
	m = num % 10;
	*sumptr += m * _topower(base, count);
}

/**
 * _topower - raise a number to the power of a number
 * @b: number to be raised (base)
 * @x: power to raise number to (exponent)
 *
 * Return: Exponent.
 */
int _topower(int b, int x)
{
	int n = b;

	while (x--)
		n *= b;

	return (n);
}


