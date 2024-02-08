#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = (char *)str;

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;  // a -> A
    }
  }

  return (void *)result;
}

void *s21_to_lower(const char *str) {
  char *result = (char *)str;

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + 32;  // // A -> a
    }
  }

  return (void *)result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index >= src_len) {
    return S21_NULL;
  }

  char *result = (char *)malloc((src_len + str_len) * sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  char *endSrc = (char *)(src + start_index);

  s21_strncpy(result, src, start_index);
  result[start_index] = '\0';
  s21_strncat(result, str, str_len);
  s21_strncat(result, endSrc, src_len - start_index);

  return (void *)result;
}
