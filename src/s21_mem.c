#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  unsigned char value = (unsigned char)c;
  void *result = S21_NULL;

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

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = str1;
  const unsigned char *p2 = str2;
  int result = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (p1[i] != p2[i]) {
      result = (int)(p1[i] - p2[i]);
      break;
    }
  }

  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *p1 = dest;
  const unsigned char *p2 = src;

  for (s21_size_t i = 0; i < n; i++) {
    p1[i] = p2[i];
  }
  return dest;
}
