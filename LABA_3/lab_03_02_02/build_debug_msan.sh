#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c -o main.o
clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c input_output.c -o input_output.o
clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c process.c -o process.o


clang -g -fsanitize=memory -o app.exe main.o input_output.o process.o -pie
