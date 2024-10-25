#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=1
echo "$2" > save_out.txt
args_saver="$3"
file_path=$(echo "$args_saver" | cut -d '.' -f 2-)
comand=${args_saver// .$file_path/}
start_file=$(find "../../" -name "app.exe")
"$start_file" import "$1" "../..$file_path"
"$start_file" "$comand" "../..$file_path" > save_res.txt
touch save_res.txt
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
bash comparator.sh save_res.txt save_out.txt
saver_code=$?
if [ $saver_code -ne 0 ]; then
	exit 1
fi
exit 0