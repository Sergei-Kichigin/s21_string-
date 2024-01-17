#include <math.h>
#include <stdarg.h>
#include <stdio.h>

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
          char buffer[20];
          s21_itoa(intValue, buffer);
          s21_strncat(str, buffer, s21_strlen(buffer));
          str += s21_strlen(buffer);
          break;
        // float type
        case 'f':
          double floatValue = va_arg(arg, double);
          char floatBuffer[20];
          s21_ftoa(floatValue, floatBuffer);
          s21_strncat(str, floatBuffer, s21_strlen(floatBuffer));
          str += s21_strlen(floatBuffer);
          break;
        // string type
        case 's':
          char *charPtrValue = va_arg(arg, char *);
          s21_strncat(str, charPtrValue, s21_strlen(charPtrValue));
          str += s21_strlen(charPtrValue);
          break;
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

void s21_itoa(int value, char *buffer) {
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

void s21_ftoa(double value, char *buffer) {
  char doubleBuffer[20];

  int intPart = (int)value;
  int fractionalPart = round((value - intPart) * pow(10, 6));

  s21_itoa(intPart, buffer);
  s21_itoa(fractionalPart, doubleBuffer);

  s21_strncat(buffer, ".", 1);
  s21_strncat(buffer, doubleBuffer, s21_strlen(doubleBuffer));
}