#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - Printf function
 * @format: format
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	char *str;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			format++;
		}
		if (*format == 'c')
		{
			write(1, format, 1);
		}

		str = va_arg(args, char *);

		if (*format == 's')
		{
			while (str[len])
			{
				len++;
				write(1, str, len);
			}
		}
		if (*format == '%')
		{
			write(1, format, 1);
		}
	}
	va_end(args);
	return (count);
}
