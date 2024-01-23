#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdbool.h>

#define SUCCESS 0
#define ERROR 1
#define S21_NULL (void *)0
#define MAXLENGHTSTRFLAGS

typedef long unsigned s21_size_t;

typedef struct {
  bool forcedSignOutput;  // Принудительный вывод знака
  bool leftOrientation;
  bool signPlace;
  s21_size_t width;
  s21_size_t precision;
  char length;
} parserParameters;

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

// additional functions

// for str
void s21_writeString(char *str, char *buffer);
void s21_writeNchar(char *str, const char *buffer, s21_size_t n);
void s21_addFormat(char *buffer, parserParameters parametrs);
int s21_writeFlags(parserParameters *parametrs, char *formatSpec);

// transform type
void s21_ctoa(char value, char *buffer);
void s21_itoa(int value, char *buffer, parserParameters parametrs);
void s21_strrev(char *str);
void s21_ftoa(double value, char *buffer, parserParameters parametrs);
void s21_utoa(unsigned int value, char *buffer);

int s21_isdigit(int c);
int s21_isflag(int c);

s21_size_t s21_stoi(const char *str);

// specifier parametrs
int s21_writeParameters(parserParameters *parametrs, char *format);
int s21_writeWidth(parserParameters *parametrs, char *format);

#endif