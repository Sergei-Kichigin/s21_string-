SRC_FILES = s21_str.c s21_mem.c s21_sprintf.c s21_sprintf_utils.c s21_part5.c
all: gcov_report
clean:
	rm -rf test test_sharp test_sscanf test_sprintf *.o *.a *.gcno *.html *.gcda
	rm -rf lcov_report lcov_report.info
clang_test:
	clang-format -n -style=Google *.c *.h */*.c

s21_string.o:
	gcc -c -Wall -Wextra -Werror -std=c11 *.c s21_sprintf.c

s21_string.a: s21_string.o
	ar rc s21_string.a *.o
	ranlib s21_string.a

test:
	gcc -Wall -Wextra -Werror -o test s21_string_test.c $(SRC_FILES) --coverage -lcheck -lm -lsubunit 
	./test

test_sharp: 
	gcc -Wall -Wextra -Werror -o test_sharp s21_sharp_tests.c $(SRC_FILES) --coverage -lcheck -lm -lsubunit 
	./test_sharp

test_sprintf:
	gcc -Wall -Wextra -Werror -o test_sprintf s21_sprintf_test.c $(SRC_FILES) --coverage -lcheck -lm -lsubunit 
	./test_sprintf


gcov_report: test test_sharp test_sprintf
	gcovr --html >> report.html

lcov_report:test test_sharp test_sprintf
	lcov -t "lcov_report" -o lcov_report.info -c -d . 
	genhtml -o lcov_report lcov_report.info
