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
        char buffer[BUFFER_SIZE] = {0};
        s21_size_t lenFormatSpec = 0;
        parserParameters parameters = {false, false, false, 0, -1, '\0'};

        s21_getLenFormatSpec(format, &lenFormatSpec);

        if (lenFormatSpec == s21_strlen(format)) {  // specifier not found
          va_end(arg);
          return -ERROR;
        }

        s21_specifierParametersParsing(format, lenFormatSpec, &parameters);
        format += lenFormatSpec;

        s21_checkSpecifier(format, buffer, arg, parameters);
        str += s21_addFormat(parameters, buffer, str);
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