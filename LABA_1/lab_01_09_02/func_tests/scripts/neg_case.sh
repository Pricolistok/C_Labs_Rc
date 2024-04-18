#!/bin/bash
if [ $# != 2 ]; then
	echo Error pos_case
	exit 1
fi
echo "$1" > save_in.txt
touch save_res.txt
start_file=$(find "../../" -name "app.exe")
"$start_file" < save_in.txt > save_res.txt
if [ $? -eq 1 ]; then
	exit 0
fi
exit 1
