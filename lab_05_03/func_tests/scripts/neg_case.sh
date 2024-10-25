#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
args_saver="$3"
file_path=$(echo "$args_saver" | cut -d '.' -f 2-)
comand=${args_saver// .$file_path/}
start_file=$(find "../../" -name "app.exe")
saver_code="$start_file import $1 ../../$file_path"
if $saver_code -ne 1; then
	exit 1
fi
saver_code="$start_file $comand ../..$file_path" > save_res.txt
if $saver_code -ne 1; then
	exit 1
fi
exit 0
