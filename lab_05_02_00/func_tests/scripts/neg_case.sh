#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
echo "$1" > save_in.txt
args_saver="$2" 
touch save_res.txt
start_file=$(find "../../" -name "app.exe")
"$start_file" "../../$args_saver" < save_in.txt > save_res.txt
saver_code=$?
if [[ $saver_code -ne 0 ]]; then
	exit 0
fi
exit 1
