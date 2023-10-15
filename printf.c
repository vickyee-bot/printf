#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    const char *ptr;
    int count = 0;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ++ptr) {
        if (*ptr == '%') {
            ++ptr;
            if (*ptr == '\0')
                break;

            if (*ptr == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                ++count;
            } else if (*ptr == 's') {
                const char *s = va_arg(args, const char *);
                while (*s != '\0') {
                    putchar(*s);
                    ++s;
                    ++count;
                }
            } else if (*ptr == '%') {
                putchar('%');
                ++count;
            }
        } else {
            putchar(*ptr);
            ++count;
        }
    }

    va_end(args);
    return count;
}

int main() {
    int num = 42;
    _printf("Hello, %s! This is a %c test. Number: %d. Percent: %%\n", "world", 'C', num);
    return 0;
}
