#!/bin/bash

to_source=$(dirname "$(readlink -f "$0")")
flag=0
cd "$to_source" || exit
if [ "$1" = "-v" ]; then
  VERBOSE=true
else
  VERBOSE=false
fi
cnt_complete_pos=0
cnt_all_pos=0
ls "$to_source/../data" > save_all.txt
count_files_in=$(grep -Ec 'pos_[0-9]{1,2}_in\.txt' "save_all.txt")
count_files_out=$(grep -Ec 'pos_[0-9]{1,2}_out\.txt' "save_all.txt")
count_files_args=$(grep -Ec 'pos_[0-9]{1,2}_args\.txt' "save_all.txt")
if [ "$count_files_in" -eq "$count_files_out" ] && [ "$count_files_in" -eq "$count_files_args" ]; 
then
  cnt_all_pos=$count_files_in
  if [ "$count_files_in" -ne 0 ]; 
    then
    for ((i=1; i < count_files_in + 1; i++ ))
    do
      if [ "$i" -lt 10 ];
      then
        data_in="../data/pos_0${i}_in.txt"
        data_out=$(cat "../data/pos_0${i}_out.txt")
        data_arg=$(cat "../data/pos_0${i}_args.txt")
        bash pos_case.sh "$data_in" "$data_out" "$data_arg"
        if [ $? -eq 1 ]; then
          if [ "$VERBOSE" = true ]; then
            echo "pos_0$i - ERROR"
          fi
          flag=$((flag + 1))
        else
          if [ "$VERBOSE" = true ]; then
            echo "pos_0$i - OK"
          fi
          cnt_complete_pos=$((cnt_complete_pos + 1))
        fi
      else
        data_in="../data/pos_${i}_in.txt"
        data_out=$(cat "../data/pos_${i}_out.txt")
        data_arg=$(cat "../data/pos_${i}_args.txt")
        bash pos_case.sh "$data_in" "$data_out" "$data_arg"
        if [ $? -eq 1 ]; then
          if [ "$VERBOSE" = true ]; then 
            echo "pos_$i - ERROR"
          fi
          flag=$((flag + 1))
        else
          if [ "$VERBOSE" = true ]; then
            echo "pos_$i - OK"
          fi
          cnt_complete_pos=$((cnt_complete_pos + 1))
        fi
      fi
    done
  fi
else
  exit 1
fi
cnt_complete_neg=0
count_files_in=$(grep -Ec 'neg_[0-9]+_in\.txt' "save_all.txt")
count_files_out=$(grep -Ec 'neg_[0-9]+_out\.txt' "save_all.txt")
count_files_args=$(grep -Ec 'neg_[0-9]+_args\.txt' "save_all.txt")
if [ "$count_files_in" -eq "$count_files_out" ] && [ "$count_files_in" -eq "$count_files_args" ]; 
then
  cnt_all_neg=$count_files_in
  if [ "$count_files_in" -ne 0 ]; 
  then
    for ((i=1; i < count_files_in + 1; i++ ))
    do
      if [ "$i" -lt 10 ];
      then
        data_in=$(cat "../data/neg_0${i}_in.txt")
        data_args=$(cat "../data/neg_0${i}_args.txt")
        bash neg_case.sh "$data_in" "$data_args" 
        if [ $? -eq 1 ]; then
          if [ "$VERBOSE" = true ]; then
            echo "neg_0$i - ERROR"
          fi
          flag=$((flag + 1))
        else
          if [ "$VERBOSE" = true ]; then
            echo "neg_0$i - OK"
          fi
          cnt_complete_neg=$((cnt_complete_neg + 1))
        fi
      else
          data_in=$(cat "../data/neg_${i}_in.txt")
          data_args=$(cat "../data/neg_${i}_args.txt")
          bash neg_case.sh "$data_in" "$data_args" 
        if [ $? -eq 1 ]; then
          if [ "$VERBOSE" = true ]; then
            echo "neg_$i - ERROR"
          fi
          flag=$((flag + 1))
        else
            if [ "$VERBOSE" = true ]; then
              echo "neg_$i - OK"
            fi
            cnt_complete_neg=$((cnt_complete_neg + 1))
        fi
    fi  
    done
  fi
else
  flag=$((flag + 1))
fi
if [ "$flag" == 0 ]; then
  echo "TESTS - COMPLETE"
  echo "Positive tests: Passed $cnt_complete_pos tests out of $cnt_all_pos"
  echo "Negative tests: Passed $cnt_complete_neg tests out of $cnt_all_neg"
  exit 0
else
  echo "TESTS - FAIL"
  echo "Positive tests: Passed $cnt_complete_pos tests out of $cnt_all_pos"
  echo "Negative tests: Passed $cnt_complete_neg tests out of $cnt_all_neg"
  exit 1
fi

