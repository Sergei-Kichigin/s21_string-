#include <stdarg.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);

    while(*format){
        switch(*format) {
            case 'd':
                *str = (va_arg(arg, int));
                //s21_strncat(str, (char*)(char)(va_arg(arg, int)), sizeof(char));
                break;
        }
        format++;
    }
    va_end(arg);
    s21_strncat(str, "/0", sizeof(char));
    return 0;
}
