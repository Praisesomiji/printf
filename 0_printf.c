#include "main.h"

int format(char *fp, va_list args);

/**
 * _printf - produces output according to a format.
 * @format: list of formats' pseudo
 *
 * Return: The number of characters printed excluding the null byte.
 */
int _printf(const char *format, ...)
{
	int i, j, count;
	va_list args;
	char *str;

	if (format == NULL)
		return (-1);

	i = 0;
	count = 0;
	va_start(args, format);

	while (format[i++] != '\0')
	{
		if (format[i] == '%')
		{
			count += format(format[++i], args);
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	putchar('\n');
	}

	va_end(args);
	return (count);
}

/**
 * format - format char(c) and string(s)
 * @fp: pointer to the format
 * @args: variadic arguments
 *
 * Return: Number of characters outputted to standard output.
 */
int format(char *fp, va_list args)
{
	int i, count;
	char *str;

	switch (*fp)
	{
		case 'c':
			putchar(va_args(args, int));
			count++;
			break;
		case 's':
			str = va_args(arg, char *);
			if (str)
			{
				while (str[i] != '\0')
				{
					putchar(str[j]);
					count++;
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
