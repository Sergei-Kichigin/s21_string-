#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  void *result = NULL;
  unsigned char value = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == value) {
      result = (void *)(p + i);
      break;
    }
  }
  return result;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p = str;
  unsigned char value = (unsigned char)c;

  for (s21_size_t i = 0; i < n; ++i) {
    p[i] = value;
  }

  return str;
}
