#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      format++;

      if (*format == '%') {  // % have not parametrs
        *str = *format;
        str++;
      } else {
        s21_size_t lenFormatSpec = s21_strcspn(format, "cdfsu");
        parserParameters parametrs = {false, false, false, 0, -1, '\0'};

        if (lenFormatSpec == s21_strlen(format)) {  // not found "cdfsu"
          printf("%s", "Uncorrect format\n");
          return ERROR;
        }

        if (lenFormatSpec > 0) {  // specifier have parametrs
          char formatSpec[20];

          s21_writeNchar(formatSpec, format, lenFormatSpec);
          if (s21_writeParameters(&parametrs, formatSpec)) {
            printf("%s", "Uncorrect format\n");
            return ERROR;
          }

          format += lenFormatSpec;
        }

        char buffer[20];  // достаточно 20 символов? с добавлением ширины
                          // какая может быть максимальная ширина

        char charValue;
        int intValue;
        double doubleValue;
        unsigned int unsignedIntValue;
        char *stringValue;

        switch (*format) {
          // char type
          case 'c':
            charValue = (char)va_arg(arg, int);
            s21_ctoa(charValue, buffer);
            break;
          // int type
          case 'd':
            intValue = va_arg(arg, int);
            s21_itoa(parametrs, buffer, intValue);
            break;
          // float type
          case 'f':
            doubleValue = va_arg(arg, double);
            s21_ftoa(parametrs, buffer, doubleValue);
            break;
          // string type
          case 's':
            stringValue = va_arg(arg, char *);
            s21_stoa(parametrs, buffer, stringValue);
            break;
          // unsigned int type
          case 'u':
            unsignedIntValue = va_arg(arg, unsigned int);
            s21_utoa(parametrs, buffer, unsignedIntValue);
            break;
          // unknown type
          default:
            return ERROR;  // need to change !!!
            break;
        }

        s21_addFormat(parametrs, buffer);
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
