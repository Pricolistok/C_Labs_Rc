#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=1
echo "$2" > save_out.txt
echo "$3" > save_args.txt
# cat save_args.txt
args_saver=$3
IFS=" " read -r -a arr <<< "$args_saver"
# arr=($args_saver)
file_in="${arr[0]}"
file_out="${arr[1]}"
key="${arr[2]}"


cd ../../ || exit
start_file="./app.exe"

if [ $key == "f" ]; then
	"$start_file" $file_in $file_out $key > ./func_tests/scripts/saver.txt
fi
if [ $key == "a" ]; then
	"$start_file" $file_in $file_out $key ${arr[3]} > ./func_tests/scripts/saver.txt
fi

saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
cd ./func_tests/scripts || exit
bash ./comparator.sh save_out.txt ./../.$file_out
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
exit 0
