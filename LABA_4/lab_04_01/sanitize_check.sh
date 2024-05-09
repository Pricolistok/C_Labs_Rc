#!/bin/bash

check_tests()
{
    if [ "$VERBOSE" = true ]; then
        echo "Check tests"
        ./func_tests/scripts/func_tests.sh -v
    else
        ./func_tests/scripts/func_tests.sh
    fi
}

if [ "$1" = "-v" ]; then
  VERBOSE=true
else
  VERBOSE=false
fi

to_source=$(dirname "$(readlink -f "$0")")
cd "$to_source" || exit

flag=true
if [ "$VERBOSE" = true ]; then
    echo "Check address sanitizer"
fi
bash build_debug_asan.sh
check_tests
if [ "$?" = "1" ]; then
    flag=false
fi

echo "_________________________________________________________"

if [ "$VERBOSE" = true ]; then
    echo "Check memory sanitizer"
fi
bash build_debug_msan.sh
check_tests
if [ "$?" = "1" ]; then
    flag=false
fi

echo "_________________________________________________________"

if [ "$VERBOSE" = true ]; then
    echo "Check undefinedBehavior sanitizer"
fi
bash build_debug_ubsan.sh
check_tests
if [ "$?" = "1" ]; then
    flag=false
fi

echo "_________________________________________________________"

if [ "$flag" = false ]; then
    echo "Sanitizers - ERROR"
else
    echo "Sanitizers - COMPLETE"
fi