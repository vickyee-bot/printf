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
	int count = 0;
	char specifier;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
		if (specifier == 'c')
		{
			char c = (char)va_arg(args, int);
			write(1, &c, 1);
			count++;
		}
		else if (specifier == 's')
		{
			char *str = va_arg(args, char *);
			int len = 0;
			while (str[len] != '\0')
			{
				len++;
			}
			write(1, str, len);
			count += len;
		}
		else if (specifier == '%')
		{
			write(1, "%", 1);
			count++;
		}
		else if (specifier == 'd' || specifier == 'i')
		{
			int num = va_arg(args, int);
			char num_str[20];
			sprintf(num_str, "%d", num);
			len = 0;
			while (num_str[len] != '\0')
			{
				len++;
			}
			write(1, num_str, len);
			count += len;
		}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}
