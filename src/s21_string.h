#ifndef S21_STRING_H
#define S21_STRING_H

#define SUCCESS 0
#define ERROR 1

#define NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strlen(const char *str);

#endif