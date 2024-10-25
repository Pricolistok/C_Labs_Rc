#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=1
echo "$2" > save_out.txt
echo "$3" > save_args.txt
all=$3
args_saver=$(grep -oE '(st|ft)' save_args.txt)
cd ../../ || exit
start_file="./app.exe"
if [[ "$args_saver" =~ "$all" ]]; then
	"$start_file" $all > ./func_tests/scripts/saver.txt
else
	"$start_file" $all > ./func_tests/data/test.txt
fi
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
