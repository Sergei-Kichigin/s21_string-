#include <stddef.h>

#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t length = 0;
  while (str[length] != '\0') {
    length += 1;
  }
  return length;
}