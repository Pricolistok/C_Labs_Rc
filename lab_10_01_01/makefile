CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -Iinc

EXEFLAGS := 

create := $(shell mkdir -p out)

ifeq ($(mode), release)
  CFLAGS += -O2
endif

ifeq ($(mode), debug)
  CFLAGS += -g -O0
endif

ifeq ($(mode), memory)
  CFLAGS += -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -O0
  EXEFLAGS += -fsanitize=memory -pie
  CC := clang
endif

ifeq ($(mode), adress)
  CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g -O0
  EXEFLAGS += -fsanitize=address
  CC := clang
endif

ifeq ($(mode), ubsan)
  CFLAGS += -fsanitize=undefined -fno-omit-frame-pointer -g -O0
  EXEFLAGS += -fsanitize=undefined
  CC := clang
endif

ifeq ($(mode), coverage)
  CFLAGS += --coverage
  EXEFLAGS += --coverage
endif

all : app.exe unit_tests.exe

app.exe: out/main.o out/input_output.o out/process.o
	$(CC) -o app.exe out/main.o out/input_output.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/input_output.h inc/process.h inc/errors.h inc/struct.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c 

out/input_output.o: src/input_output.c inc/errors.h inc/input_output.h inc/struct.h
	$(CC) $(CFLAGS) -o out/input_output.o -c src/input_output.c

out/process.o: src/process.c inc/errors.h inc/process.h inc/struct.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

# -lsubunit -lpthread -lrt
unit_tests.exe: out/pop_duplicates_test.o out/check_main.o out/process.o out/funcs_for_units.o out/input_output.o out/pop_front_test.o out/pop_end_test.o out/sort_test.o
	$(CC) -o unit_tests.exe out/pop_duplicates_test.o out/check_main.o out/process.o out/input_output.o out/funcs_for_units.o out/pop_front_test.o out/pop_end_test.o out/sort_test.o -lcheck -lm -lsubunit -lpthread -lrt

out/check_main.o: unit_tests/check_main.c inc/process.h
	$(CC) $(CFLAGS) -o out/check_main.o -c unit_tests/check_main.c

out/pop_duplicates_test.o: unit_tests/pop_duplicates_test.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/pop_duplicates_test.o -c unit_tests/pop_duplicates_test.c

out/pop_front_test.o: unit_tests/pop_front_test.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/pop_front_test.o -c unit_tests/pop_front_test.c

out/pop_end_test.o: unit_tests/pop_end_test.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/pop_end_test.o -c unit_tests/pop_end_test.c

out/sort_test.o: unit_tests/sort_test.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/sort_test.o -c unit_tests/sort_test.c

out/funcs_for_units.o: unit_tests/funcs_for_units.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/funcs_for_units.o -c unit_tests/funcs_for_units.c

unit: unit_tests.exe
	./unit_tests.exe

func_tests: app.exe 
	./func_tests/scripts/func_tests.sh

.PHONY : clean unit func_tests

clean:
	$(RM) out/* 
	$(RM) ./*.exe 
	$(RM) ./*.txt 
	$(RM) func_tests/scripts/*.txt 