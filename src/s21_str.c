#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n){
  char *p = dest + s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++){
    p[i] = src[i];
    if (src[i] == '\0') break;
  }
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str[length] != '\0') {
    length += 1;
  }
  return length;
}