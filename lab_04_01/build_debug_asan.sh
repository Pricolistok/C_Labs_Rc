#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

clang -fsanitize=address -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g -c main.c -o main.o
clang -fsanitize=address -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g -c functions.c -o functions.o


clang main.o functions.o -o app.exe -lm -fsanitize=address
