#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
saver_code=1
echo "$2" > save_args.txt
all="$2"
args_saver=$(grep -oE '(st|ft)' save_args.txt)
cd ../../ || exit
start_file="./app.exe"
if [[ "$args_saver" =~ "st" ]]; then
	"$start_file" $all > ./func_tests/scripts/saver.txt
else
	"$start_file" $all > ./func_tests/scripts/saver.txt
fi
if [ $saver_code -ne 0 ]; then
	exit 0
fi
exit 1
