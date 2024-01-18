#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;

  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      format++;

      if (*format == '%') {  // % не имеет параметров
        *str = *format;
        str++;
      } else {
        s21_size_t len_spec = s21_strcspn(format, "cdfsu");

        printf("len_spec: %lu\n", len_spec);

        if (len_spec == s21_strlen(format)) {
          printf("%s", "Uncorrect format\n");
          return ERROR;
        }

        if (len_spec > 0) {
          parserParameters parametrs = {'\0', 0, 0, 0};
          s21_writeParameters(&parametrs, format, len_spec);
          printf("\nflag is: %c\n", parametrs.flag);
          printf("\n%s %lu\n", format, len_spec);
          format += len_spec;
        }

        char buffer[20];

        switch (*format) {
          // char type
          case 'c':
            char charValue = (char)va_arg(arg, int);
            s21_ctoa(charValue, buffer);
            break;
          // int type
          case 'd':
            int intValue = va_arg(arg, int);
            s21_itoa(intValue, buffer);
            break;
          // float type
          case 'f':
            double floatValue = va_arg(arg, double);
            s21_ftoa(floatValue, buffer);
            break;
          // string type
          case 's':
            char *charPtrValue = va_arg(arg, char *);
            s21_writeString(buffer, charPtrValue);
            break;
          // unsigned int type
          case 'u':
            unsigned int unsignedIntValue = va_arg(arg, unsigned int);
            s21_utoa(unsignedIntValue, buffer);
            break;
          case '%':
            s21_ctoa('%', buffer);
            break;
          // unknown type
          default:
            return ERROR;  // need to change !!!
            break;
        }

        s21_writeString(str, buffer);
        str += s21_strlen(buffer);
      }
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  va_end(arg);
  return (int)s21_strlen(str);
}
