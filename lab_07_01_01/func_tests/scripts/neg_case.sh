#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
echo "$2" > save_args.txt
args_saver=$2
IFS=" " read -r -a arr <<< "$args_saver"
file_in="${arr[0]}"
file_out="${arr[1]}"
key="${arr[2]}"

cd ../../ || exit
start_file="./app.exe"
"$start_file" $file_in $file_out $key > ./func_tests/scripts/saver.txt

saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 0
fi
exit 1
