#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...) {
    int printed_chars = 0;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];
    va_list args;
    int i;

    if (format == NULL)
        return -1;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        } else {
            print_buffer(buffer, &buff_ind);
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(args);

    return printed_chars;
}
