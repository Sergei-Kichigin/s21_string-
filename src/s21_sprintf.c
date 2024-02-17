#include <stdarg.h>
#include <stdio.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  char *temp = str;
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

        char buffer[1024] = {0};

        if (lenFormatSpec == s21_strlen(format)) {  // not found "cdfsu"
          return ERROR;
        }

        if (lenFormatSpec > 0) {  // specifier have parametrs
          char formatSpec[20] = {0};
          s21_writeNchar(formatSpec, format, lenFormatSpec);
          s21_writeParameters(&parametrs, formatSpec);
          format += lenFormatSpec;
        }

        switch (*format) {
          case 'c':
            s21_processChar(buffer, arg);
            break;
          case 'd':
            s21_processInteger(buffer, arg, parametrs);
            break;
          case 'f':
            s21_processFloat(buffer, arg, parametrs);
            break;
          case 's':
            s21_processString(buffer, arg, parametrs);
            break;
          case 'u':
            s21_processUnsignedInteger(buffer, arg, parametrs);
            break;
        }
        str += s21_addFormat(parametrs, buffer, str);
      }
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  va_end(arg);
  // printf("\n RETURN - %ld\n", s21_strlen(temp));
  return (int)s21_strlen(temp);
}
