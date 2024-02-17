#include <check.h>

#include "s21_string.h"

// to_upper tests

START_TEST(s21_to_upper_default) {
  char str[10][32] = {
      "auysdgf",   "had;qiuef", "lsdkf wig", "^lsdkf:", "kasjfaksf",
      "~ 'aas;of", "ai2p5iu",   "||\\mjag",  "q0984r0", "/+4asf"};

  char expected_result[10][32] = {
      "AUYSDGF",   "HAD;QIUEF", "LSDKF WIG", "^LSDKF:", "KASJFAKSF",
      "~ 'AAS;OF", "AI2P5IU",   "||\\MJAG",  "Q0984R0", "/+4ASF"};

  for (int i = 0; i < 10; i++)
    ck_assert_str_eq(s21_to_upper(str[i]), expected_result[i]);
}
END_TEST

START_TEST(s21_to_upper_no_letters) {
  char str[16] = "\n\t/*-7894{}";
  char expected_res[16] = "\n\t/*-7894{}";
  ck_assert_str_eq(s21_to_upper(str), expected_res);
}
END_TEST

START_TEST(s21_to_upper_str_null) {
  char *str = S21_NULL;
  char *expected_res = S21_NULL;
  ck_assert_pstr_eq(s21_to_upper(str), expected_res);
}
END_TEST

// to lower tests

START_TEST(s21_to_lower_default) {
  char str[10][32] = {
      "AUYSDGF",   "HAD;QIUEF", "LSDKF WIG", "^LSDKF:", "KASJFAKSF",
      "~ 'AAS;OF", "AI2P5IU",   "||\\MJAG",  "Q0984R0", "/+4ASF"};

  char expected_result[10][32] = {
      "auysdgf",   "had;qiuef", "lsdkf wig", "^lsdkf:", "kasjfaksf",
      "~ 'aas;of", "ai2p5iu",   "||\\mjag",  "q0984r0", "/+4asf"};

  for (int i = 0; i < 10; i++)
    ck_assert_str_eq(s21_to_lower(str[i]), expected_result[i]);
}
END_TEST

START_TEST(s21_to_lower_no_letters) {
  char str[16] = "\n\t/*-7894{}";
  char expected_res[16] = "\n\t/*-7894{}";
  ck_assert_str_eq(s21_to_lower(str), expected_res);
}
END_TEST

START_TEST(s21_to_lower_str_null) {
  char *str = S21_NULL;
  char *expected_res = S21_NULL;
  ck_assert_pstr_eq(s21_to_lower(str), expected_res);
}
END_TEST

// insert tests

START_TEST(s21_insert_default) {
  char src[5][64] = {"kuswjghks", "kasgdfkja", "q8r7hsa", "9o8q4ryf", "18svva"};
  char str[5][64] = {"aq276r", "29ihff ", "654aff", "2983rty", "987uyfd"};
  s21_size_t start_index = 5;
  char expected_res[5][64] = {"kuswjaq276rghks", "kasgd29ihff fkja",
                              "q8r7h654affsa", "9o8q42983rtyryf",
                              "18svv987uyfda"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_insert(src[i], str[i], start_index), expected_res[i]);
}
END_TEST

START_TEST(s21_insert_index_zero) {
  char src[16] = "kuswjghks";
  char str[16] = "29ihff";
  s21_size_t start_index = 0;
  char expected_res[32] = "29ihffkuswjghks";
  ck_assert_str_eq(s21_insert(src, str, start_index), expected_res);
}
END_TEST

START_TEST(s21_insert_len_less_index) {
  char src[16] = "kjgh";
  char str[16] = "75tr";
  s21_size_t start_index = 13;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), S21_NULL);
}
END_TEST

START_TEST(s21_insert_index_less_zero) {
  char src[16] = "kjgh";
  char str[16] = "75tr";
  s21_size_t start_index = -13;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), S21_NULL);
}
END_TEST

START_TEST(s21_insert_src_null) {
  char *src = S21_NULL;
  char str[16] = "75tr";
  s21_size_t start_index = 13;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), S21_NULL);
}
END_TEST

START_TEST(s21_insert_str_null) {
  char src[16] = "akjshf";
  char *str = S21_NULL;
  s21_size_t start_index = 13;
  ck_assert_ptr_eq(s21_insert(src, str, start_index), S21_NULL);
}
END_TEST

// trim tests

START_TEST(s21_trim_default) {
  char src[5][64] = {"   zkjdhfg    ", "kasgdfkja", "zxcshdfshxzc", "\tzsdhf",
                     "\nasdf\tadfgaf\t\t\t"};
  char trim_chars[5][64] = {" ", "zsdf", "zxc", "\t", "\n\t"};
  char expected_res[5][64] = {"zkjdhfg", "kasgdfkja", "shdfsh", "zsdhf",
                              "asdf\tadfgaf"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_trim(src[i], trim_chars[i]), expected_res[i]);
}
END_TEST

START_TEST(s21_trim_all_comp) {
  char src[64] = "ababbababababa";
  char trim_chars[64] = "ba";
  char expected_res[64] = "";
  ck_assert_str_eq(s21_trim(src, trim_chars), expected_res);
}
END_TEST

START_TEST(s21_trim_chars_null) {
  char src[64] = "\t\n zsjdff\r\t";
  char *trim_chars = S21_NULL;
  char expected_res[64] = "zsjdff";
  ck_assert_str_eq(s21_trim(src, trim_chars), expected_res);
}
END_TEST

START_TEST(s21_trim_src_null) {
  char *src = S21_NULL;
  char trim_chars[64] = "aff";
  char *expected_res = S21_NULL;
  ck_assert_ptr_eq(s21_trim(src, trim_chars), expected_res);
}
END_TEST

START_TEST(s21_trim_empty_src) {
  char src[64] = "";
  char trim_chars[64] = "zcvv";
  char expected_res[64] = "";
  ck_assert_str_eq(s21_trim(src, trim_chars), expected_res);
}
END_TEST

START_TEST(s21_trim_empty_char) {
  char src[64] = "\ts21_NULL\t";
  char trim_chars[64] = "";
  char expected_res[64] = "S21_NULL";
  ck_assert_str_eq(s21_trim(src, trim_chars), expected_res);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("s21_to_upper");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_upper_default);
  tcase_add_test(tc_core, s21_to_upper_no_letters);
  tcase_add_test(tc_core, s21_to_upper_str_null);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *to_lower_suite(void) {
  Suite *s2;
  TCase *tc_core;
  s2 = suite_create("s21_to_lower");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_lower_default);
  tcase_add_test(tc_core, s21_to_lower_no_letters);
  tcase_add_test(tc_core, s21_to_lower_str_null);
  suite_add_tcase(s2, tc_core);
  return s2;
}

Suite *insert_suite(void) {
  Suite *s3;
  TCase *tc_core;
  s3 = suite_create("s21_insert");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_insert_default);
  tcase_add_test(tc_core, s21_insert_index_zero);
  tcase_add_test(tc_core, s21_insert_len_less_index);
  tcase_add_test(tc_core, s21_insert_index_less_zero);
  tcase_add_test(tc_core, s21_insert_src_null);
  tcase_add_test(tc_core, s21_insert_str_null);
  suite_add_tcase(s3, tc_core);
  return s3;
}

Suite *trim_suite(void) {
  Suite *s4;
  TCase *tc_core;
  s4 = suite_create("s21_trim");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_trim_default);
  tcase_add_test(tc_core, s21_trim_all_comp);
  tcase_add_test(tc_core, s21_trim_chars_null);
  tcase_add_test(tc_core, s21_trim_empty_char);
  tcase_add_test(tc_core, s21_trim_empty_src);
  tcase_add_test(tc_core, s21_trim_src_null);
  suite_add_tcase(s4, tc_core);
  return s4;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(to_upper_suite(), &fail);
  case_test(to_lower_suite(), &fail);
  case_test(insert_suite(), &fail);
  case_test(trim_suite(), &fail);
  return fail;
}