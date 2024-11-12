#!/bin/bash
if [ $# != 2 ]; then
	echo Error neg_case
	exit 1
fi
saver_code=1
echo "$2" > save_args.txt
all="$2"
cd ../../ || exit
start_file="./app.exe"
"$start_file" $all > ./func_tests/scripts/saver.txt
if [ "$?" -ne 0 ]; then
	exit 0
fi
exit 1
