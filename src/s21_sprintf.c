#include <stdarg.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg;
  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        // int type
        case 'd':
          int intValue = va_arg(arg, int);
          char *buffer = s21_itoa(intValue);
          s21_strncat(str, buffer, s21_strlen(buffer)); 
          str += s21_strlen(buffer);
          break;
        // string type
        case 's':
          char *charValue = va_arg(arg, char *);
          s21_strncat(str, charValue, s21_strlen(charValue));
          str += s21_strlen(charValue);
        // unknown type
        default:
          break;
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

char *s21_itoa(int value) {
  static char buffer[20];  // max length long int + знак + завершающий символ
  int isNegative = 0;
  s21_size_t i = 0;

  if (value < 0) {
    isNegative = 1;
    value = -value;
  }

  while (value > 0) {
    buffer[i++] = '0' + value % 10;
    value /= 10;
  }

  if (isNegative) {
    buffer[i++] = '-';
  }

  buffer[i] = '\0';

  // Переворачиваем строку, так как мы записывали цифры в обратном порядке
  s21_strrev(buffer);

  return buffer;
}

void s21_strrev(char *str) {
  int length = s21_strlen(str);
  int start = 0;
  int end = length - 1;

  while (start < end) {
    // Обмениваем символы на концах строки
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Переходим к следующей паре символов
    start++;
    end--;
  }
}