#include <math.h>

#include "s21_string.h"

int s21_isdigit(int c) { return (c >= '0' && c <= '9'); }

int s21_isflag(int c) { return (c == '-' || c == '+' || c == ' '); }

int s21_writeParameters(parserParameters *parametrs, const char *format,
                        s21_size_t len_spec) {
  if (s21_isflag(*format)) {
    parametrs->flag = *format;
    format++;
    len_spec--;
  }

  if (!s21_writeWidth(parametrs, format, len_spec)) {
    return ERROR;
  }

  return SUCCESS;
}

int s21_writeWidth(parserParameters *parametrs, const char *format,
                   s21_size_t len_spec) {
  char charWidth[20];
  s21_size_t i;

  if (len_spec > 0) {
    for (i = 0; i < len_spec; i++, format++) {
      if (s21_isdigit(*format)) {
        charWidth[i] = *format;
      } else {
        return ERROR;
      }
    }
    charWidth[i] = '\0';
    parametrs->width = s21_stoi(charWidth);
  }

  return SUCCESS;
}

int s21_stoi(const char *str) {
  int result = 0;
  // Convert a string to a number between 0 and 9
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str++ - '0');
  }

  return result;
}

void s21_writeString(char *str, char *buffer) {
  // copy the string from buffer to the str
  for (s21_size_t i = 0; i <= s21_strlen(buffer); i++) {
    str[i] = buffer[i];
  }
}

void s21_ctoa(char value, char *buffer) {
  buffer[0] = value;
  buffer[1] = '\0';
}

void s21_utoa(unsigned int value, char *buffer) {
  s21_size_t i = 0;

  while (value > 0) {
    buffer[i++] = '0' + value % 10;
    value /= 10;
  }
  buffer[i] = '\0';

  s21_strrev(buffer);
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
  int fractionalPart = fabs(round((value - intPart) * pow(10, 6)));

  s21_itoa(intPart, buffer);
  s21_itoa(fractionalPart, doubleBuffer);

  s21_strncat(buffer, ".", 1);
  s21_strncat(buffer, doubleBuffer, s21_strlen(doubleBuffer));
}
