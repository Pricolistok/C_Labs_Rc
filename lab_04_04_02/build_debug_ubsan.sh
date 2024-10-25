#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

clang -fsanitize=undefined -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c main.c -o main.o
clang -fsanitize=undefined -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c input_output.c -o input_output.o
clang -fsanitize=undefined -fno-omit-frame-pointer -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c process.c -o process.o


clang main.o input_output.o process.o -o app.exe -lm -fsanitize=undefined