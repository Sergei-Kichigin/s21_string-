#include <stdarg.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  const char *temp = str;
  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      format++;

      if (*format == '%') {  // % has no parameters
        *str = *format;
        str++;
      } else {
        s21_size_t lenFormatSpec = s21_strcspn(format, "cdfsu");
        parserParameters parametrs = {false, false, false, 0, -1, '\0'};

        char buffer[BUFFER_SIZE] = {0};

        if (lenFormatSpec == s21_strlen(format)) {  // specifier not found
          va_end(arg);
          return ERROR;
        }

        if (lenFormatSpec > 0) {  // specifier has parameters
          char formatSpec[20] = {0};
          s21_writeNchar(formatSpec, format, lenFormatSpec);
          s21_writeParameters(&parametrs, formatSpec);
          format += lenFormatSpec;
        }

        if (*format == 'c') {
          s21_processChar(buffer, arg);
        } else if (*format == 'd') {
          s21_processInteger(buffer, arg, parametrs);
        } else if (*format == 'f') {
          s21_processFloat(buffer, arg, parametrs);
        } else if (*format == 's') {
          s21_processString(buffer, arg, parametrs);
        } else if (*format == 'u') {
          s21_processUnsignedInteger(buffer, arg, parametrs);
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
  *str = '\0';

  return (int)(str - temp);  // Calculate and return the length
}