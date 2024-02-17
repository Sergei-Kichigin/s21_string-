#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// MEMCHR
START_TEST(memchr_1) {
  s21_size_t length = 10;
  char input[20] = "This is Test1";
  void *result;
  void *expected;

  result = s21_memchr(input, 's', length);
  expected = memchr(input, 's', length);

  ck_assert_mem_eq(result, expected, sizeof(*expected));
}
END_TEST

START_TEST(memchr_2) {
  s21_size_t length = 10;
  char input[20] = "This is Test2";
  void *result;
  void *expected;

  result = s21_memchr(input, 'A', length);
  expected = memchr(input, 'A', length);

  ck_assert_ptr_null(result);    // 'A' is not in input
  ck_assert_ptr_null(expected);  // return NULL
}
END_TEST

// MEMSET
START_TEST(memset_1) {
  s21_size_t length = 5;
  char result[10] = {0};
  char expected[10] = {0};

  s21_memset(result, 'A', length);
  memset(expected, 'A', length);

  ck_assert_mem_eq(result, expected, length);
}
END_TEST

START_TEST(memset_2) {
  s21_size_t length = 7;
  char result[10] = {0};
  char expected[10] = {0};

  s21_memset(result, 'B', length);
  memset(expected, 'B', length);

  ck_assert_mem_eq(result, expected, length);
}
END_TEST

// MEMCMP
START_TEST(memcmp_1) {
  s21_size_t length = 13;
  char input1[20] = "This is Test1";
  char input2[20] = "This is Test1";
  int result;
  int expected;

  result = s21_memcmp(input1, input2, length);
  expected = memcmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_2) {
  s21_size_t length = 13;
  char input1[20] = "This is Test2";
  char input2[20] = "This is Test3";
  int result;
  int expected;

  result = s21_memcmp(input1, input2, length);
  expected = memcmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_3) {
  s21_size_t length = 5;
  char input1[10] = "hello";
  char input2[10] = "world";
  int result;
  int expected;

  result = s21_memcmp(input1, input2, length);
  expected = memcmp(input1, input2, length);

  ck_assert_int_eq(result, expected);  // 'h' < 'w'
}
END_TEST

START_TEST(memcmp_4) {
  s21_size_t length = 7;
  char input1[10] = "foobar";
  char input2[10] = "foobaz";
  int result;
  int expected;

  result = s21_memcmp(input1, input2, length);
  expected = memcmp(input1, input2, length);

  ck_assert_int_eq(result, expected);  // 'r' > 'z'
}
END_TEST

// MEMCPY
START_TEST(memcpy_1) {
  s21_size_t length = 5;

  char src[20] = "Thiss is Test";
  char buffer[20] = "Text to copy";
  char expected_buffer[20] = "Text to copy";
  void *result;
  void *expected;

  result = s21_memcpy(buffer, src, length);
  expected = memcpy(expected_buffer, src, length);
  // printf("\n%ld, %ld, %ld\n", sizeof(expected), sizeof(*expected),
  // strlen(expected)*sizeof(*expected));
  ck_assert_mem_eq(result, expected, strlen(expected) * sizeof(*expected));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t length = 5;

  char src[20] = "This";
  char buffer[20] = "Text to copy";
  char expected_buffer[20] = "Text to copy";
  void *result;
  void *expected;

  result = s21_memcpy(buffer, src, length);
  expected = memcpy(expected_buffer, src, length);
  ck_assert_mem_eq(result, expected, strlen(expected) * sizeof(*expected));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t length = 5;

  char src[20] = "Thiss is Test";
  char buffer[20] = "Text";
  char expected_buffer[20] = "Text";
  void *result;
  void *expected;

  result = s21_memcpy(buffer, src, length);
  expected = memcpy(expected_buffer, src, length);
  ck_assert_mem_eq(result, expected, strlen(expected) * sizeof(*expected));
}
END_TEST

// STRNCAT
START_TEST(strncat_1) {
  s21_size_t length = 7;

  char dest1[10] = "make";  // change in strncat
  const char src1[10] = "Test1";

  char dest2[10] = "make";
  const char src2[10] = "Test1";

  char *result;
  char *expected;

  result = s21_strncat(dest1, src1, length);
  expected = strncat(dest2, src2, length);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t length = 2;

  char dest1[10] = "make";  // change in strncat
  const char src1[10] = "Test2";

  char dest2[10] = "make";
  const char src2[10] = "Test2";

  char *result;
  char *expected;

  result = s21_strncat(dest1, src1, length);
  expected = strncat(dest2, src2, length);

  ck_assert_str_eq(result, expected);
}
END_TEST

// STRCHR
START_TEST(strchr_1) {
  char input[20] = "This is Test1";
  char *result;
  char *expected;

  result = s21_strchr(input, 's');
  expected = strchr(input, 's');

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strchr_2) {
  char input[20] = "This is Test2";
  char *result;
  char *expected;

  result = s21_strchr(input, '\0');  // terminating null
  expected = strchr(input, '\0');

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strchr_3) {
  char input[20] = "This is Test3";
  char *result;
  char *expected;

  result = s21_strchr(input, 'A');
  expected = strchr(input, 'A');

  ck_assert_ptr_null(result);    // 'A' is not in input
  ck_assert_ptr_null(expected);  // return NULL
}
END_TEST

// STRCSPN
START_TEST(strcspn_1) {
  char input1[10] = "make";
  char input2[10] = "Tst1";
  s21_size_t result;
  s21_size_t expected;

  result = s21_strcspn(input1, input2);
  expected = strcspn(input1, input2);

  ck_assert_uint_eq(result, expected);
}
END_TEST

START_TEST(strcspn_2) {
  char input1[10] = "make";
  char input2[10] = "Testm";
  s21_size_t result;
  s21_size_t expected;

  result = s21_strcspn(input1, input2);
  expected = strcspn(input1, input2);

  ck_assert_uint_eq(result, expected);
}
END_TEST

// STRLEN
START_TEST(strlen_1) {
  char *input = "make";
  s21_size_t result;
  s21_size_t expected;

  result = s21_strlen(input);
  expected = strlen(input);

  ck_assert_uint_eq(
      result, expected);  // compare unsigned int with size_t - unsigned long
}
END_TEST

START_TEST(strlen_2) {
  char *input = "";  // empty line
  s21_size_t result;
  s21_size_t expected;

  result = s21_strlen(input);
  expected = strlen(input);

  ck_assert_uint_eq(result, expected);
}
END_TEST

// STRPBRK
START_TEST(strpbrk_1) {
  char input1[10] = "make";
  char input2[10] = "Test1";
  char *result;
  char *expected;

  result = s21_strpbrk(input1, input2);
  expected = strpbrk(input1, input2);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strpbrk_2) {
  char input1[10] = "make";
  char input2[10] = "Tst2";
  char *result;
  char *expected;

  result = s21_strpbrk(input1, input2);
  expected = strpbrk(input1, input2);

  ck_assert_ptr_null(result);    // char from input1 is not in input2
  ck_assert_ptr_null(expected);  // return NULL
}
END_TEST

// STRRCHR
START_TEST(strrchr_1) {
  char input[20] = "This is Test1";
  char *result;
  char *expected;

  result = s21_strrchr(input, 's');
  expected = strrchr(input, 's');

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strrchr_2) {
  char input[20] = "This is Test2";
  char *result;
  char *expected;

  result = s21_strrchr(input, '\0');  // terminating null
  expected = strrchr(input, '\0');

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strrchr_3) {
  char input[20] = "This is Test3";
  char *result;
  char *expected;

  result = s21_strrchr(input, 'A');
  expected = strrchr(input, 'A');

  ck_assert_ptr_null(result);    // 'A' is not in input
  ck_assert_ptr_null(expected);  // return NULL
}
END_TEST

// STRSTR
START_TEST(strstr_1) {
  const char *haystack = "This is a simple test.";
  const char *needle = "simple";
  char *result;
  char *expected;

  result = s21_strstr(haystack, needle);
  expected = strstr(haystack, needle);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strstr_2) {
  const char *haystack = "This is another test.";
  const char *needle = "missing";
  char *result;
  char *expected;

  result = s21_strstr(haystack, needle);
  expected = strstr(haystack, needle);

  ck_assert_ptr_null(result);    // 'missing' is not in haystack
  ck_assert_ptr_null(expected);  // return NULL
}
END_TEST

START_TEST(strstr_3) {
  const char *haystack = "This is a simple test.";
  const char *needle = "simple";
  char *result;
  char *expected;

  result = s21_strstr(haystack, needle);
  expected = strstr(haystack, needle);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strstr_empty_needle) {
  const char *haystack = "This is a simple test.";
  const char *needle = "";
  char *result;
  char *expected;

  result = s21_strstr(haystack, needle);
  expected = strstr(haystack, needle);

  ck_assert_str_eq(result, expected);
}
END_TEST

// STRNCMP

START_TEST(strncmp_1) {
  s21_size_t length = 10;
  char input1[20] = "This is Test4";
  char input2[20] = "This is Test4";
  int result;
  int expected;

  result = s21_strncmp(input1, input2, length);
  expected = strncmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t length = 10;
  char input1[20] = "This Test5";
  char input2[20] = "This is Test5";
  int result;
  int expected;

  result = s21_strncmp(input1, input2, length);
  expected = strncmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t length = 10;
  char input1[20] = "This is Test5";
  char input2[20] = "This Test5";
  int result;
  int expected;

  result = s21_strncmp(input1, input2, length);
  expected = strncmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_4) {
  s21_size_t length = 5;
  char input1[20] = "This is Test7";
  char input2[20] = "This is Tett7";
  int result;
  int expected;

  result = s21_strncmp(input1, input2, length);
  expected = strncmp(input1, input2, length);

  ck_assert_int_eq(result, expected);
}
END_TEST

// STRNCPY

START_TEST(strncpy_1) {
  s21_size_t length = 5;

  char input[20] = "Textt to copy";
  char src1[20] = "This is Test";
  char src2[20] = "This is Test";
  char *result;
  char *expected;

  result = s21_strncpy(src1, input, length);
  expected = strncpy(src2, input, length);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t length = 5;

  char input[20] = "Text";
  char src1[20] = "This is Test";
  char src2[20] = "This is Test";
  char *result;
  char *expected;

  result = s21_strncpy(src1, input, length);
  expected = strncpy(src2, input, length);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t length = 5;

  char input[20] = "Textt to copy";
  char src1[20] = "This";
  char src2[20] = "This";
  char *result;
  char *expected;

  result = s21_strncpy(src1, input, length);
  expected = strncpy(src2, input, length);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_4) {
  s21_size_t length = 0;
  char input[20] = "Textt to copy";
  char src1[20] = "This is Test";
  char src2[20] = "This is Test";
  char *result;
  char *expected;

  result = s21_strncpy(src1, input, length);
  expected = strncpy(src2, input, length);

  ck_assert_str_eq(result, expected);
}
END_TEST

// STRTOK

START_TEST(strtok_1) {
  char str1[] = ",,,,,,Hello, world, how are you";
  char str2[] = ",,,,,,Hello, world, how are you";

  char delim[] = ",?";

  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "Hello, world, how are you";
  char str2[] = "Hello, world, how are you";

  char delim[] = "!?";

  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str1[] = "Hello, world! how are you?";
  char str2[] = "Hello, world! how are you?";

  char delim[] = ",!?";

  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_str_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
  ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str1[] = "Hello, world! how are you?";
  char str2[] = "Hello, world! how are you?";

  char delim[] = "\0";

  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "";
  char str2[] = "";

  char delim[] = ",!?";

  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(strtok_6) {
  char str1[] = "";
  char str2[] = "";

  char delim[] = "\0";

  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  ck_assert_pstr_eq(s21_strtok(s2, s3), strtok(s1, s3));
  ck_assert_pstr_eq(s21_strtok(S21_NULL, s3), strtok(S21_NULL, s3));
  ck_assert_pstr_eq(s21_strtok(S21_NULL, s3), strtok(S21_NULL, s3));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

// STRERROR

START_TEST(strerror_1) {
  for (int i = -5; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

// SPRINTF

START_TEST(test_sprintf_int_left_orientation) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %-10d %%", 42);
  sprintf(buffer2, "Test: %-10d %%", 42);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_right_orientation) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %10d", 42);
  sprintf(buffer2, "Test: %10d", 42);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_negative) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %d", -142);
  sprintf(buffer2, "Test: %d", -142);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_float) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Float: %f", 3.14159);
  sprintf(buffer2, "Float: %f", 3.14159);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_float_negative) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Float: %f", -3.14159);
  sprintf(buffer2, "Float: %f", -3.14159);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_string) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "String: %s", "Hello, World!");
  sprintf(buffer2, "String: %s", "Hello, World!");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_char) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Char: %c", 'A');
  sprintf(buffer2, "Char: %c", 'A');

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Unsigned: %u", 12345);
  sprintf(buffer2, "Unsigned: %u", 12345);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// PRECISION

START_TEST(test_sprintf_int_precision_positive) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.4d", 42);
  sprintf(buffer2, "Test: %.4d", 42);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_precision_null) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.0d", 0);
  sprintf(buffer2, "Test: %.0d", 0);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_precision_no_explicit_meaning) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.d", 0);  // precision = 0
  sprintf(buffer2, "Test: %.d", 0);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_precision_positive) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.4u", 65);
  sprintf(buffer2, "Test: %.4u", 65);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_precision_null) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.0u", 0);
  sprintf(buffer2, "Test: %.0u", 0);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_precision_no_explicit_meaning) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.u", 0);  // precision = 0
  sprintf(buffer2, "Test: %.u", 0);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_double_precision_positive) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.4f", 12.456789);
  sprintf(buffer2, "Test: %.4f", 12.456789);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_double_precision_null) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.0f", -134.784);
  sprintf(buffer2, "Test: %.0f", -134.784);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_double_precision_no_explicit_meaning) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.f", 0.6);  // precision = 0
  sprintf(buffer2, "Test: %.f", 0.6);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_string_precision_positive) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.4s", "SUCCESS");
  sprintf(buffer2, "Test: %.4s", "SUCCESS");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_string_precision_null) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.0s", "SUCCESS");
  sprintf(buffer2, "Test: %.0s", "SUCCESS");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_string_precision_no_explicit_meaning) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %.s", "SUCCESS");  // precision = 0
  sprintf(buffer2, "Test: %.s", "SUCCESS");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_length_h) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %hd", -112000);
  sprintf(buffer2, "Test: %hd", -112000);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_length_h) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %hu", 12999999);
  sprintf(buffer2, "Test: %hu", 12999999);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_length_l) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %ld", -6120000000);
  sprintf(buffer2, "Test: %ld", -6120000000);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_length_l) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "Test: %lu", 9120000000);
  sprintf(buffer2, "Test: %lu", 9120000000);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_int_flags_with_width) {
  char buffer1[20] = {0};
  char buffer2[20] = {0};

  // Тест с флагом '+'
  s21_sprintf(buffer1, "Test: %+10d", 42);
  sprintf(buffer2, "Test: %+10d", 42);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест с флагом '-'
  s21_sprintf(buffer1, "Test: %-10d", 42);
  sprintf(buffer2, "Test: %-10d", 42);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест с флагом ' '
  s21_sprintf(buffer1, "Test: % 10d", 42);
  sprintf(buffer2, "Test: % 10d", 42);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_float_flags_with_width) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  // Тест с флагом '+'

  float value = 3.141592;

  s21_sprintf(buffer1, "Test: %+10.2f", value);
  sprintf(buffer2, "Test: %+10.2f", value);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест с флагом '-'
  s21_sprintf(buffer1, "Test: %-10.2f", value);
  sprintf(buffer2, "Test: %-10.2f", value);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест с флагом ' '
  s21_sprintf(buffer1, "Test: % 10.2f", value);
  sprintf(buffer2, "Test: % 10.2f", value);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_unsigned_int_flags_with_width) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  unsigned int value = 42;

  // Тест с флагом '-'
  s21_sprintf(buffer1, "Test: %-10u", value);
  sprintf(buffer2, "Test: %-10u", value);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_char_width) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};
  char symbol = 'c';

  s21_sprintf(buffer1, "Test: %10c", symbol);
  sprintf(buffer2, "Test: %10c", symbol);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_string_flags_with_width) {
  char buffer1[10000] = {0};
  char buffer2[10000] = {0};

  char string[20] = "Hello";

  // Тест с флагом '-'
  s21_sprintf(buffer1, "Test: %-2000s test", string);
  sprintf(buffer2, "Test: %-2000s test", string);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "Test: %10s", string);
  sprintf(buffer2, "Test: %10s", string);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(to_upper) {
  char input[20] = "This is Test1!";

  void *result;
  char *expected = "THIS IS TEST1!";

  result = s21_to_upper(input);

  ck_assert_str_eq((char *)result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower) {
  char input[20] = "This is Test2!";

  void *result;
  char *expected = "this is test2!";

  result = s21_to_lower(input);

  ck_assert_str_eq((char *)result, expected);
  free(result);
}
END_TEST

START_TEST(insert) {
  char input[20] = "make";

  void *result;
  char *expected = "maALLke";

  result = s21_insert(input, "ALL", 2);
  ck_assert_str_eq((char *)result, expected);
  free(result);

  result = s21_insert(S21_NULL, "ALL", 2);
  ck_assert_ptr_null(result);
  free(result);

  result = s21_insert(input, S21_NULL, 2);
  ck_assert_ptr_null(result);
  free(result);

  result = s21_insert(input, "ALL", 10);
  ck_assert_ptr_null(result);

  free(result);  // malloc in insert
}
END_TEST

START_TEST(insert_basic) {
  char input1[20] = "make";
  void *result1;
  char *expected1 = "maALLke";
  result1 = s21_insert(input1, "ALL", 2);
  ck_assert_str_eq((char *)result1, expected1);
  free(result1);

  char input2[20] = "12345";
  void *result2;
  char *expected2 = "1ABC2345";
  result2 = s21_insert(input2, "ABC", 1);
  ck_assert_str_eq((char *)result2, expected2);
  free(result2);

  char input3[20] = "";
  void *result3;
  char *expected3 = "XYZ";
  result3 = s21_insert(input3, "XYZ", 0);
  ck_assert_str_eq((char *)result3, expected3);
  free(result3);
}
END_TEST

START_TEST(insert_edge_cases) {
  char input1[20] = "hello";
  void *result1;
  char *expected1 = "helloALL";
  result1 = s21_insert(input1, "ALL", 5);
  ck_assert_str_eq((char *)result1, expected1);
  free(result1);

  char input2[20] = "world";
  void *result2;
  char *expected2 = "ALLworld";
  result2 = s21_insert(input2, "ALL", 0);
  ck_assert_str_eq((char *)result2, expected2);
  free(result2);

  // проверка на выход за пределы длины строки
  char input3[20] = "abc";
  void *result3;
  result3 = s21_insert(input3, "XYZ", 10);
  ck_assert_ptr_null(result3);
  free(result3);
}
END_TEST

START_TEST(trim) {
  char input1[20] = "1112make32221";
  char input2[20] = "\t 123make123   \n";
  char input3[20] = "\t 123make123   \n";
  char input4[20] = "\t\r 123make123   \n";
  char input5[20] = "1231231232131231";

  void *result;
  char *expected1 = "make";
  char *expected2 = "\t 123make123   \n";
  char *expected3 = "123make123";
  char *expected4 = "123make123";
  char *expected5 = "";

  result = s21_trim(input1, "123");
  ck_assert_str_eq((char *)result, expected1);

  free(result);  // malloc in trim

  result = s21_trim(input2, "123");
  ck_assert_str_eq((char *)result, expected2);

  free(result);  // malloc in trim

  result = s21_trim(input3, "");
  ck_assert_str_eq((char *)result, expected3);

  free(result);  // malloc in trim

  result = s21_trim(input4, S21_NULL);
  ck_assert_str_eq((char *)result, expected4);

  free(result);  // malloc in trim

  result = s21_trim(input5, "123");
  ck_assert_str_eq((char *)result, expected5);

  free(result);  // malloc in trim

  result = s21_trim(S21_NULL, "");
  ck_assert_ptr_null(result);

  free(result);  // malloc in trim
}
END_TEST

Suite *my_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MyString");
  tc_core = tcase_create("Core");

  // MEMCHR
  tcase_add_test(tc_core, memchr_1);
  tcase_add_test(tc_core, memchr_2);

  // MEMCPY
  tcase_add_test(tc_core, memcpy_1);
  tcase_add_test(tc_core, memcpy_2);
  tcase_add_test(tc_core, memcpy_3);

  // MEMSET
  tcase_add_test(tc_core, memset_1);
  tcase_add_test(tc_core, memset_2);

  // MEMCMP
  tcase_add_test(tc_core, memcmp_1);
  tcase_add_test(tc_core, memcmp_2);
  tcase_add_test(tc_core, memcmp_3);
  tcase_add_test(tc_core, memcmp_4);

  // STRNCAT
  tcase_add_test(tc_core, strncat_1);
  tcase_add_test(tc_core, strncat_2);

  // STRCHR
  tcase_add_test(tc_core, strchr_1);
  tcase_add_test(tc_core, strchr_2);
  tcase_add_test(tc_core, strchr_3);

  // STRCSPN
  tcase_add_test(tc_core, strcspn_1);
  tcase_add_test(tc_core, strcspn_2);

  // STRLEN
  tcase_add_test(tc_core, strlen_1);
  tcase_add_test(tc_core, strlen_2);

  // STRPBRK
  tcase_add_test(tc_core, strpbrk_1);
  tcase_add_test(tc_core, strpbrk_2);

  // STRRCHR
  tcase_add_test(tc_core, strrchr_1);
  tcase_add_test(tc_core, strrchr_2);
  tcase_add_test(tc_core, strrchr_3);

  // STRSTR
  tcase_add_test(tc_core, strstr_1);
  tcase_add_test(tc_core, strstr_2);
  tcase_add_test(tc_core, strstr_3);
  tcase_add_test(tc_core, strstr_empty_needle);

  // STRNCMP
  tcase_add_test(tc_core, strncmp_1);
  tcase_add_test(tc_core, strncmp_2);
  tcase_add_test(tc_core, strncmp_3);
  tcase_add_test(tc_core, strncmp_4);

  // STRNCPY
  tcase_add_test(tc_core, strncpy_1);
  tcase_add_test(tc_core, strncpy_2);
  tcase_add_test(tc_core, strncpy_3);
  tcase_add_test(tc_core, strncpy_4);

  // STRTOK
  tcase_add_test(tc_core, strtok_1);
  tcase_add_test(tc_core, strtok_2);
  tcase_add_test(tc_core, strtok_3);
  tcase_add_test(tc_core, strtok_4);
  tcase_add_test(tc_core, strtok_5);
  tcase_add_test(tc_core, strtok_6);
  tcase_add_test(tc_core, strtok_7);
  tcase_add_test(tc_core, strtok_8);

  // STRERROR
  tcase_add_test(tc_core, strerror_1);

  // SPRINTF
  tcase_add_test(tc_core, test_sprintf_int_left_orientation);
  tcase_add_test(tc_core, test_sprintf_int_right_orientation);
  tcase_add_test(tc_core, test_sprintf_int_negative);
  tcase_add_test(tc_core, test_sprintf_float);
  tcase_add_test(tc_core, test_sprintf_float_negative);
  tcase_add_test(tc_core, test_sprintf_string);
  tcase_add_test(tc_core, test_sprintf_char);
  tcase_add_test(tc_core, test_sprintf_unsigned);

  // PRECISION
  tcase_add_test(tc_core, test_sprintf_int_precision_positive);
  tcase_add_test(tc_core, test_sprintf_int_precision_null);
  tcase_add_test(tc_core, test_sprintf_int_precision_no_explicit_meaning);

  tcase_add_test(tc_core, test_sprintf_unsigned_int_precision_positive);
  tcase_add_test(tc_core, test_sprintf_unsigned_int_precision_null);
  tcase_add_test(tc_core,
                 test_sprintf_unsigned_int_precision_no_explicit_meaning);

  tcase_add_test(tc_core, test_sprintf_double_precision_positive);
  tcase_add_test(tc_core, test_sprintf_double_precision_null);
  tcase_add_test(tc_core, test_sprintf_double_precision_no_explicit_meaning);

  tcase_add_test(tc_core, test_sprintf_string_precision_positive);
  tcase_add_test(tc_core, test_sprintf_string_precision_null);
  tcase_add_test(tc_core, test_sprintf_string_precision_no_explicit_meaning);

  tcase_add_test(tc_core, test_sprintf_int_length_h);
  tcase_add_test(tc_core, test_sprintf_unsigned_int_length_h);

  tcase_add_test(tc_core, test_sprintf_int_length_l);
  tcase_add_test(tc_core, test_sprintf_unsigned_int_length_l);

  // SPRINTF FLAGS
  tcase_add_test(tc_core, test_sprintf_int_flags_with_width);
  tcase_add_test(tc_core, test_sprintf_float_flags_with_width);
  tcase_add_test(tc_core, test_sprintf_unsigned_int_flags_with_width);
  tcase_add_test(tc_core, test_sprintf_char_width);
  tcase_add_test(tc_core, test_sprintf_string_flags_with_width);

  // Special string processing functions (from the String class in C#)
  tcase_add_test(tc_core, to_upper);
  tcase_add_test(tc_core, to_lower);
  tcase_add_test(tc_core, insert);
  tcase_add_test(tc_core, insert_basic);
  tcase_add_test(tc_core, insert_edge_cases);
  tcase_add_test(tc_core, trim);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = my_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? SUCCESS : ERROR;
}
