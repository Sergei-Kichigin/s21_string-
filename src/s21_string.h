#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdbool.h>
#include <stddef.h>

#define SUCCESS 0
#define ERROR 1
#define S21_NULL (void *)0

typedef long unsigned s21_size_t;

typedef struct {
  bool forcedSignOutput;  // Принудительный вывод знака
  bool leftOrientation;
  bool signPlace;
  s21_size_t width;
  int precision;
  char length;
} parserParameters;

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_sprintf(char *str, const char *format, ...);

s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);

// Special string processing functions (from the String class in C#)
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

// additional functions for sprintf

// for str
void s21_writeString(char *str, char *buffer);
void s21_writeNchar(char *str, const char *buffer, s21_size_t n);
void s21_addFormat(parserParameters parametrs, char *buffer);

// transform type
void s21_ctoa(wchar_t value, char *buffer);
void s21_itoa(parserParameters parametrs, char *buffer, long int value);
void s21_ftoa(parserParameters parametrs, char *buffer, double value);
void s21_utoa(parserParameters parametrs, char *buffer,
              long unsigned int value);
void s21_stoa(parserParameters parametrs, char *buffer, char *charPtrValue);

void s21_intPartToa(parserParameters parametrs, char *buffer, int intPart);
void s21_strrev(char *str);

int s21_isdigit(int c);

s21_size_t s21_stoi(const char *str);

// specifier parametrs
void s21_writeParameters(parserParameters *parametrs, char *format);
void s21_writeLength(parserParameters *parametrs, char *formatSpec);

s21_size_t s21_writeFlags(parserParameters *parametrs, char *formatSpec);
s21_size_t s21_writeWidth(parserParameters *parametrs, char *formatSpec);
s21_size_t s21_writePrecision(parserParameters *parametrs, char *formatSpec);

#endif
