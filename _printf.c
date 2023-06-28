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
		switch (format[i])
		{
			case '%':
				count += _format(format[++i], args);
				break;
			default:
				write(1, format + i, 1);
				count++;
				break;
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
	int n, count;
	char *str;
	char ch;

	switch (f)
	{
		case '\0':
			return (-1);
		default:
			break;
	}

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
			count += printstr(str);
			break;
		case 'd':
			n = va_arg(args, int);
			str = tostring(n);
			count += printstr(str);
			break;
		case 'i':
			n = va_arg(args, int);
			str = tostring(n);
			count += printstr(str);
			break;
		case 'b':
			n = va_arg(args, int);
			n = chbase(n, 10, 2);
			str = tostring(n);
			count += printstr(str);
			break;
		case '%':
			ch = '%';
			write(1, &ch, 1);
			count++;
			break;
	}
	return (count);
}
