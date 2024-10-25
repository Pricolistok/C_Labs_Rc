#!/bin/bash

file_1=$1
file_2=$2 

create_line=""

if [ -e "$file_1" ] && [ -e "$file_2" ]; then
  lines_1=$(cat "$file_1")
  lines_2=$(cat "$file_2")
  for line in $lines_1
  do
    create_line+="${line} "
  done
  echo "$create_line" 1> save_line_1.txt
  
  create_line=""
  for line in $lines_2
  do
    create_line+="${line} "
  done
  echo "$create_line" 1> save_line_2.txt
  new1=$(sed -n "s/.*Result:[[:space:]]*//p" "save_line_1.txt")
  new2=$(sed -n "s/.*Result:[[:space:]]*//p" "save_line_2.txt")
  echo "$new1" 1> save_nums_1.txt
  echo "$new2" 1> save_nums_2.txt
  diff save_nums_1.txt save_nums_2.txt 1> saver.txt; 
  if [ $? -ne 1 ]; then
    exit 0
  else
    exit 1
  fi 
else
    exit 1
fi

