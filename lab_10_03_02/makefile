CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -Iinc

SRCS = associative_array_impl_2.c check_clear.c check_create.c check_destroy.c check_each.c check_find.c check_insert.c check_max.c check_min.c check_remove.c check_main.c
OBJS = $(SRCS:.c=.o)

EXEFLAGS :=


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

all: unit_tests.exe

unit_tests.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(EXEFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean unit

clean:
	$(RM) ./*.exe