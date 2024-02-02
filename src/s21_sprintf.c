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

        char buffer[20];
        s21_memset(buffer, 0, sizeof(buffer));

        char charValue = 0;

        int intValue = 0;
        short int shortIntValue = 0;
        long int longIntValue = 0;

        double doubleValue = 0.0;

        unsigned int unsignedIntValue = 0;
        short unsigned int shortUnsignedIntValue = 0;
        long unsigned int longUnsignedIntValue = 0;

        char *stringValue = NULL;

        if (lenFormatSpec == s21_strlen(format)) {  // not found "cdfsu"
          printf("%s", "Uncorrect format\n");
          return ERROR;
        }

        if (lenFormatSpec > 0) {  // specifier have parametrs
          char formatSpec[20];

          s21_writeNchar(formatSpec, format, lenFormatSpec);
          s21_writeParameters(&parametrs, formatSpec);

          format += lenFormatSpec;
        }

        switch (*format) {
          // char type
          case 'c':
            if (parametrs.length == '\0') {
              charValue = (char)va_arg(arg, int);
              s21_ctoa(charValue, buffer);
            }
            if (parametrs.length == 'l') {
              /// надо сделать!
            }
            break;
          // int type
          case 'd':
            if (parametrs.length == '\0') {
              intValue = va_arg(arg, int);
              s21_itoa(parametrs, buffer, intValue);
            }
            if (parametrs.length == 'h') {
              shortIntValue = va_arg(arg, int);
              s21_itoa(parametrs, buffer, shortIntValue);
            }
            if (parametrs.length == 'l') {
              longIntValue = va_arg(arg, long int);
              s21_itoa(parametrs, buffer, longIntValue);
            }
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
            if (parametrs.length == '\0') {
              unsignedIntValue = va_arg(arg, int);
              s21_utoa(parametrs, buffer, unsignedIntValue);
            }
            if (parametrs.length == 'h') {
              shortUnsignedIntValue = va_arg(arg, int);
              s21_utoa(parametrs, buffer, shortUnsignedIntValue);
            }
            if (parametrs.length == 'l') {
              longUnsignedIntValue = va_arg(arg, long int);
              s21_utoa(parametrs, buffer, longUnsignedIntValue);
            }
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
