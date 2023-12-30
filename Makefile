CC = gcc
CFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lcheck -lm -lpthread
OBJECTS = s21_string.o
SOURSES = s21_string.c
GCOVFLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(OS),Linux)
	CFLAGS+=-D LINUX
	TST_LIBS+= -lcheck_pic -lrt -lsubunit
else
	ifeq ($(OS),Darwin)
		CFLAGS+=-D MAC
	else
		CFLAGS+=-D LINUX
		TST_LIBS+= -lcheck_pic -lrt -lsubunit
	endif
endif

all: clean s21_string.a test gcov_report

s21_string.a: s21_string.o
	$(CC) -c $(SOURSES)
	ar rcs s21_string.a $(OBJECTS)

clean:
	rm -rf ./*.o ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./string_o ./*.dSYM ./s21_string_test ./CPPLINT* test

test: s21_string_test.c s21_string.a
	$(CC) $(CFLAGS) -c s21_string_test.c -o test.o
	$(CC) test.o s21_string.a $(TEST_LIBS) -o test

gcov_report: s21_string.a 
	$(CC) $(CFLAGS) --coverage s21_string_test.c s21_string.c s21_string.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html
	
check: s21_string.a
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	$(CC) s21_string_test.c s21_string.a -lcheck
	$(CC) $(CFLAGS) -c s21_string_test.c -o test.o
	$(CC) test.o s21_string.a $(TEST_LIBS) -o test
	CK_FORK=no leaks --atExit -- ./test

rebuild: clean all

