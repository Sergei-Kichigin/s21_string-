#include <math.h>
#include <stdio.h>

#include "s21_string.h"

int s21_isdigit(int c) { return (c >= '0' && c <= '9'); }

int s21_writeParameters(parserParameters *parametrs, char *formatSpec) {
  s21_size_t lenParam = 0;

  if (s21_writeFlags(parametrs, formatSpec, &lenParam)) {
    return ERROR;
  }

  formatSpec += lenParam;

  if (s21_writeWidth(parametrs, formatSpec, &lenParam)) {
    return ERROR;
  }

  formatSpec += lenParam;

  if (s21_writePrecision(parametrs, formatSpec, &lenParam)) {
    return ERROR;
  }

  formatSpec += lenParam;

  return SUCCESS;
}

int s21_writeFlags(parserParameters *parametrs, char *formatSpec,
                   s21_size_t *lenParam) {
  s21_size_t lenFlags = s21_strcspn(formatSpec, "1234567890.lh");
  *lenParam = lenFlags;

  if (lenFlags > 2 || (lenFlags == 2 && (formatSpec[0] == formatSpec[1]))) {
    return ERROR;
  }

  if (lenFlags == 1 || lenFlags == 2) {
    for (s21_size_t i = 0; i < lenFlags; i++) {
      switch (formatSpec[i]) {
        case '-':
          parametrs->leftOrientation = true;
          break;
        case '+':
          parametrs->forcedSignOutput = true;
          break;
        case ' ':
          parametrs->signPlace = true;
          break;
        default:
          return ERROR;
          break;
      }
    }
  }

  if (parametrs->forcedSignOutput && parametrs->signPlace) {
    return ERROR;
  }

  return SUCCESS;
}

int s21_writeWidth(parserParameters *parametrs, char *formatSpec,
                   s21_size_t *lenParam) {
  char strWidth[20];

  s21_size_t lenWidth = s21_strcspn(formatSpec, ".lh");
  *lenParam = lenWidth;

  if (lenWidth > 0) {
    for (s21_size_t i = 0; i < lenWidth; i++, formatSpec++) {
      if (s21_isdigit(*formatSpec)) {
        strWidth[i] = *formatSpec;
      } else {
        return ERROR;
      }
    }
    strWidth[lenWidth] = '\0';

    parametrs->width = s21_stoi(strWidth);
  }

  return SUCCESS;
}

int s21_writePrecision(parserParameters *parametrs, char *formatSpec,
                       s21_size_t *lenParam) {
  char strPrecision[20];

  if (*formatSpec == '.') {
    formatSpec++;

    s21_size_t lenPrecision = s21_strcspn(formatSpec, "lh");
    *lenParam = lenPrecision + 1;  // + '.'

    if (lenPrecision > 0) {
      for (s21_size_t i = 0; i < lenPrecision; i++, formatSpec++) {
        if (s21_isdigit(*formatSpec)) {
          strPrecision[i] = *formatSpec;
        } else {
          return ERROR;
        }
      }
      strPrecision[lenPrecision] = '\0';

      parametrs->precision = s21_stoi(strPrecision);
    }
  }

  return SUCCESS;
}

void s21_addFormat(parserParameters parametrs, char *buffer) {
  if (parametrs.width > s21_strlen(buffer)) {
    s21_size_t addWidth = parametrs.width - s21_strlen(buffer);

    char bufferWidth[parametrs.width];
    s21_memset(bufferWidth, ' ', addWidth);
    bufferWidth[addWidth] = '\0';

    if (parametrs.leftOrientation) {  // left orientation
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
  while (s21_isdigit(*str)) {
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

void s21_itoa(int value, char *buffer, parserParameters parametrs) {
  int isNegative = 0;
  s21_size_t i = 0;

  if (value == 0) {
    buffer[i++] = '0';
  }

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
  } else {
    if (parametrs.forcedSignOutput) buffer[i++] = '+';
    if (parametrs.signPlace) buffer[i++] = ' ';
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

void s21_ftoa(double value, char *buffer, parserParameters parametrs) {
  char fracBuffer[20];

  int intPart = (int)value;
  s21_size_t fractionalPart =
      round((fabs(value - intPart) + 1) *
            pow(10, 6));  // +1 for save nulls in frac.part

  s21_itoa(intPart, buffer, parametrs);
  s21_utoa(fractionalPart, fracBuffer);

  fracBuffer[0] = '.';  //  1 -> '.'
  s21_strncat(buffer, fracBuffer, s21_strlen(fracBuffer));
}
