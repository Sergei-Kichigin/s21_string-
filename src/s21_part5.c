#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  
  s21_size_t str_len = s21_strlen(str);
  char *result = (char *)malloc((str_len + 1) * sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < str_len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;  // a -> A
    } else {
      result[i] = str[i];
    }
  }

  return (void *)result;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  
  s21_size_t str_len = s21_strlen(str);
  char *result = (char *)malloc((str_len + 1) * sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < str_len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + 32;  // A -> a
    } else {
      result[i] = str[i];
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

  if (start_index > src_len) {  // Исправлено с >= на >
    return S21_NULL;
  }

  char *result = (char *)malloc((src_len + str_len + 1) *
                                sizeof(char));  // Учтен символ '\0'
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_strncpy(result, src, start_index);
  result[start_index] = '\0';
  s21_strncat(result, str, str_len);
  s21_strncat(result, src + start_index, src_len - start_index);

  return (void *)result;
}

int is_space(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }

int is_empty_trim_chars(const char *trim_chars) {
  if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
    return ERROR;
  }
  return SUCCESS;
}

int check_trim_chars(char c, bool isEmptyTrimChars, const char *trim_chars) {
  int result = 0;

  if (isEmptyTrimChars) {
    result = is_space(c);
  } else {
    result = (s21_strchr(trim_chars, c) != S21_NULL ? ERROR : SUCCESS);
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) {
    return S21_NULL;
  }

  bool isEmptyTrimChars = is_empty_trim_chars(trim_chars);
  s21_size_t src_len = s21_strlen(src);

  s21_size_t start_idx = 0;
  while (start_idx < src_len &&
         check_trim_chars(src[start_idx], isEmptyTrimChars, trim_chars)) {
    start_idx++;
  }

  s21_size_t end_idx = src_len - 1;
  while (end_idx > start_idx &&
         check_trim_chars(src[end_idx], isEmptyTrimChars, trim_chars)) {
    end_idx--;
  }

  // Вычисляем новую длину строки
  s21_size_t result_len =
      (end_idx >= start_idx) ? (end_idx - start_idx + 1) : 0;

  char *result = (char *)malloc((result_len + 1) * sizeof(char));
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_strncpy(result, src + start_idx, result_len);
  result[result_len] = '\0';

  return (void *)result;
}