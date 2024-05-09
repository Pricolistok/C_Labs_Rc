#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c -o main.o
clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c functions.c -o functions.o


clang -g -fsanitize=memory -o app.exe main.o functions.o -pie
