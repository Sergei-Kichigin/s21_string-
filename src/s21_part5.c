#include <stdio.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  void *result = S21_NULL;
  char *upStr = (char *)str;

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      upStr[i] = str[i] - 32; // a -> A
    }
  }

  result = (void *)upStr;

  return result;
}

void *s21_to_lower(const char *str){
  void *result = S21_NULL;
  char *lwStr = (char *)str;

  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      lwStr[i] = str[i] + 32; // // A -> a
    }
  }

  result = (void *)lwStr;

  return result;

}