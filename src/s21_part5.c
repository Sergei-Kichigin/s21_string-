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

void *s21_trim(const char *src, const char *trim_chars) {
  if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
    char *trim_chars = (char *)malloc(3 * sizeof(char));
    s21_strncpy(trim_chars, " \n\t", 3);
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t trim_len = s21_strlen(trim_chars);

  char *result = (char *)malloc(src_len * sizeof(char));

  s21_size_t result_len = 0;
  s21_size_t j = 0;

  // delete initial trim_chars
  for (s21_size_t i = 0; i < src_len; i++) {
    for (j = 0; j < trim_len; j++) {
      if (src[i] == trim_chars[j]) {
        break;
      }
    }

    if (j == trim_len) {  // src[i] not equal trim_chars
      result_len = s21_strlen(src + i);
      s21_strncpy(result, src + i, result_len);
      result[result_len] = '\0';
      break;
    }
  }

  // delete end trim_chars
  for (int k = result_len - 1; k >= 0; k--) {
    for (j = 0; j < trim_len; j++) {
      if (result[k] == trim_chars[j]) {
        result[k] = '\0';
        break;
      }
    }

    if (j == trim_len) {  // result[k] not equal trim_chars
      break;
    }
  }

  return (void *)result;
}
