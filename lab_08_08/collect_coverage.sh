#!/bin/bash

if [ "$1" = "-v" ]; then
  VERBOSE=true
else
  VERBOSE=false
fi

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

make clean
make mode=coverage
if [ "$VERBOSE" = true ]; then
    echo "Check tests"
    ./func_tests/scripts/func_tests.sh -v
else
    ./func_tests/scripts/func_tests.sh
fi
gcov /src/*.c
