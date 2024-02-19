#include "../s21_string.h"

#include <check.h>
#include <string.h>

// memchr tests

START_TEST(s21_memchr_cmp) {
  char str[16] = "Hello World";
  int c = 'o';
  s21_size_t n = s21_strlen(str);
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_no_cmp) {
  char str[16] = "Hello World";
  int c = 'a';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_less_n) {
  char str[16] = "I'm tired";
  int c = 'd';
  s21_size_t n = s21_strlen(str) + 4;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_empty) {
  char str[2] = "";
  int c = 'p';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_c_null) {
  char str[16] = "65tfhdf";
  int c = '\0';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_c_less_Zero) {
  char str[16] = "65tfhdf";
  int c = -6;
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_n_eq_Zero) {
  char str[16] = "65tfhdf";
  int c = 't';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_null) {
  char *str = s21_NULL;
  int c = 't';
  s21_size_t n = 0;
  ck_assert_ptr_null(s21_memchr(str, c, n));
}
END_TEST

// memcmp tests

START_TEST(s21_memcmp_part_cmp) {
  char str_1[5][16] = {"65tfhdf", "ajhesdtjf", "8273tq", "auerta", "u237tr"};
  char str_2[5][16] = {"65tfbvh", "ajhesdtgf", "8273aw", "auertp", "u2-7tr"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]);
    int res_1 = s21_memcmp(str_1[i], str_2[i], n);
    int res_2 = memcmp(str_1[i], str_2[i], n);
    ck_assert_int_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(s21_memcmp_len_less_n) {
  char str_1[16] = "aksudfd";
  char str_2[16] = "df";
  s21_size_t n = s21_strlen(str_1) + 4;
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_n_eq_zero) {
  char str_1[16] = "asd45;wr";
  char str_2[16] = ":wr";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_memcmp_str1_null) {
  char *str_1 = "";
  char str_2[16] = ":wr";
  s21_size_t n = 1;
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_str2_null) {
  char str_1[16] = "aksfaaf";
  char *str_2 = "";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_full_cmp) {
  char str_1[16] = "memcmp test";
  char str_2[16] = "memcmp test";
  s21_size_t n = s21_strlen(str_1);
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_memcmp_no_cmp) {
  char str_1[16] = "memcmp test";
  char str_2[16] = ";<w";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// memcpy tests

START_TEST(s21_memcpy_default) {
  char dest_1[16] = "";
  char dest_2[16] = "";
  char src[5][16] = {"memcpy test", "some text", "adfaw45", "aijfa o",
                     "1q024578"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(src[i]);
    s21_memcpy(dest_1, src[i], n);
    memcpy(dest_2, src[i], n);
    ck_assert_str_eq(dest_1, dest_2);
    dest_1[0] = '\0';
    dest_2[0] = '\0';
  }
}
END_TEST

START_TEST(s21_memcpy_dest_not_empty) {
  char dest_1[16] = "ahsdgf";
  char dest_2[16] = "ahsdgf";
  char src[16] = "trulyalya";
  s21_size_t n = s21_strlen(src);
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_memcpy_src_empty) {
  char dest_1[16] = "zsdfasd";
  char dest_2[16] = "zsdfasd";
  char src[16] = "";
  s21_size_t n = s21_strlen(src);
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_memcpy_n_eq_zero) {
  char dest_1[16] = "ashdf";
  char dest_2[16] = "ashdf";
  char src[16] = "jhagsdf";
  s21_size_t n = 0;
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_pstr_eq(dest_1, dest_2);
}
END_TEST

// memset tests

START_TEST(s21_memset_default) {
  char str_1[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  char str_2[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  int c = 56;
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]) - 3;
    s21_memset(str_1[i], c, n);
    memset(str_2[i], c, n);
    ck_assert_str_eq(str_1[i], str_2[i]);
  }
}
END_TEST

START_TEST(s21_memset_NULL) {
  char *str_1 = s21_NULL;
  char *str_2 = s21_NULL;
  int c = 56;
  s21_size_t n = 0;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_n_zero) {
  char str_1[16] = "s21_NULL";
  char str_2[16] = "s21_NULL";
  int c = 56;
  s21_size_t n = 0;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_c_less_zero) {
  char str_1[16] = "trulala";
  char str_2[16] = "trulala";
  int c = -56;
  s21_size_t n = 2;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_str_empty) {
  char str_1[16] = "\0";
  char str_2[16] = "\0";
  int c = 56;
  s21_size_t n = 13;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// strncat tests

START_TEST(s21_strncat_default) {
  char dest_1[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  char dest_2[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  char src[5][16] = {"yawgfe", "1o824", " iuraf", "5465", "13qou74r"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(src[i]);
    s21_strncat(dest_1[i], src[i], n);
    strncat(dest_2[i], src[i], n);
    ck_assert_str_eq(dest_1[i], dest_2[i]);
  }
}
END_TEST

START_TEST(s21_strncat_len_less_dest) {
  char dest_1[32] = "asdfasdf";
  char dest_2[32] = "asdfasdf";
  char src[16] = "nqurt";
  s21_size_t n = s21_strlen(src) - 2;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncat_dest_less_len) {
  char dest_1[20] = "aiuey que";
  char dest_2[20] = "aiuey que";
  char src[16] = "98ahgoladhuhdk";
  s21_size_t n = s21_strlen(src);
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncat_empty_dest) {
  char dest_1[16] = "";
  char dest_2[16] = "";
  char src[16] = "nqurt";
  s21_size_t n = s21_strlen(src);
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncat_empty_src) {
  char dest_1[16] = "ASiausdyf";
  char dest_2[16] = "ASiausdyf";
  char src[16] = "\0";
  s21_size_t n = s21_strlen(src);
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncat_all_empty) {
  char dest_1[16] = "\0";
  char dest_2[16] = "\0";
  char src[16] = "\0";
  s21_size_t n = s21_strlen(src);
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

// strchr test

START_TEST(s21_strchr_cmp) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  int array_symb[5] = {'w', 'r', 'h', 'x', 'u'};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strchr(array_str[i], array_symb[i]),
                     strchr(array_str[i], array_symb[i]));
}
END_TEST

START_TEST(s21_strchr_no_cmp) {
  char *str = "z86hs-vbcx";
  int symb = 'o';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_less_zero) {
  char *str = "kuyuteasd";
  int symb = -1;
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_null_symb) {
  char *str = "Hello World";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_empty_str) {
  char *str = "";
  int symb = 'a';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_empty_str_symb) {
  char *str = "";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

// strncmp test

START_TEST(s21_strncmp_part_cmp) {
  char str_1[5][16] = {"65tfhdf", "ajhesdtjf", "8273tq", "auerta", "u237tr"};
  char str_2[5][16] = {"65tfbvh", "ajhesdtgf", "8273aw", "auertp", "u2-7tr"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]);
    int res_1 = s21_strncmp(str_1[i], str_2[i], n);
    int res_2 = strncmp(str_1[i], str_2[i], n);
    ck_assert_int_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(s21_strncmp_len_less_n) {
  char str_1[16] = "aksudfd";
  char str_2[16] = "df";
  s21_size_t n = s21_strlen(str_1) + 4;
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_n_eq_zero) {
  char str_1[16] = "asd45;wr";
  char str_2[16] = ":wr";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_strncmp_str1_null) {
  char *str_1 = "";
  char str_2[16] = ":wr";
  s21_size_t n = 2;
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_str2_null) {
  char str_1[16] = "aksfaaf";
  char *str_2 = "";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_full_cmp) {
  char str_1[16] = "strncmp test";
  char str_2[16] = "strncmp test";
  s21_size_t n = s21_strlen(str_1);
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_strncmp_no_cmp) {
  char str_1[16] = "strncmp test";
  char str_2[16] = ";<w";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// strncpy test

START_TEST(s21_strncpy_default) {
  char dest_1[16] = "";
  char dest_2[16] = "";
  char src[5][16] = {"strncpy test", "some text", "adfaw45", "aijfa o",
                     "1q024578"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(src[i]);
    s21_strncpy(dest_1, src[i], n);
    strncpy(dest_2, src[i], n);
    ck_assert_str_eq(dest_1, dest_2);
    dest_1[0] = '\0';
    dest_2[0] = '\0';
  }
}
END_TEST

START_TEST(s21_strncpy_dest_not_empty) {
  char dest_1[16] = "ahsdgf";
  char dest_2[16] = "ahsdgf";
  char src[16] = "trulyalya";
  s21_size_t n = s21_strlen(src);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncpy_src_empty) {
  char dest_1[16] = "zsdfasd";
  char dest_2[16] = "zsdfasd";
  char src[16] = "";
  s21_size_t n = s21_strlen(src);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncpy_n_eq_zero) {
  char dest_1[16] = "ashdf";
  char dest_2[16] = "ashdf";
  char src[16] = "jhagsdf";
  s21_size_t n = 0;
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_pstr_eq(dest_1, dest_2);
}
END_TEST
START_TEST(s21_strncpy_src_shorter) {
  char dest_1[16] = "ahsdgsdafgf";
  char dest_2[16] = "ahsdgsdafgf";
  char src[4] = "tro\0";
  s21_size_t n = s21_strlen(dest_1);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}

// strcspn tests

START_TEST(s21_strcspn_match) {
  char array_str_1[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                             "t3q45h"};
  char array_str_2[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_int_eq(s21_strcspn(array_str_1[i], array_str_2[i]),
                     strcspn(array_str_1[i], array_str_2[i]));
}
END_TEST

START_TEST(s21_strcspn_no_match) {
  char str_1[12] = "sf2q345dusf";
  char str_2[3] = "31";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_2_empty) {
  char str_1[9] = "k3245asd";
  char *str_2 = "\0";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_1_empty) {
  char str_1[9] = "";
  char str_2[4] = ";5s";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_1_str_2_empty) {
  char str_1[4] = "";
  char str_2[4] = "\0";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

// strerror tests

START_TEST(s21_strerror_test) {
  for (int i = -5; i < 150; i++) ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST

START_TEST(s21_strerror_long_int_pos) {
  int num_3 = 2147483647;
  ck_assert_str_eq(strerror(num_3), s21_strerror(num_3));
}
END_TEST

START_TEST(s21_strerror_long_int_neg) {
  int num_4 = -2147483647;
  ck_assert_str_eq(strerror(num_4), s21_strerror(num_4));
}
END_TEST

// strlen tests

START_TEST(s21_strlen_default) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  for (int i = 0; i < 5; i++)
    ck_assert_int_eq(s21_strlen(array_str[i]), strlen(array_str[i]));
}
END_TEST

START_TEST(s21_strlen_null) {
  char *str = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

// strpbrk tests

START_TEST(s21_strpbrk_match) {
  char array_str1[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                            "t3q45h"};
  char array_str2[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strpbrk(array_str1[i], array_str2[i]),
                     strpbrk(array_str1[i], array_str2[i]));
}
END_TEST

START_TEST(s21_strpbrk_no_match) {
  char str1[12] = "sf2q345dusf";
  char str2[3] = "31";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str2_empty) {
  char str1[9] = "k3245asd";
  char *str2 = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str1_empty) {
  char str1[9] = "";
  char str2[4] = ";5s";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str1_str2_empty) {
  char str1[4] = "";
  char str2[4] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// strrchr tests

START_TEST(s21_strrchr_cmp) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  int array_symb[5] = {'w', 'r', 'h', 'x', 'u'};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strrchr(array_str[i], array_symb[i]),
                     strrchr(array_str[i], array_symb[i]));
}
END_TEST

START_TEST(s21_strrchr_no_cmp) {
  char *str = "z86hs-vbcx";
  int symb = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_less_zero) {
  char *str = "kuyuteasd";
  int symb = -100;
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_null_symb) {
  char *str = "Hello World";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_empty_str) {
  char *str = "";
  int symb = 'a';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_empty_str_symb) {
  char *str = "";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

// strstr tests
START_TEST(s21_strstr_match) {
  char array_haystack[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                                "t3q45h"};
  char array_needle[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strstr(array_haystack[i], array_needle[i]),
                     strstr(array_haystack[i], array_needle[i]));
}
END_TEST

START_TEST(s21_strstr_no_match) {
  char haystack[12] = "sf2q345dusf";
  char needle[3] = "31";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_needle_empty) {
  char haystack[9] = "k3245asd";
  char *needle = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_haystack_empty) {
  char haystack[9] = "";
  char needle[4] = ";5s";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_haystack_needle_empty) {
  char haystack[4] = "";
  char needle[4] = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// strtok tests

START_TEST(s21_strtok_match) {
  char str_1[32] = "test1/test2/test3/test4";
  char str_2[32] = "test1/test2/test3/test4";
  char delim[4] = "/,";
  ck_assert_str_eq(s21_strtok(str_1, delim), strtok(str_2, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_one_token) {
  char str[32] = "test1/test2/test3/test4";
  char delim[4] = " ,";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
  ck_assert_pstr_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_empty_delim) {
  char str[32] = "qtw824rgyf8q3";
  char delim[4] = "\0";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_empty_str) {
  char str[4] = "";
  char delim[4] = ";,";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_empty_str_delim) {
  char str[4] = "";
  char *delim = "\0";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

// Suits

Suite *memchr_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("s21_memchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memchr_cmp);
  tcase_add_test(tc_core, s21_memchr_no_cmp);
  tcase_add_test(tc_core, s21_memchr_str_empty);
  tcase_add_test(tc_core, s21_memchr_str_less_n);
  tcase_add_test(tc_core, s21_memchr_str_null);
  tcase_add_test(tc_core, s21_memchr_c_null);
  tcase_add_test(tc_core, s21_memchr_c_less_Zero);
  tcase_add_test(tc_core, s21_memchr_n_eq_Zero);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *memcmp_suite(void) {
  Suite *s2;
  TCase *tc_core;
  s2 = suite_create("s21_memcmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcmp_part_cmp);
  tcase_add_test(tc_core, s21_memcmp_len_less_n);
  tcase_add_test(tc_core, s21_memcmp_n_eq_zero);
  tcase_add_test(tc_core, s21_memcmp_str1_null);
  tcase_add_test(tc_core, s21_memcmp_str2_null);
  tcase_add_test(tc_core, s21_memcmp_no_cmp);
  tcase_add_test(tc_core, s21_memcmp_full_cmp);
  suite_add_tcase(s2, tc_core);
  return s2;
}

Suite *memcpy_suite(void) {
  Suite *s3;
  TCase *tc_core;
  s3 = suite_create("s21_memcpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcpy_default);
  tcase_add_test(tc_core, s21_memcpy_dest_not_empty);
  tcase_add_test(tc_core, s21_memcpy_src_empty);
  tcase_add_test(tc_core, s21_memcpy_n_eq_zero);
  suite_add_tcase(s3, tc_core);
  return s3;
}

Suite *memset_suite(void) {
  Suite *s4;
  TCase *tc_core;
  s4 = suite_create("s21_memset");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memset_default);
  tcase_add_test(tc_core, s21_memset_NULL);
  tcase_add_test(tc_core, s21_memset_n_zero);
  tcase_add_test(tc_core, s21_memset_c_less_zero);
  tcase_add_test(tc_core, s21_memset_str_empty);
  suite_add_tcase(s4, tc_core);
  return s4;
}

Suite *strncat_suite(void) {
  Suite *s5;
  TCase *tc_core;
  s5 = suite_create("s21_strncat");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncat_default);
  tcase_add_test(tc_core, s21_strncat_len_less_dest);
  tcase_add_test(tc_core, s21_strncat_dest_less_len);
  tcase_add_test(tc_core, s21_strncat_empty_dest);
  tcase_add_test(tc_core, s21_strncat_empty_src);
  tcase_add_test(tc_core, s21_strncat_all_empty);
  suite_add_tcase(s5, tc_core);
  return s5;
}

Suite *strchr_suite(void) {
  Suite *s6;
  TCase *tc_core;
  s6 = suite_create("s21_strchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strchr_cmp);
  tcase_add_test(tc_core, s21_strchr_no_cmp);
  tcase_add_test(tc_core, s21_strchr_less_zero);
  tcase_add_test(tc_core, s21_strchr_null_symb);
  tcase_add_test(tc_core, s21_strchr_empty_str);
  tcase_add_test(tc_core, s21_strchr_empty_str_symb);
  suite_add_tcase(s6, tc_core);
  return s6;
}

Suite *strncmp_suite(void) {
  Suite *s7;
  TCase *tc_core;
  s7 = suite_create("s21_strncmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncmp_part_cmp);
  tcase_add_test(tc_core, s21_strncmp_len_less_n);
  tcase_add_test(tc_core, s21_strncmp_n_eq_zero);
  tcase_add_test(tc_core, s21_strncmp_str1_null);
  tcase_add_test(tc_core, s21_strncmp_str2_null);
  tcase_add_test(tc_core, s21_strncmp_no_cmp);
  tcase_add_test(tc_core, s21_strncmp_full_cmp);
  suite_add_tcase(s7, tc_core);
  return s7;
}

Suite *strncpy_suite(void) {
  Suite *s8;
  TCase *tc_core;
  s8 = suite_create("s21_strncpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncpy_default);
  tcase_add_test(tc_core, s21_strncpy_dest_not_empty);
  tcase_add_test(tc_core, s21_strncpy_src_empty);
  tcase_add_test(tc_core, s21_strncpy_n_eq_zero);
  tcase_add_test(tc_core, s21_strncpy_src_shorter);
  suite_add_tcase(s8, tc_core);
  return s8;
}

Suite *strcspn_suite(void) {
  Suite *s9;
  TCase *tc_core;
  s9 = suite_create("s21_strcspn");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strcspn_match);
  tcase_add_test(tc_core, s21_strcspn_no_match);
  tcase_add_test(tc_core, s21_strcspn_str_2_empty);
  tcase_add_test(tc_core, s21_strcspn_str_1_empty);
  tcase_add_test(tc_core, s21_strcspn_str_1_str_2_empty);
  suite_add_tcase(s9, tc_core);
  return s9;
}

Suite *strerror_suite(void) {
  Suite *s10;
  TCase *tc_core;
  s10 = suite_create("s21_strerror");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strerror_test);
  tcase_add_test(tc_core, s21_strerror_long_int_neg);
  tcase_add_test(tc_core, s21_strerror_long_int_pos);
  suite_add_tcase(s10, tc_core);
  return s10;
}

Suite *strlen_suite(void) {
  Suite *s11;
  TCase *tc_core;
  s11 = suite_create("s21_strlen");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strlen_default);
  tcase_add_test(tc_core, s21_strlen_null);
  suite_add_tcase(s11, tc_core);
  return s11;
}

Suite *strpbrk_suite(void) {
  Suite *s12;
  TCase *tc_core;
  s12 = suite_create("s21_strpbrk");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strpbrk_match);
  tcase_add_test(tc_core, s21_strpbrk_no_match);
  tcase_add_test(tc_core, s21_strpbrk_str2_empty);
  tcase_add_test(tc_core, s21_strpbrk_str1_empty);
  tcase_add_test(tc_core, s21_strpbrk_str1_str2_empty);
  suite_add_tcase(s12, tc_core);
  return s12;
}

Suite *strrchr_suite(void) {
  Suite *s13;
  TCase *tc_core;
  s13 = suite_create("s21_strrchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strrchr_cmp);
  tcase_add_test(tc_core, s21_strrchr_no_cmp);
  tcase_add_test(tc_core, s21_strrchr_less_zero);
  tcase_add_test(tc_core, s21_strrchr_null_symb);
  tcase_add_test(tc_core, s21_strrchr_empty_str);
  tcase_add_test(tc_core, s21_strrchr_empty_str_symb);
  suite_add_tcase(s13, tc_core);
  return s13;
}

Suite *strstr_suite(void) {
  Suite *s14;
  TCase *tc_core;
  s14 = suite_create("s21_strstr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strstr_match);
  tcase_add_test(tc_core, s21_strstr_no_match);
  tcase_add_test(tc_core, s21_strstr_needle_empty);
  tcase_add_test(tc_core, s21_strstr_haystack_empty);
  tcase_add_test(tc_core, s21_strstr_haystack_needle_empty);
  suite_add_tcase(s14, tc_core);
  return s14;
}

Suite *strtok_suite(void) {
  Suite *s15;
  TCase *tc_core;
  s15 = suite_create("s21_strtok");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtok_match);
  tcase_add_test(tc_core, s21_strtok_one_token);
  tcase_add_test(tc_core, s21_strtok_empty_delim);
  tcase_add_test(tc_core, s21_strtok_empty_str);
  tcase_add_test(tc_core, s21_strtok_empty_str_delim);
  suite_add_tcase(s15, tc_core);
  return s15;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(memchr_suite(), &fail);
  case_test(memcmp_suite(), &fail);
  case_test(memcpy_suite(), &fail);
  case_test(memset_suite(), &fail);
  case_test(strncat_suite(), &fail);
  case_test(strchr_suite(), &fail);
  case_test(strncmp_suite(), &fail);
  case_test(strncpy_suite(), &fail);
  case_test(strcspn_suite(), &fail);
  case_test(strerror_suite(), &fail);
  case_test(strlen_suite(), &fail);
  case_test(strpbrk_suite(), &fail);
  case_test(strrchr_suite(), &fail);
  case_test(strstr_suite(), &fail);
  case_test(strtok_suite(), &fail);
  return fail;
}