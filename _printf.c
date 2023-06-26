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
			putchar(format[i]);
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

	if (f == '\0')
		return (-1);

	count = 0;
	switch (f)
	{
		case 'c':
			putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str)
			{
				i = 0;
				while (str[i] != '\0')
				{
					putchar(str[i]);
					count++;
					i++;
				}
			}
			break;
		case '%':
			putchar('%');
			count++;
			break;
	}
	return (count);
}
