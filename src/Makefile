OS = $(shell uname)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_POSIX_C_SOURCE=200809L
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

LIBS = -lcheck -lm
ifeq ($(OS), Linux)
	LIBS += -lsubunit
endif

VALG = valgrind --tool=memcheck --leak-check=yes ./s21_tests
CPPCH = cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidFunctionArg --force

SRC_FILES = s21_str.c s21_mem.c s21_sprintf.c s21_sprintf_utils.c s21_part5.c
OBJ_FILES = $(SRC_FILES:.c=.o)

HEAD_FILE = s21_string.h
LIBRARY = $(HEAD_FILE:.h=.a)

EXECUTABLE = s21_tests
GCOV_EXECUTABLE = s21_gcov_tests

TEST_SRC = tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

SRC_CL = ../materials/linters/.clang-format

all: $(LIBRARY)

# building static lib
$(LIBRARY): $(OBJ_FILES)
	ar rcs $@ $^
	
# building objects for static lib
%.o: %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(TEST_SRC) $(LIBRARY)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(EXECUTABLE) $(LIBRARY) $(LIBS)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

# building file for gcov report
$(GCOV_EXECUTABLE): $(SRC_FILES) $(TEST_SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $^ -o $@ $(LIBS)

# building gcov report
gcov_report: $(GCOV_EXECUTABLE)
	./$(GCOV_EXECUTABLE)
	gcov *.gcda
	gcovr -r . --exclude tests.c --html --html-details -o coverage_report.html
	rm -f *.gc* $(GCOV_EXECUTABLE)

valgrind: $(EXECUTABLE)
	$(VALG) $(EXECUTABLE)

cpp_check:
	$(CPPCH) $(SRC_FILES) $(HEAD_FILE)

clang_all:
	cp $(SRC_CL) .clang-format
	clang-format -i *.c
	clang-format -i *.h
	rm -f .clang-format

clean:
	rm -f $(EXECUTABLE) $(GCOV_EXECUTABLE) $(LIBRARY) *.gc* *.html *.css *.o

rebuild: clean all

.PHONY: all test clean gcov_report valgrind cpp_check clang_all
