#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
echo "$1" > save_in.txt
touch save_res.txt
start_file=$(find "../../" -name "app.exe")

if ! "$start_file" < save_in.txt > save_res.txt; then
	exit 0
fi
exit 1
