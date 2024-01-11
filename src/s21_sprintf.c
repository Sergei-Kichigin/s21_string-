#include <stdarg.h>
#include <stdio.h>

#include <string.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);
  char *str1;
  char str2[20] = "";
 
  while (*format) {
    switch (*format) {
      case 'd':
        *str = (va_arg(arg, int));
        // s21_strncat(str, (char*)(char)(va_arg(arg, int)), sizeof(char));
        break;
      case 's':
        str1 = va_arg(arg, char *);
        break;
    }
    s21_strncat(str2, str1, s21_strlen(str1));
    format++;
  }
  va_end(arg);
  strncpy(str, str2, s21_strlen(str2));
  return 0;
}
