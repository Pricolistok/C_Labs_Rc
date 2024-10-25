#!/bin/bash
if [ $# != 3 ]; then
	echo Error pos_case
	exit 1
fi
saver_code=0
echo "$1" > save_in.txt
echo "$2" > save_out.txt
args_saver="$3"
touch save_res.txt
start_file=$(find "../../app.exe")
"$start_file" "../../$args_saver" < save_in.txt > save_res.txt
saver_code="$?"
bash comparator.sh save_res.txt save_out.txt
if ! bash comparator.sh save_res.txt save_out.txt || [ $saver_code -ne 0 ]; then
	exit 1
fi
exit 0
