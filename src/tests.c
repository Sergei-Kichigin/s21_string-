#include <check.h>
#include <string.h>
#include <stdio.h>

#include "s21_string.h"

// MEMCHR
START_TEST(memchr_1) {
  s21_size_t length = 10;
  char input[20] = "This is Test1";
  void *result;
  void *expected;

  result = s21_memchr(input, 's', length);
  expected = memchr(input, 's', length);

  ck_assert_mem_eq(result, expected, sizeof(expected));
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
  char result[10];
  char expected[10];

  s21_memset(result, 'A', length);
  memset(expected, 'A', length);

  ck_assert_mem_eq(result, expected, length);
}
END_TEST

START_TEST(memset_2) {
  s21_size_t length = 7;
  char result[10];
  char expected[10];

  s21_memset(result, 'B', length);
  memset(expected, 'B', length);

  ck_assert_mem_eq(result, expected, length);
}
END_TEST

// MEMCMP
START_TEST(memcmp_1) {
  s21_size_t length = 10;
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
  s21_size_t length = 10;
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

// STRNCAT
START_TEST(strncat_1) {
  s21_size_t length = 7;
  char input1[10] = "make";
  char input2[10] = "Test1";
  char *result;
  char *expected;

  result = s21_strncat(input1, input2, length);
  expected = strncat(input1, input2, length);

  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t length = 2;
  char input1[10] = "make";
  char input2[10] = "Test2";
  char *result;
  char *expected;

  result = s21_strncat(input1, input2, length);
  expected = strncat(input1, input2, length);

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

Suite *my_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MyString");
  tc_core = tcase_create("Core");

  // MEMCHR
  tcase_add_test(tc_core, memchr_1);
  tcase_add_test(tc_core, memchr_2);

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

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  // TEST
  
  char str1[10];
  char str2[10];
  sprintf(str1, "%d", 4);
  s21_sprintf(str2, "d", 4);
  printf("%s\n", str1);
  printf("%s\n", str2);

  s = my_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? SUCCESS : ERROR;
}
