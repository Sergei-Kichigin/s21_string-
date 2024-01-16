#ifndef S21_STRING_H
#define S21_STRING_H

#define SUCCESS 0
#define ERROR 1
#define S21_NULL (void *)0

typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_sprintf(char *str, const char *format, ...);

s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// additional functions
void s21_strrev(char *str);

char *s21_itoa(int value);

#endif
