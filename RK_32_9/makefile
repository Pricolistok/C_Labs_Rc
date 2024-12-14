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

all : app.exe

app.exe: out/main.o out/input_output.o out/process.o
	$(CC) -o app.exe out/main.o out/input_output.o out/process.o $(EXEFLAGS) -lm

out/main.o: src/main.c inc/input_output.h inc/process.h inc/errors.h inc/struct.h
	$(CC) $(CFLAGS) -o out/main.o -c src/main.c 

out/input_output.o: src/input_output.c inc/errors.h inc/input_output.h inc/struct.h inc/process.h
	$(CC) $(CFLAGS) -o out/input_output.o -c src/input_output.c

out/process.o: src/process.c inc/errors.h inc/process.h inc/struct.h
	$(CC) $(CFLAGS) -o out/process.o -c src/process.c

.PHONY : clean

clean:
	$(RM) out/* 
	$(RM) ./*.exe