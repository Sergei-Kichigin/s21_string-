#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR 1
#define s21_NULL (void *)0
#define BUFFER_SIZE 1024

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
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// additional functions for sprintf

// for str
void s21_writeString(char *str, char *buffer);
void s21_writeNchar(char *str, const char *buffer, s21_size_t n);
s21_size_t s21_addFormat(parserParameters parameters, char *buffer, char *str);

// transform type
void s21_ctoa(char value, char *buffer);
void s21_itoa(parserParameters parameters, char *buffer, long int value);
void s21_ftoa(parserParameters parameters, char *buffer, double value);
void s21_utoa(parserParameters parameters, char *buffer,
              long unsigned int value);
void s21_stoa(parserParameters parameters, char *buffer, char *charPtrValue);

void s21_intPartToa(parserParameters parameters, char *buffer, int intPart);
void s21_strrev(char *str);

void s21_processChar(char *buffer, va_list arg);
void s21_processInteger(char *buffer, va_list arg, parserParameters parameters);
void s21_processFloat(char *buffer, va_list arg, parserParameters parameters);
void s21_processString(char *buffer, va_list arg, parserParameters parameters);
void s21_processUnsignedInteger(char *buffer, va_list arg,
                                parserParameters parameters);

int s21_isdigit(int c);
int s21_sign(double x);

s21_size_t s21_stoi(const char *str);

// specifier parameters
void s21_getLenFormatSpec(const char *format, s21_size_t *lenFormatSpec);
void s21_specifierParametersParsing(const char *format,
                                    s21_size_t lenFormatSpec,
                                    parserParameters *parameters);
void s21_checkSpecifier(const char *format, char *buffer, va_list arg,
                        parserParameters parameters);
void s21_writeParameters(parserParameters *parameters, char *format);
void s21_writeLength(parserParameters *parameters, char *formatSpec);

s21_size_t s21_writeFlags(parserParameters *parameters, char *formatSpec);
s21_size_t s21_writeWidth(parserParameters *parameters, char *formatSpec);
s21_size_t s21_writePrecision(parserParameters *parameters, char *formatSpec);

int is_space(char c);
int is_empty_trim_chars(const char *trim_chars);
int check_trim_chars(char c, bool isEmptyTrimChars, const char *trim_chars);

#endif
