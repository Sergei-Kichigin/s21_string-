#include <check.h>
#include <string.h>

#include "s21_string.h"
#include <stdio.h>

// specifier c

START_TEST(sprintf_spec_c_1) {
  char str1[400];
  char str2[400];
  const char *format = "%c %c";
  char first = ',';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_2) {
  char str1[400];
  char str2[400];
  const char *format = "%7c %0c";
  char first[8] = " xsgh,";
  char second[16] = "zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_3) {
  char str1[400];
  char str2[400];
  const char *format = "%-20c %+010c";
  char first[8] = " xsgh,";
  char second[16] = "i'm tired";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-3.3c %13.6c";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_5) {
  char str1[400];
  char str2[400];
  const char *format = "%0.2c %+0c";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_6) {
  char str1[400];
  char str2[400];
  const char *format = "%#7c % 15c";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_7) {  // нужно сделать как-то по другому
  char str1[400];
  char str2[400];
  const char *format = "%lc %c";
  wchar_t first = L'0';
  wchar_t second = L'~';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*c %*c";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 15, second),
                   sprintf(str2, format, 10, first, 15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*c %*c";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, -15, second),
                   sprintf(str2, format, -10, first, -15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_11) {
  char str1[400];
  char str2[400];
  const char *format = "%c %c";
  char first = '\n';
  char second = '\t';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_12) {
  char str1[400];
  const char *format = "some text";
  ck_assert_int_eq(s21_sprintf(str1, format), s21_strlen(format));
}
END_TEST

// specifier s
START_TEST(sprintf_spec_s_1) {
  char str1[400];
  char str2[400];
  const char *format = "%1s %s";
  char *first = ",";
  char *second = "d";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_2) {
  char str1[400];
  char str2[400];
  const char *format = "%s %s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_3) {
  char str1[400];
  char str2[400];
  const char *format = "%-20s %+20s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-3.3s %13.6s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_5) {
  char str1[400];
  char str2[400];
  const char *format = "%0.2s %+0s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_6) {
  char str1[400];
  char str2[400];
  const char *format = "%#7s % 15s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_7) {
  char str1[400];
  char str2[400];
  const char *format = "%ls %s";
  wchar_t *first = L"aydgfiaud";
  wchar_t *second = L"13213<>";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*s %*s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 15, second),
                   sprintf(str2, format, 10, first, 15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*s %*s";
  char first[8] = " xsgh,";
  char second[16] = "?zfgsgf";
  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, -15, second),
                   sprintf(str2, format, -10, first, -15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_11) {
  char str1[400];
  char str2[400];
  const char *format = "%s %s";
  char *first = "\n";
  char *second = "\t";
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifier d

START_TEST(sprintf_spec_d_1) {
  char str1[400];
  char str2[400];
  const char *format = " %d %d %d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+d %+d %+d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_3) {
  char str1[400];
  char str2[400];
  const char *format = "% d % d % d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-d %-d %-d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#d %#d %#d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0d %0d %0d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2d %2d %3d";

  int first = 2565465;
  int third = -35243543;
  int fifth = -454356;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2d %.13d %.98d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*d %d %d";

  int first = 2552;
  int second = -1352;
  int third = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, second, third),
                   sprintf(str2, format, 10, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_10) {
  char str1[400];
  char str2[400];
  const char *format = "%+-*d %0#d % -*d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_11) {
  char str1[400];
  char str2[400];
  const char *format = " %d %d %d";

  int first = 02552;
  int third = -01352;
  int fifth = 0032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_12) {
  char str1[400];
  char str2[400];
  const char *format = " %d %d %d";

  char *first = "2552";
  char *third = "-1352";
  char *fifth = "-325";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*d %d %.*d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*d %d %.*d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_15) {
  char str1[400];
  char str2[400];
  const char *format = " %ld %ld %ld";

  long int first = 12345067891352;
  long int third = -98654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_16) {
  char str1[400];
  char str2[400];
  const char *format = " %6ld %0ld %-15ld";

  long int first = 123450891352;
  long int third = -987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_17) {
  char str1[400];
  char str2[400];
  const char *format = " %hd %hd %hd";

  short int first = 12354;
  short int third = -352;
  short int fifth = -32768;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_18) {
  char str1[400];
  char str2[400];
  const char *format = " %hd %hd %hd";

  short int first = 14435;
  short int third = -3352;
  short int fifth = -3585;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_19) {
  char str1[400];
  char str2[400];
  const char *format = "% #+d % #+d % #+d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifier i

START_TEST(sprintf_spec_i_1) {
  char str1[400];
  char str2[400];
  const char *format = " %i %i %i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+i %+i %+i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_3) {
  char str1[400];
  char str2[400];
  const char *format = "% i % i % i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-i %-i %-i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#i %#i %#i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0i %0i %0i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2i %2i %3i";

  int first = 2565465;
  int third = -35243543;
  int fifth = -454356;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2i %.13i %.98i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*i %i %i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, fifth),
                   sprintf(str2, format, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*i %i %*i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_11) {
  char str1[400];
  char str2[400];
  const char *format = "%i %i %i";

  int first = 02552;
  int third = -01352;
  int fifth = 0032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_12) {
  char str1[400];
  char str2[400];
  const char *format = "%i %i %i";

  char *first = "25";
  char *third = "-13";
  char *fifth = "-325";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*i %i %.*i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*i %i %.*i";

  int first = 2552;

  int third = -1352;

  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_15) {
  char str1[400];
  char str2[400];
  const char *format = " %li %li %li";

  long int first = 12345061352;
  long int third = -98765654165;
  long int fifth = -655467463654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_16) {
  char str1[400];
  char str2[400];
  const char *format = " %6li %0li %-15li";

  long int first = 12345067891352;
  long int third = -987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_17) {
  char str1[400];
  char str2[400];
  const char *format = "%hi %hi %hi";

  short int first = 12354;
  short int third = -352;
  short int fifth = -32768;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_18) {
  char str1[400];
  char str2[400];
  const char *format = "%hi %hi %hi";

  short int first = 12435;
  short int third = 0;
  short int fifth = -32585;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_19) {
  char str1[400];
  char str2[400];
  const char *format = "% #+i % #+i % #+i";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifier u

START_TEST(sprintf_spec_u_1) {
  char str1[400];
  char str2[400];
  const char *format = "%u %u %u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+u %+u %+u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_3) {
  char str1[400];
  char str2[400];
  const char *format = "% u % u % u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-u %-u %-u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#u %#u %#u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0u %0u %0u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2u %2u %3u";

  int first = 2565465;
  int third = 35243543;
  int fifth = -454356;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2u %.13u %.98u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*u %u %u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, fifth),
                   sprintf(str2, format, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*u %u %*u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_11) {
  char str1[400];
  char str2[400];
  const char *format = "%u %u %u";

  int first = 02552;
  int third = 01352;
  int fifth = 0032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_12) {
  char str1[400];
  char str2[400];
  const char *format = "% #.10u % 0u % -.3u";

  char *first = "2552";
  char *third = "1352";
  char *fifth = "-325";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*u %u %.*u";

  int first = 2552;
  int third = 1352552;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*u %u %.*u";

  int first = 252552;
  int third = 1523;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lu %lu %lu";

  long int first = 123450678952;
  long int third = 987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lu %0lu %-15lu";

  long int first = 123450678952;
  long int third = 987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_17) {
  char str1[400];
  char str2[400];
  const char *format = " %hu %hu %hu";

  short int first = 12354;
  short int third = 352;
  short int fifth = -32768;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_18) {
  char str1[400];
  char str2[400];
  const char *format = " %hu %hu %hu";

  short int first = 12435;
  short int third = 35452;
  short int fifth = -3585;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_19) {
  char str1[400];
  char str2[400];
  const char *format = "% #+u % #+u % #+u";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifier o

START_TEST(sprintf_spec_o_1) {
  char str1[400];
  char str2[400];
  const char *format = "%o %o %o";

  int first = 02552;
  int third = 01352;
  int fifth = -032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+o %+o %+o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325152;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_3) {
  char str1[400];
  char str2[400];
  const char *format = "% o % o % o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-o %-o %-o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#o %#o %#o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0o %0o %0o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2.o %2.0o %3.13o";

  int first = 02565465;
  int third = 035243543;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2o %.13o %.98o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*o %o %o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, fifth),
                   sprintf(str2, format, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*o %o %*o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_11) {
  char str1[400];
  char str2[400];
  const char *format = "% 0o % #-o % +o";

  int first = 2552;
  int third = 1352;
  int fifth = 325852;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_12) {
  char str1[400];
  char str2[400];
  const char *format = "%2o %010o %o";

  char *first = "02552";
  char *third = "01352";
  char *fifth = "-0325052";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*o %o %.*o";

  int first = 02552;
  int third = 01352552;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*o %o %.*o";

  int first = 0252552;
  int third = 01523;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lo %lo %lo";

  long int first = 01234506752;
  long int third = 07654302165;
  long int fifth = -065746553654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lo %0lo %-15lo";

  long int first = 01234506752;
  long int third = 07654302165;
  long int fifth = -065746353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_17) {
  char str1[400];
  char str2[400];
  const char *format = "%ho %ho %ho";

  short int first = 012354;
  short int third = 0352;
  short int fifth = -035052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_18) {
  char str1[400];
  char str2[400];
  const char *format = "%ho %ho %ho";

  short int first = 012435;
  short int third = 03452;
  short int fifth = -03505;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifiers e, E

START_TEST(sprintf_spec_e_1) {
  char str1[400];
  char str2[400];
  const char *format = "%e %e %e\n%E %E %E";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_2) {
  char str1[400];
  char str2[400];
  const char *format = "%e %e %e\n%E %E %E";

  double first = 542135644658;
  double second = -56465874654654;
  double third = 0;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_3) {
  char str1[400];
  char str2[400];
  const char *format = "%-15e %-10e %-5e\n%-15E %-10E %-5E";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_4) {
  char str1[400];
  char str2[400];
  const char *format = "%+15.3e %+10.10e %+5.0e\n%+15.3E %+10.10E %+5.0E";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_5) {
  char str1[400];
  char str2[400];
  const char *format = "% .8e % .6e % .2e\n% .8E % .6E % .2E";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_6) {
  char str1[400];
  char str2[400];
  const char *format = "%#15.8e % #.6e %#46.17e\n%#15.8E % #.6E %#46.17E";

  double first = 54564354.232549687968546;
  double second = -6868456653.0;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_7) {
  char str1[400];
  char str2[400];
  const char *format = "%0.8e   %0.6e    %0.2e\n%0.8E   %0.6E   %0.2E";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.*e\t   %.*e\t    %.*e\n%.*E\t   %.*E\t    %.*E";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 0, second, -3, third,
                               10, first, 0, second, -3, third),
                   sprintf(str2, format, 10, first, 0, second, -3, third, 10,
                           first, 0, second, -3, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*.3e %*.2e  %*.2e\n%*.3E %*.2E  %*.2E";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 0, second, -3, third,
                               10, first, 0, second, -3, third),
                   sprintf(str2, format, 10, first, 0, second, -3, third, 10,
                           first, 0, second, -3, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*.3e, %.2e,  %.2e\n%*.3E, %.2E,  %.2E";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, second, third, -10,
                               first, second, third),
                   sprintf(str2, format, -10, first, second, third, -10, first,
                           second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_11) {
  char str1[400];
  char str2[400];
  const char *format = "%3e %2e %2e\n%3E %2E %2E";

  double first = 00054564354.232549687968546;
  double second = -00056465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_12) {
  char str1[400];
  char str2[400];
  const char *format = "%Le %Le %Le\n%LE %LE %LE";

  long double first = 5434563564354.232549687968546;
  long double second = -686836734653.1565456;
  long double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_13) {
  char str1[400];
  char str2[400];
  const char *format = "%he %he %he\n%hE %hE %hE";

  double first = 542135644658.232549687968546;
  double second = -683.1565456;
  double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_14) {
  char str1[400];
  char str2[400];
  const char *format = "%Le %Le %Le\n%LE %LE %LE";

  long double first = 542135644658.232549687968546;
  long double second = -683.1565456;
  long double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_15) {
  char str1[400];
  char str2[400];
  const char *format = "%Le %Le %Le\n%LE %LE %LE";

  long double first = 54345635465564354.232549687968546;
  long double second = -68683673454654653.1565456;
  long double third = 5465465654654650.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifiers f, g, G

START_TEST(sprintf_spec_f_g_1) {
  char str1[400];
  char str2[400];
  const char *format = "%f %f %f\n%g %g %g";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_2) {
  char str1[400];
  char str2[400];
  const char *format = "%f %f %f\n%G %G %G";

  double first = 542135644658;
  double second = -56465874654654;
  double third = 0;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_3) {
  char str1[400];
  char str2[400];
  const char *format = "%-15f %-10f %-5f\n%-15G %-10G %-5G";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_4) {
  char str1[400];
  char str2[400];
  const char *format = "%+15.3f %+10.10f %+5.0f\n%+15.3g %+10.10g %+5.0g";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_5) {
  char str1[400];
  char str2[400];
  const char *format = "% .8f % .6f % .2f\n% .8G % .6G % .2G";

  double first = 542135644658.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_6) {
  char str1[200];
  char str2[200];
  const char *format = "%#15.8f % #.6f %#16.17f\n%#15.8g % #.6g %#16.17g";

  double first = 54564354.232549687968546;
  double second = -6868456653.0;
  double third = 0.0000000000000123;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_7) {
  char str1[400];
  char str2[400];
  const char *format = "%0.8f   %0.6f    %0.2f\n%0.8G   %0.6G   %0.2G";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.*f\t   %.*f\t    %.*f\n%.*g\t   %.*g\t    %.*g";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 0, second, -3, third,
                               10, first, 0, second, -3, third),
                   sprintf(str2, format, 10, first, 0, second, -3, third, 10,
                           first, 0, second, -3, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*.6f %*.2f  %*.9f\n%*.3G %*.2G  %*.2G";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 0, second, -3, third,
                               10, first, 0, second, -3, third),
                   sprintf(str2, format, 10, first, 0, second, -3, third, 10,
                           first, 0, second, -3, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*.6f, %.2f,  %.9f\n%*.3g, %.2g,  %.2g";

  double first = 54564354.232549687968546;
  double second = -56465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, second, third, -10,
                               first, second, third),
                   sprintf(str2, format, -10, first, second, third, -10, first,
                           second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_11) {
  char str1[400];
  char str2[400];
  const char *format = "%13.0012f %25.16f %0.f\n%13.0012G %25.16G %0.G";

  double first = 00054564354.232549687968546;
  double second = -00056465874654654.1565456;
  double third = 0.57894651321;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_12) {
  char str1[400];
  char str2[400];
  const char *format = "%Lf %Lf %Lf\n%Lg %LG %Lg";

  long double first = 5434563564354.232549687968546;
  long double second = -686836734653.1565456;
  long double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_13) {
  char str1[400];
  char str2[400];
  const char *format = "%hf %hf %hf\n%hg %hG %hg";

  double first = 542135644658.232549687968546;
  double second = -683.1565456;
  double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_14) {
  char str1[400];
  char str2[400];
  const char *format = "%lf %lf %lf\n%lG %lg %lG";

  double first = 54456448546354.232549687968546;
  double second = -683.1565456;
  double third = 0.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_15) {
  char str1[400];
  char str2[400];
  const char *format = "%Lf %Lf %Lf\n%LG %Lg %Lg";

  long double first = 54345635465564354.232549687968546;
  long double second = -68683673454654653.1565456;
  long double third = 5465465654654650.5746583477685768;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_g_16) {
  char str1[400];
  char str2[400];
  const char *format = "%f %f %f";

  double first = 1.0 / 0.0;
  double second = -1.0 / 0.0;
  double third = -1.0 / 0.0;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, second, third, first, second, third),
      sprintf(str2, format, first, second, third, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifiers x and X

START_TEST(sprintf_spec_x_1) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+x %+x %+x\n%+X %+X %+X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_3) {
  char str1[400];
  char str2[400];
  const char *format = "% x % x % x\n% X % X % X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-x %-x %-x\n%-X %-X %-X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#x %#x %#x\n%#X %#X %#X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0x %0x %0x\n%0X %0X %0X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_7) {
  char str1[400];
  char str2[400];
  const char *format = "%4x %5x %3x\n%4X %5X %3X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2x %.13x %.98x\n%.2X %.13X %.98X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*x %x %x\n%*X %X %X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 10, first, third, fifth, 10, first, third,
                  fifth),
      sprintf(str2, format, 10, first, third, fifth, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*x %x %*x\n%*X %X %*X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth, -10,
                               first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth, -10,
                           first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_11) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  int first = 0x0005c4353b;
  int third = 0x0001111111;
  int fifth = 000325052;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_12) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  char *first = "0x5c4353b";
  char *third = "0x11111111";
  char *fifth = "-3435435";

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*x %x %.*x\n%.*X %X %.*X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth, 10,
                               first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth, 10, first,
                           third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*x %x %.*x\n%.*X %X %.*X";

  int first = 0x5c4353b;
  int third = 1523;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth, -10,
                               first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth, -10,
                           first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lx %lx %lx\n%lX %lX %lX";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lx %0lx %-15lx\n%6lX %0lX %-15lX";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_17) {
  char str1[400];
  char str2[400];
  const char *format = "%hx %hx %hx\n%hX %hX %hX";

  short int first = 0x53b;
  short int third = 0x519c;
  short int fifth = -6435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_18) {
  char str1[400];
  char str2[400];
  const char *format = "%6hx %2hx %1hx\n%6hX %2hX %1hX";

  short int first = 0x5ab2;
  short int third = 0x1621;
  short int fifth = -3615;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifier p

START_TEST(sprintf_spec_p_1) {
  char str1[400];
  char str2[400];
  const char *format = "%p %p %p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+p %+p %+p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_3) {
  char str1[400];
  char str2[400];
  const char *format = "% p % p % p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-p %-p %-p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#p %#p %#p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0p %13p %-15p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_7) {
  char str1[400];
  char str2[400];
  const char *format = "%4p %5p %3p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2p %.13p %.p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*p %p %p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, &first, &third, &fifth),
                   sprintf(str2, format, 10, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_10) {
  char str1[400];
  char str2[400];
  const char *format = "%*p %p %*p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, &first, &third, 0, &fifth),
                   sprintf(str2, format, -10, &first, &third, 0, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_11) {
  char str1[400];
  char str2[400];
  const char *format = "%p %p %p";

  int first = 0x0005c4353b;
  int third = 0x000111111;
  int fifth = 000325752;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_12) {
  char str1[400];
  char str2[400];
  const char *format = "%p %p %p";

  char *first = "0x5c4353b";
  char *third = "0x11111111";
  char *fifth = "-3435435";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*p %p %.*p";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, &first, &third, 5, &fifth),
                   sprintf(str2, format, 10, &first, &third, 5, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_14) {
  char str1[400];
  char str2[400];
  const char *format = "%.*p %p %.*p";

  int first = 0x5c4353b;
  int third = 1523;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, &first, &third, 0, &fifth),
                   sprintf(str2, format, -10, &first, &third, 0, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lp %lp %lx\0%lp %lp %lX";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lp %0lp %-15lp";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_17) {
  char str1[400];
  char str2[400];
  const char *format = "%hp %hp %hp";

  short int first = 0x53b;
  short int third = 0x519c;
  short int fifth = -3435;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_18) {
  char str1[400];
  char str2[400];
  const char *format = "%6hp %2hp %1hp";

  short int first = 0x5ab2;
  short int third = 0x1111;
  short int fifth = -3615;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &third, &fifth),
                   sprintf(str2, format, &first, &third, &fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// specifiers n and %

START_TEST(sprintf_spec_n_per_1) {
  char str1[400];
  char str2[400];
  const char *format = "%nblablablablabla%%%n";

  int first = 0;
  int second = 0;
  int third = 0;
  int fourth = 0;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &second),
                   sprintf(str2, format, &third, &fourth));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(first, third);
  ck_assert_int_eq(second, fourth);
}
END_TEST

START_TEST(sprintf_spec_n_per_2) {
  char str1[400];
  char str2[400];
  const char *format = "%n%%%%%%%%%%%n";

  int first = 0;
  int second = 0;
  int third = 0;
  int fourth = 0;

  ck_assert_int_eq(s21_sprintf(str1, format, &first, &second),
                   sprintf(str2, format, &third, &fourth));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(first, third);
  ck_assert_int_eq(second, fourth);
}
END_TEST

Suite *spec_c_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("SPECIFIER C");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_c_1);
  tcase_add_test(tc_core, sprintf_spec_c_2);
  tcase_add_test(tc_core, sprintf_spec_c_3);
  tcase_add_test(tc_core, sprintf_spec_c_4);
  tcase_add_test(tc_core, sprintf_spec_c_5);
  tcase_add_test(tc_core, sprintf_spec_c_6);
  tcase_add_test(tc_core, sprintf_spec_c_7);
  tcase_add_test(tc_core, sprintf_spec_c_9);
  tcase_add_test(tc_core, sprintf_spec_c_10);
  tcase_add_test(tc_core, sprintf_spec_c_11);
  tcase_add_test(tc_core, sprintf_spec_c_12);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *spec_s_suite(void) {
  Suite *s2;
  TCase *tc_core;
  s2 = suite_create("SPECIFIER S");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_s_1);
  tcase_add_test(tc_core, sprintf_spec_s_2);
  tcase_add_test(tc_core, sprintf_spec_s_3);
  tcase_add_test(tc_core, sprintf_spec_s_4);
  tcase_add_test(tc_core, sprintf_spec_s_5);
  tcase_add_test(tc_core, sprintf_spec_s_6);
  tcase_add_test(tc_core, sprintf_spec_s_7);
  tcase_add_test(tc_core, sprintf_spec_s_9);
  tcase_add_test(tc_core, sprintf_spec_s_10);
  tcase_add_test(tc_core, sprintf_spec_s_11);
  suite_add_tcase(s2, tc_core);
  return s2;
}

Suite *spec_d_suite(void) {
  Suite *s3;
  TCase *tc_core;
  s3 = suite_create("SPECIFIER D");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_d_1);
  tcase_add_test(tc_core, sprintf_spec_d_2);
  tcase_add_test(tc_core, sprintf_spec_d_3);
  tcase_add_test(tc_core, sprintf_spec_d_4);
  tcase_add_test(tc_core, sprintf_spec_d_5);
  tcase_add_test(tc_core, sprintf_spec_d_6);
  tcase_add_test(tc_core, sprintf_spec_d_7);
  tcase_add_test(tc_core, sprintf_spec_d_8);
  tcase_add_test(tc_core, sprintf_spec_d_9);
  tcase_add_test(tc_core, sprintf_spec_d_10);
  tcase_add_test(tc_core, sprintf_spec_d_11);
  tcase_add_test(tc_core, sprintf_spec_d_12);
  tcase_add_test(tc_core, sprintf_spec_d_13);
  tcase_add_test(tc_core, sprintf_spec_d_14);
  tcase_add_test(tc_core, sprintf_spec_d_15);
  tcase_add_test(tc_core, sprintf_spec_d_16);
  tcase_add_test(tc_core, sprintf_spec_d_17);
  tcase_add_test(tc_core, sprintf_spec_d_18);
  tcase_add_test(tc_core, sprintf_spec_d_19);
  suite_add_tcase(s3, tc_core);
  return s3;
}

Suite *spec_i_suite(void) {
  Suite *s4;
  TCase *tc_core;
  s4 = suite_create("SPECIFIER I");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_i_1);
  tcase_add_test(tc_core, sprintf_spec_i_2);
  tcase_add_test(tc_core, sprintf_spec_i_3);
  tcase_add_test(tc_core, sprintf_spec_i_4);
  tcase_add_test(tc_core, sprintf_spec_i_5);
  tcase_add_test(tc_core, sprintf_spec_i_6);
  tcase_add_test(tc_core, sprintf_spec_i_7);
  tcase_add_test(tc_core, sprintf_spec_i_8);
  tcase_add_test(tc_core, sprintf_spec_i_9);
  tcase_add_test(tc_core, sprintf_spec_i_10);
  tcase_add_test(tc_core, sprintf_spec_i_11);
  tcase_add_test(tc_core, sprintf_spec_i_12);
  tcase_add_test(tc_core, sprintf_spec_i_13);
  tcase_add_test(tc_core, sprintf_spec_i_14);
  tcase_add_test(tc_core, sprintf_spec_i_15);
  tcase_add_test(tc_core, sprintf_spec_i_16);
  tcase_add_test(tc_core, sprintf_spec_i_17);
  tcase_add_test(tc_core, sprintf_spec_i_18);
  tcase_add_test(tc_core, sprintf_spec_i_19);
  suite_add_tcase(s4, tc_core);
  return s4;
}

Suite *spec_u_suite(void) {
  Suite *s5;
  TCase *tc_core;
  s5 = suite_create("SPECIFIER U");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_u_1);
  tcase_add_test(tc_core, sprintf_spec_u_2);
  tcase_add_test(tc_core, sprintf_spec_u_3);
  tcase_add_test(tc_core, sprintf_spec_u_4);
  tcase_add_test(tc_core, sprintf_spec_u_5);
  tcase_add_test(tc_core, sprintf_spec_u_6);
  tcase_add_test(tc_core, sprintf_spec_u_7);
  tcase_add_test(tc_core, sprintf_spec_u_8);
  tcase_add_test(tc_core, sprintf_spec_u_9);
  tcase_add_test(tc_core, sprintf_spec_u_10);
  tcase_add_test(tc_core, sprintf_spec_u_11);
  tcase_add_test(tc_core, sprintf_spec_u_12);
  tcase_add_test(tc_core, sprintf_spec_u_13);
  tcase_add_test(tc_core, sprintf_spec_u_14);
  tcase_add_test(tc_core, sprintf_spec_u_15);
  tcase_add_test(tc_core, sprintf_spec_u_16);
  tcase_add_test(tc_core, sprintf_spec_u_17);
  tcase_add_test(tc_core, sprintf_spec_u_18);
  tcase_add_test(tc_core, sprintf_spec_u_19);
  suite_add_tcase(s5, tc_core);
  return s5;
}

Suite *spec_e_suite(void) {
  Suite *s6;
  TCase *tc_core;
  s6 = suite_create("SPECIFIERs e, E");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_e_1);
  tcase_add_test(tc_core, sprintf_spec_e_2);
  tcase_add_test(tc_core, sprintf_spec_e_3);
  tcase_add_test(tc_core, sprintf_spec_e_4);
  tcase_add_test(tc_core, sprintf_spec_e_5);
  tcase_add_test(tc_core, sprintf_spec_e_6);
  tcase_add_test(tc_core, sprintf_spec_e_7);
  tcase_add_test(tc_core, sprintf_spec_e_8);
  tcase_add_test(tc_core, sprintf_spec_e_9);
  tcase_add_test(tc_core, sprintf_spec_e_10);
  tcase_add_test(tc_core, sprintf_spec_e_11);
  tcase_add_test(tc_core, sprintf_spec_e_12);
  tcase_add_test(tc_core, sprintf_spec_e_13);
  tcase_add_test(tc_core, sprintf_spec_e_14);
  tcase_add_test(tc_core, sprintf_spec_e_15);
  suite_add_tcase(s6, tc_core);
  return s6;
}

Suite *spec_f_g_suite(void) {
  Suite *s7;
  TCase *tc_core;
  s7 = suite_create("SPECIFIERS f, g, G");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_f_g_1);
  tcase_add_test(tc_core, sprintf_spec_f_g_2);
  tcase_add_test(tc_core, sprintf_spec_f_g_3);
  tcase_add_test(tc_core, sprintf_spec_f_g_4);
  tcase_add_test(tc_core, sprintf_spec_f_g_5);
  tcase_add_test(tc_core, sprintf_spec_f_g_6);
  tcase_add_test(tc_core, sprintf_spec_f_g_7);
  tcase_add_test(tc_core, sprintf_spec_f_g_8);
  tcase_add_test(tc_core, sprintf_spec_f_g_9);
  tcase_add_test(tc_core, sprintf_spec_f_g_10);
  tcase_add_test(tc_core, sprintf_spec_f_g_11);
  tcase_add_test(tc_core, sprintf_spec_f_g_12);
  tcase_add_test(tc_core, sprintf_spec_f_g_13);
  tcase_add_test(tc_core, sprintf_spec_f_g_14);
  tcase_add_test(tc_core, sprintf_spec_f_g_15);
  tcase_add_test(tc_core, sprintf_spec_f_g_16);
  suite_add_tcase(s7, tc_core);
  return s7;
}

Suite *spec_o_suite(void) {
  Suite *s8;
  TCase *tc_core;
  s8 = suite_create("SPECIFIER O");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_o_1);
  tcase_add_test(tc_core, sprintf_spec_o_2);
  tcase_add_test(tc_core, sprintf_spec_o_3);
  tcase_add_test(tc_core, sprintf_spec_o_4);
  tcase_add_test(tc_core, sprintf_spec_o_5);
  tcase_add_test(tc_core, sprintf_spec_o_6);
  tcase_add_test(tc_core, sprintf_spec_o_7);
  tcase_add_test(tc_core, sprintf_spec_o_8);
  tcase_add_test(tc_core, sprintf_spec_o_9);
  tcase_add_test(tc_core, sprintf_spec_o_10);
  tcase_add_test(tc_core, sprintf_spec_o_11);
  tcase_add_test(tc_core, sprintf_spec_o_12);
  tcase_add_test(tc_core, sprintf_spec_o_13);
  tcase_add_test(tc_core, sprintf_spec_o_14);
  tcase_add_test(tc_core, sprintf_spec_o_15);
  tcase_add_test(tc_core, sprintf_spec_o_16);
  tcase_add_test(tc_core, sprintf_spec_o_17);
  tcase_add_test(tc_core, sprintf_spec_o_18);
  suite_add_tcase(s8, tc_core);
  return s8;
}

Suite *spec_x_suite(void) {
  Suite *s9;
  TCase *tc_core;
  s9 = suite_create("SPECIFIER X");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_x_1);
  tcase_add_test(tc_core, sprintf_spec_x_2);
  tcase_add_test(tc_core, sprintf_spec_x_3);
  tcase_add_test(tc_core, sprintf_spec_x_4);
  tcase_add_test(tc_core, sprintf_spec_x_5);
  tcase_add_test(tc_core, sprintf_spec_x_6);
  tcase_add_test(tc_core, sprintf_spec_x_7);
  tcase_add_test(tc_core, sprintf_spec_x_8);
  tcase_add_test(tc_core, sprintf_spec_x_9);
  tcase_add_test(tc_core, sprintf_spec_x_10);
  tcase_add_test(tc_core, sprintf_spec_x_11);
  tcase_add_test(tc_core, sprintf_spec_x_12);
  tcase_add_test(tc_core, sprintf_spec_x_13);
  tcase_add_test(tc_core, sprintf_spec_x_14);
  tcase_add_test(tc_core, sprintf_spec_x_15);
  tcase_add_test(tc_core, sprintf_spec_x_16);
  tcase_add_test(tc_core, sprintf_spec_x_17);
  tcase_add_test(tc_core, sprintf_spec_x_18);
  suite_add_tcase(s9, tc_core);
  return s9;
}

Suite *spec_p_suite(void) {
  Suite *s10;
  TCase *tc_core;
  s10 = suite_create("SPECIFIER P");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_p_1);
  tcase_add_test(tc_core, sprintf_spec_p_2);
  tcase_add_test(tc_core, sprintf_spec_p_3);
  tcase_add_test(tc_core, sprintf_spec_p_4);
  tcase_add_test(tc_core, sprintf_spec_p_5);
  tcase_add_test(tc_core, sprintf_spec_p_6);
  tcase_add_test(tc_core, sprintf_spec_p_7);
  tcase_add_test(tc_core, sprintf_spec_p_8);
  tcase_add_test(tc_core, sprintf_spec_p_9);
  tcase_add_test(tc_core, sprintf_spec_p_10);
  tcase_add_test(tc_core, sprintf_spec_p_11);
  tcase_add_test(tc_core, sprintf_spec_p_12);
  tcase_add_test(tc_core, sprintf_spec_p_13);
  tcase_add_test(tc_core, sprintf_spec_p_14);
  tcase_add_test(tc_core, sprintf_spec_p_15);
  tcase_add_test(tc_core, sprintf_spec_p_16);
  tcase_add_test(tc_core, sprintf_spec_p_17);
  tcase_add_test(tc_core, sprintf_spec_p_18);
  suite_add_tcase(s10, tc_core);
  return s10;
}

Suite *spec_n_per_suite(void) {
  Suite *s10;
  TCase *tc_core;
  s10 = suite_create("SPECIFIER N AND PERCENT");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_n_per_1);
  tcase_add_test(tc_core, sprintf_spec_n_per_2);
  suite_add_tcase(s10, tc_core);
  return s10;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(spec_c_suite(), &fail);
  case_test(spec_s_suite(), &fail);
  case_test(spec_d_suite(), &fail);
  case_test(spec_i_suite(), &fail);
  case_test(spec_u_suite(), &fail);
  case_test(spec_e_suite(), &fail);
  case_test(spec_f_g_suite(), &fail);
  case_test(spec_x_suite(), &fail);
  case_test(spec_o_suite(), &fail);
  case_test(spec_p_suite(), &fail);
  case_test(spec_n_per_suite(), &fail);
  return fail;
}