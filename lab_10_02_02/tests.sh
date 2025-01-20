#!/bin/bash

for ((i=10; i <= 16; i++ ))
do
#    touch ./func_tests/data1/neg_${i}_args.txt
    touch ./func_tests/data/neg_${i}_in.txt
    touch ./func_tests/data/neg_${i}_out.txt
#    echo ./func_tests/data1/neg_${i}_in.txt ./func_tests/data1/test.txt "SORT" > ./func_tests/data1/neg_${i}_args.txt

#    touch ./func_tests/data1/pos_${i}_args.txt
#    touch ./func_tests/data1/pos_${i}_in.txt
#    touch ./func_tests/data1/pos_${i}_out.txt
#    echo ./func_tests/data1/pos_${i}_in.txt ./func_tests/data1/pos_${i}_out.txt "POP_FRONT" > ./func_tests/data1/pos_${i}_args.txt
done