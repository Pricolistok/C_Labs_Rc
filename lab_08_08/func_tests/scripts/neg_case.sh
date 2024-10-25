#!/bin/bash
if [ $# != 1 ]; then
	echo Error neg_case
	exit 1
fi
saver_code=1
echo $1 > in.txt

cd ../../ || exit
start_file="./app.exe"
"$start_file" < func_tests/scripts/in.txt > func_tests/scripts/out_res.txt

saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 0
fi
exit 1
