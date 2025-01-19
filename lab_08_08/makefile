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

all: app.exe

app.exe: out/main.o out/input_output.o out/process.o
	$(CC) -o app.exe out/main.o out/input_output.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/input_output.h inc/process.h inc/errors.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c 

out/input_output.o: src/input_output.c inc/errors.h inc/input_output.h
	$(CC) $(CFLAGS) -o out/input_output.o -c src/input_output.c

out/process.o: src/process.c inc/errors.h inc/process.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

# -lsubunit -lpthread -lrt
unit_tests.exe: out/check_rm_rows.o out/check_rm_columns.o out/check_main.o out/process.o out/funcs_for_units.o out/check_multiplication_matrix.o out/check_add_elems.o
	$(CC) -o unit_tests.exe out/funcs_for_units.o out/check_rm_rows.o out/check_rm_columns.o out/check_main.o out/process.o out/check_multiplication_matrix.o out/check_add_elems.o -lcheck -lm

out/check_rm_rows.o: unit_tests/check_rm_rows.c inc/errors.h inc/funcs_for_unit.h inc/consts_for_unit.h
	$(CC) $(CFLAGS) -o out/check_rm_rows.o -c unit_tests/check_rm_rows.c

out/check_rm_columns.o: unit_tests/check_rm_columns.c inc/errors.h  inc/funcs_for_unit.h inc/consts_for_unit.h
	$(CC) $(CFLAGS) -o out/check_rm_columns.o -c unit_tests/check_rm_columns.c

out/funcs_for_units.o: unit_tests/funcs_for_units.c inc/errors.h  inc/funcs_for_unit.h inc/consts_for_unit.h
	$(CC) $(CFLAGS) -o out/funcs_for_units.o -c unit_tests/funcs_for_units.c

out/check_multiplication_matrix.o: unit_tests/check_multiplication_matrix.c inc/errors.h  inc/funcs_for_unit.h inc/consts_for_unit.h
	$(CC) $(CFLAGS) -o out/check_multiplication_matrix.o -c unit_tests/check_multiplication_matrix.c

out/check_add_elems.o: unit_tests/check_add_elems.c inc/errors.h  inc/funcs_for_unit.h inc/consts_for_unit.h
	$(CC) $(CFLAGS) -o out/check_add_elems.o -c unit_tests/check_add_elems.c

out/check_main.o: unit_tests/check_main.c inc/errors.h 
	$(CC) $(CFLAGS) -o out/check_main.o -c unit_tests/check_main.c

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
