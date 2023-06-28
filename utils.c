#include "main.h"
#include <string.h>

int _itostr(const int num, int sz, int *len, char **const str);
void _chtod(const int num, const int base, int count, int *output);
void _chfrod(const int num, const int base, int count, int *output);

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

	if (!_itostr(num, size, &len, &str))
		return (NULL);

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
int _itostr(const int num, int sz, int *len, char **str)
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
			return (0);
		(*str)[0] = 0;
		(*str)[sz] = '\0';
	}
	/* base case */
	m = num % 10;
	ch = m + '0';
	(*str)[*len] = ch;
	*len += 1;

	return (*len);
}

/**
 * changebase - change the base of a number
 * @num: an integer
 * @sbase: source base
 * @dbase: destination base
 *_chfrod(num, dbase, &count, &output);
 * Return: Number in new base.
 */
int chbase(int num, const int sbase, const int dbase)
{
	int count, output;

	count = 0;
	output = 0;
	if (sbase == 10)
	{
		_chfrod(num, dbase, count, &output);
	}
	else if (dbase == 10)
	{
		_chtod(num, sbase, count, &output);
	}
	else
	{
		_chfrod(num, dbase, count, &output);
		_chtod(num, sbase, count, &output);
	}

	return (output);
}

/**
 * _chfrod - change from decimal to given base
 * @num: 
 * @base: the base
 * @count: counts down from zero and raises the power of each digit
 * @output: pointer to the accumulated result
 *
 * Return: Nothing.
 */
void _chfrod(const int num, const int base, int count, int *output)
{
	int n, m;

	if (num >= base)
	{
		n = num / base;
		_chfrod(n, base, count + 1, output);
	}

	m = num % base;
	*output += m * _topower(10, count);
}

/**
 * _chtod - change base to base 10 (decimal)
 * @num: the number
 * @base: the base
 * @count: counts up from zero and raises the power of each digit
 * @output: pointer to the accumulated result
 *
 * Return: Nothing.
 */
void _chtod(const int num, const int base, int count, int *output)
{
	int n, m;

	if (num >= 10)
	{
		n = num / 10;
		_chtod(n, base, count + 1, output);
	}
	m = num % 10;
	*output += m * _topower(base, count);
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
	int n = 1;

	while (x--)
		n *= b;

	return (n);
}

