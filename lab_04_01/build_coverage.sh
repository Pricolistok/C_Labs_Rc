#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit 1

gcc --std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal --coverage -c main.c -o main.o
gcc --std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal --coverage -c functions.c -o functions.o

gcc --coverage -o app.exe main.o functions.o -lm