#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest + s21_strlen(dest);

  for (s21_size_t i = 0; i < n; i++) {
    p[i] = src[i];
    if (src[i] == '\0') break;
    if (i == n - 1) p[n] = '\0';
  }

  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  char value = (char)c;

  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {  // with '\0'
    if (str[i] == value) {
      result = (char *)(str + i);
      break;
    }
  }

  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;

  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, (int)str1[i]) != S21_NULL) {
      break;
    }
    length++;
  }

  return length;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;

  while (str[length] != '\0') {
    length += 1;
  }

  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;

  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    if (s21_strchr(str2, (int)str1[i]) != S21_NULL) {
      result = (char *)(str1 + i);
      break;
    }
  }

  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  char value = (char)c;

  for (int i = s21_strlen(str); i >= 0; i--) {  // with '\0'
    if (str[i] == value) {
      result = (char *)(str + i);
      break;
    }
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *result = S21_NULL;

  if (*needle == '\0') {
    result = haystack;  // Пустая строка всегда найдена в любой строке
  } else {
    while (*haystack != '\0') {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        ++h;
        ++n;
      }

      if (*n == '\0') {
        result = haystack;  // Найдено вхождение
        break;
      }

      ++haystack;
    }
  }

  return (char *)result;
}