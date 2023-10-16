#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * format: output format
 *
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int character;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
		}
		if (*format == 'c')
		{
				character = va_arg(args, int);
				putchar(character);
				count++;
		}
				else if (*format == 's')
				{
				str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
				}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar(*format);
				count++;
			}
	format++;
	}
	va_end(args);
	return count;
}
