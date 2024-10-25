#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c input_output.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -g3 -c process.c

gcc -o app.exe main.o input_output.o process.o -lm
