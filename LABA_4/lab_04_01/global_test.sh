#!/bin/bash
if [ "$1" = "-v" ]; then
  VERBOSE=true
else
  VERBOSE=false
fi

echo "CodeChecker main.c"
if /home/george/CodeChecker/CodeChecker/CodeChecker.exe main.c
then
    echo "main.c - OK"
fi
echo "________________________________________________________"
echo "________________________________________________________"
echo "CodeChecker process.c"
if /home/george/CodeChecker/CodeChecker/CodeChecker.exe process.c
then
    echo "process.c - OK"
fi
echo "________________________________________________________"
echo "________________________________________________________"
echo "CodeChecker input_output.c"
if /home/george/CodeChecker/CodeChecker/CodeChecker.exe input_output.c
then
    echo "input_output.c - OK"
fi
echo "________________________________________________________"
echo "________________________________________________________"
echo "Shellchecker"
if shellcheck ./*.sh
then
    echo "Shellchecker in root - OK"
fi
echo "________________________________________________________"
echo "________________________________________________________"
echo "Shellchecker"
if shellcheck ./func_tests/scripts/*.sh
then
    echo "Shellchecker in scripts - OK"
fi
echo "________________________________________________________"
echo "________________________________________________________"

if [ $VERBOSE = true ]; then
    echo "Sanitizers"
    ./sanitize_check.sh -v
    echo "________________________________________________________"
    echo "________________________________________________________"
    echo "Covergae"
    ./collect_coverage.sh -v
    echo "________________________________________________________"
    echo "________________________________________________________"
else
    echo "Sanitizers"
    ./sanitize_check.sh
    echo "________________________________________________________"
    echo "________________________________________________________"
    echo "Covergae"
    ./collect_coverage.sh
    echo "________________________________________________________"
    echo "________________________________________________________"
fi