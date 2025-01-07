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

app.exe: out/main.o out/process.o
	$(CC) -o app.exe out/main.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/process.h inc/errors.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c

out/process.o: src/process.c inc/process.h inc/errors.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

unit: unit_tests.exe
	./unit_tests.exe

# -lsubunit -lpthread -lrt
unit_tests.exe: out/s_check.o out/check_main.o out/process.o out/funcs_for_units.o
	$(CC) -o unit_tests.exe out/s_check.o out/check_main.o out/process.o out/funcs_for_units.o -lcheck -lm

out/check_main.o: unit_tests/check_main.c inc/process.h
	$(CC) $(CFLAGS) -o out/check_main.o -c unit_tests/check_main.c

out/s_check.o: unit_tests/s_check.c inc/funcs_for_units.h
	$(CC) $(CFLAGS) -o out/s_check.o -c unit_tests/s_check.c

out/funcs_for_units.o: unit_tests/funcs_for_units.c inc/funcs_for_units.h inc/errors.h inc/process.h
	$(CC) $(CFLAGS) -o out/funcs_for_units.o -c unit_tests/funcs_for_units.c

.PHONY : clean unit

clean:
	$(RM) out/*
	$(RM) ./*.exe
	$(RM) ./*.txt
	$(RM) func_tests/scripts/*.txtща
