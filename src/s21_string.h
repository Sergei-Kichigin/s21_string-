#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>

#define SUCCESS 0
#define ERROR 1

size_t s21_strlen(const char *str);
void *s21_memset(void *str, int c, size_t n);

#endif