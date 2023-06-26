#include "main.h"

int _format(char f, va_list args);

/**
 * _printf - produces output according to a format.
 * @format: list of formats' pseudo
 *
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list args;

	if (format == NULL)
		return (-1);

	i = 0;
	count = 0;
	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += _format(format[++i], args);
		}
		else
		{
			write(1, format + i, 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * _format - format char(c) and string(s)
 * @f: format
 * @args: variadic arguments
 *
 * Return: Number of characters outputted to standard output.
 */
int _format(char f, va_list args)
{
	int i, count;
	char *str;
	char ch;

	if (f == '\0')
		return (-1);

	count = 0;
	switch (f)
	{
		case 'c':
			ch = va_arg(args, int);
			write(1, &ch, 1);
			count++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str)
			{
				i = 0;
				while (str[i] != '\0')
				{
					write(1, str + i, 1);
					count++;
					i++;
				}
			}
			else
			{
				write(1, "(null)", 6);
				count += 6;
			}
			break;
		case '%':
			ch = '%';
			write(1, &ch, 1);
			count++;
			break;
	}
	return (count);
}
