#include <math.h>

#include "s21_string.h"

int s21_isdigit(int c) { return (c >= '0' && c <= '9'); }

int s21_isflag(int c) { return (c == '-' || c == '+' || c == ' '); }

int s21_writeParameters(parserParameters *parametrs, char *formatSpec) {
  s21_size_t lenFormatSpec = s21_strlen(formatSpec);

  if (s21_isflag(*formatSpec)) {
    parametrs->flag = *formatSpec;
    formatSpec++;
    lenFormatSpec--;
  }

  if (!s21_writeWidth(parametrs, formatSpec)) {
    return ERROR;
  }

  return SUCCESS;
}

int s21_writeWidth(parserParameters *parametrs, char *formatSpec) {
  char charWidth[20];
  s21_size_t i;

  s21_size_t lenFormatSpec = s21_strlen(formatSpec);

  if (lenFormatSpec > 0) {
    for (i = 0; i < lenFormatSpec; i++, formatSpec++) {
      if (s21_isdigit(*formatSpec)) {
        charWidth[i] = *formatSpec;
      } else {
        return ERROR;
      }
    }
    charWidth[i] = '\0';

    parametrs->width = s21_stoi(charWidth);
  }

  return SUCCESS;
}

void s21_addFormat(char *buffer, parserParameters parametrs) {
  if (parametrs.width > s21_strlen(buffer)) {
    s21_size_t addWidth = parametrs.width - s21_strlen(buffer);
    char bufferWidth[addWidth];
    s21_memset(bufferWidth, ' ', addWidth);

    if (parametrs.flag == '-') {  // left orientation
      s21_strncat(buffer, bufferWidth, addWidth);
    } else {  // right orientation
      s21_strncat(bufferWidth, buffer, s21_strlen(buffer));
      s21_writeString(buffer, bufferWidth);
    }
  }
}

s21_size_t s21_stoi(const char *str) {
  s21_size_t result = 0;
  // Convert a string to a number between 0 and 9
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + (*str - '0');
    str++;
  }
  return result;
}

void s21_writeString(char *str, char *buffer) {
  // copy the string from buffer to the str
  for (s21_size_t i = 0; i <= s21_strlen(buffer); i++) {
    str[i] = buffer[i];
  }
}

void s21_writeNchar(char *str, const char *buffer, s21_size_t n) {
  // copy n char from buffer to the str
  for (s21_size_t i = 0; i < n; i++) {
    str[i] = buffer[i];
  }
  str[n] = '\0';
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
