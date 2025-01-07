#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=1
cat $1 > in.txt
echo $2 > out.txt

cd ../../ || exit
start_file="./app.exe"

"$start_file" < func_tests/scripts/in.txt > func_tests/scripts/out_res.txt

saver_code=$?

if [ $3 = true ]; then
	valgrind -q --leak-check=full "$start_file" < func_tests/scripts/in.txt
fi

if [ $saver_code -ne 0 ]; then
	exit 1
fi
cd ./func_tests/scripts || exit
bash ./comparator.sh out.txt out_res.txt
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
exit 0
