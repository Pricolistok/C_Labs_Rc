#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c -o main.o
clang -g -fsanitize=memory -o app.exe main.o  -pie
