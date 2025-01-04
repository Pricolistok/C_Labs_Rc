CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wvla -Wfloat-conversion -Wfloat-equal -Iinc
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

all: app.exe

app.exe: out/main.o out/process.o out/input_output.o
	$(CC) -o app.exe out/main.o out/input_output.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/input_output.h inc/process.h inc/errors.h inc/struct.h inc/errors.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c

out/process.o: src/process.c inc/process.h inc/errors.h inc/struct.h inc/input_output.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

out/input_output.o: src/input_output.c inc/input_output.h inc/errors.h inc/struct.h inc/consts.h
	$(CC) $(CFLAGS) -o out/input_output.o -c src/input_output.c


#func_tests: ./func_tests/scripts/func_tsts.sh

.PHONY : clean unit func_tests

clean:
	$(RM) out/*
	$(RM) ./*.exe
	$(RM) ./*.txt
	$(RM) func_tests/scripts/*.txt
