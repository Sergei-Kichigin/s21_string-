#ifndef S21_STRING_H
#define S21_STRING_H

#define SUCCESS 0
#define ERROR 1

typedef unsigned long s21_size_t;

s21_size_t s21_strlen(const char *str);
void *s21_memset(void *str, int c, s21_size_t n);

#endif