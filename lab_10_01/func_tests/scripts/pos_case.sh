#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=1
echo "$2" > save_out.txt
echo "$3" > save_args.txt
all="$3"
cd ../../ || exit
start_file="./app.exe"
"$start_file" $all
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
cd ./func_tests/scripts || exit
bash ./comparator.sh ../data/test.txt save_out.txt
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
exit 0
