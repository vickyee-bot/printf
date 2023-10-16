#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
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
	int character, len = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				character = va_arg(args, int);
				write(1, &character, 1);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (str[len])
				{
					len++;
					write(1, str, len);
					count += len;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
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
