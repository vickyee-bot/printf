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

	if (format == NULL)
	{
		return (1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
		if (*format == '\0')
			break;

		if (*format == 'c')
		{
			int character = va_arg(args, int);
			write(1, &character, 1);
			count++;
		}

		str = va_arg(args, char *);

		if (*format == 's')
		{
			str = va_arg(args, char *);
			while (str[len] != '\0')
			{
				len++;
				write(1, str, len);
				count += len;
			}
		}
		if (*format == '%')
		{
			write(1, format, 1);
			count++;
		}
		if (*format == 'd' || *format == 'i')
		{
			int num = va_arg(args, int);
			char buffer[20];
			int len = snprintf(buffer, sizeof(buffer), "%d", num);
			write(1, buffer, len);
			count += len;
		}
		}
		format++;
	}
	va_end(args);
	return (count);
}
