#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include "s21_string.h"

int s21_isdigit(int c) { return (c >= '0' && c <= '9'); }

void s21_writeParameters(parserParameters *parametrs, char *formatSpec) {
  formatSpec += s21_writeFlags(parametrs, formatSpec);

  formatSpec += s21_writeWidth(parametrs, formatSpec);

  formatSpec += s21_writePrecision(parametrs, formatSpec);

  s21_writeLength(parametrs, formatSpec);
}

s21_size_t s21_writeFlags(parserParameters *parametrs, char *formatSpec) {
  s21_size_t lenFlags = s21_strcspn(formatSpec, "1234567890.lh");

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
    }
  }

  return lenFlags;
}

s21_size_t s21_writeWidth(parserParameters *parametrs, char *formatSpec) {
  char strWidth[20];
  s21_size_t lenWidth = s21_strcspn(formatSpec, ".lh");

  if (lenWidth > 0) {
    for (s21_size_t i = 0; i < lenWidth; i++, formatSpec++) {
      strWidth[i] = *formatSpec;
    }
    strWidth[lenWidth] = '\0';
    parametrs->width = s21_stoi(strWidth);
  }

  return lenWidth;
}

s21_size_t s21_writePrecision(parserParameters *parametrs, char *formatSpec) {
  s21_size_t lenPrecision = 0;
  char strPrecision[20];

  if (*formatSpec == '.') {
    formatSpec++;
    lenPrecision = s21_strcspn(formatSpec, "lh");

    if (lenPrecision == 0) {  // no_explicit_meaning
      parametrs->precision = 0;
    }

    if (lenPrecision > 0) {
      for (s21_size_t i = 0; i < lenPrecision; i++, formatSpec++) {
        strPrecision[i] = *formatSpec;
      }
      strPrecision[lenPrecision] = '\0';

      parametrs->precision = s21_stoi(strPrecision);
    }

    lenPrecision++;  // + '.'
  }

  return lenPrecision;
}

void s21_writeLength(parserParameters *parametrs, char *formatSpec) {
  parametrs->length = *formatSpec;
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

void s21_ctoa(wchar_t value, char *buffer) {
  buffer[0] = value;
  buffer[1] = '\0';
}

void s21_itoa(parserParameters parametrs, char *buffer, long int value) {
  int isNegative = 0;
  int i = 0;

  if (parametrs.precision == -1) {
    parametrs.precision = 1;
  }

  if (value == 0 && parametrs.precision != 0) {
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

  if (parametrs.precision > i) {
    int numberNulls = parametrs.precision - i;
    while (numberNulls > 0) {
      buffer[i++] = '0';
      numberNulls--;
    }
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

void s21_utoa(parserParameters parametrs, char *buffer,
              long unsigned int value) {
  int i = 0;

  if (parametrs.precision == -1) {
    parametrs.precision = 1;
  }

  if (value == 0 && parametrs.precision != 0) {
    buffer[i++] = '0';
  }

  while (value > 0) {
    buffer[i++] = '0' + value % 10;
    value /= 10;
  }

  if (parametrs.precision > i) {
    int numberNulls = parametrs.precision - i;
    while (numberNulls > 0) {
      buffer[i++] = '0';
      numberNulls--;
    }
  }

  buffer[i] = '\0';

  s21_strrev(buffer);
}

void s21_ftoa(parserParameters parametrs, char *buffer, double value) {
  int intPart;
  char fracBuffer[41];

  if (parametrs.precision == -1) {  // not specified
    parametrs.precision = 6;
  }

  if (parametrs.precision == 0) {
    intPart = round(value);
    s21_intPartToa(parametrs, buffer, intPart);
  }

  if (parametrs.precision > 0) {
    intPart = (int)value;

    s21_size_t fractionalPart =
        round((fabs(value - intPart) + 1) * pow(10, parametrs.precision));
    // +1 for save nulls in frac.part

    s21_intPartToa(parametrs, buffer, intPart);
    s21_utoa(parametrs, fracBuffer, fractionalPart);

    fracBuffer[0] = '.';  //  1 -> '.'
    s21_strncat(buffer, fracBuffer, s21_strlen(fracBuffer));
  }
}

void s21_intPartToa(parserParameters parametrs, char *buffer, int intPart) {
  parametrs.precision = 1;
  s21_itoa(parametrs, buffer, intPart);
}

void s21_stoa(parserParameters parametrs, char *buffer, char *charPtrValue) {
  if (parametrs.precision == -1) {
    s21_writeString(buffer, charPtrValue);
  } else {
    s21_writeNchar(buffer, charPtrValue, parametrs.precision);
  }
}