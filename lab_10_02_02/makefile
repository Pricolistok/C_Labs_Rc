CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wvla -Wfloat-equal -Iinc
EXEFLAGS :=

create := $(shell mkdir -p out)

ifeq ($(mode), release)
	CFLAGS += -O2
endif

ifeq ($(mode), debug)
	CFLGS += -g -O0
endif

ifeq ($(mode), adress)
	CFLAGS += fsanitize=adress -fno-omit-frame-pointer -g -O0
	EXEFLAGS += fsanitize=undefined
	CC := clang
endif

ifeq ($(mode), memory)
	CFLAGS += -fsanitize=undefined -fno-omit-frame-pointer -g -O0
	EXEFLAGS += -fsanitize=undefined
	CC := clang
endif

ifeq ($(mode), ubsan)
	CFLAGS += -fsanitize=undefined -fno-omit-frame-pointer -g -O0
	EXEFLAGS += -fsanitize=undefined
	CC := clang
endif

ifeq ($(mode), coverage)
	CFALGS += --coverage
	EXEFLAGS += --coverage
endif

all: app.exe unit

app.exe: out/main.o out/process.o out/input_output.o
	$(CC) -o app.exe out/main.o out/input_output.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/input_output.h inc/process.h inc/errors.h inc/struct.h inc/errors.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c

out/process.o: src/process.c inc/process.h inc/errors.h inc/struct.h inc/input_output.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

out/input_output.o: src/input_output.c inc/input_output.h inc/errors.h inc/struct.h inc/consts.h
	$(CC) $(CFLAGS) -o out/input_output.o -c src/input_output.c

unit: unit_tests.exe
	./unit_tests.exe

# -lsubunit -lpthread -lrt
unit_tests.exe: out/val_check.o out/check_main.o out/process.o out/funcs_for_units.o out/input_output.o out/sum_check.o out/dvd_check.o out/ddx_check.o
	$(CC) -o unit_tests.exe out/val_check.o out/check_main.o out/process.o out/input_output.o out/funcs_for_units.o out/sum_check.o out/dvd_check.o out/ddx_check.o -lcheck -lm -lsubunit -lpthread -lrt

out/check_main.o: unit_tests/check_main.c inc/process.h
	$(CC) $(CFLAGS) -o out/check_main.o -c unit_tests/check_main.c

out/val_check.o: unit_tests/val_check.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/val_check.o -c unit_tests/val_check.c

out/sum_check.o: unit_tests/sum_check.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/sum_check.o -c unit_tests/sum_check.c

out/ddx_check.o: unit_tests/ddx_check.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/ddx_check.o -c unit_tests/ddx_check.c

out/dvd_check.o: unit_tests/dvd_check.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/dvd_check.o -c unit_tests/dvd_check.c

out/funcs_for_units.o: unit_tests/funcs_for_units.c inc/funcs_for_units.h inc/errors.h inc/process.h inc/struct.h inc/consts.h
	$(CC) $(CFLAGS) -o out/funcs_for_units.o -c unit_tests/funcs_for_units.c

#func_tests: ./func_tests/scripts/func_tsts.sh

.PHONY : clean unit func_tests

clean:
	$(RM) out/*
	$(RM) ./*.exe
	$(RM) ./*.txt
	$(RM) func_tests/scripts/*.txt
