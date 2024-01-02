#include <check.h>
#include <string.h>

#include "s21_string.h"

// STRLEN
START_TEST(strlen_1) {
  const char *input = "make";
  s21_size_t result = s21_strlen(input);
  s21_size_t expected = strlen(input);
  ck_assert_uint_eq(result, expected);  // compare unsigned int with size_t - unsigned long 
}
END_TEST

START_TEST(strlen_2) {
  const char *input = "";  // empty line
  s21_size_t result = s21_strlen(input);
  s21_size_t expected = strlen(input);
  ck_assert_uint_eq(result, expected);
}
END_TEST

// MEMSET
START_TEST(memset_1) {
  s21_size_t length = 5; // > 10?
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

Suite *my_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("MyString");
  tc_core = tcase_create("Core");

  // STRLEN
  tcase_add_test(tc_core, strlen_1);
  tcase_add_test(tc_core, strlen_2);

  // MEMSET
  tcase_add_test(tc_core, memset_1);
  tcase_add_test(tc_core, memset_2);

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
