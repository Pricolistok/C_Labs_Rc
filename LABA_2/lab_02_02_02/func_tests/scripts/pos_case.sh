#!/bin/bash
if [ $# != 2 ]; then
	echo Error pos_case
	exit 1
fi
echo "$1" > save_in.txt
echo "$2" > save_out.txt
touch save_res.txt
start_file=$(find "../../" -name "app.exe")
"$start_file" < save_in.txt > save_res.txt
bash comparator.sh save_res.txt save_out.txt
if  ! bash comparator.sh save_res.txt save_out.txt; then
	exit 1
fi
exit 0
