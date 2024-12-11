#!/bin/bash

for ((i=10; i <= 18; i++ ))
do
    touch ./func_tests/data/neg_${i}_args.txt
    touch ./func_tests/data/neg_${i}_in.txt
    touch ./func_tests/data/neg_${i}_out.txt
    echo ./func_tests/data/neg_${i}_in.txt ./func_tests/data/test.txt "SORT" > ./func_tests/data/neg_${i}_args.txt

#    touch ./func_tests/data/pos_${i}_args.txt
#    touch ./func_tests/data/pos_${i}_in.txt
#    touch ./func_tests/data/pos_${i}_out.txt
#    echo ./func_tests/data/pos_${i}_in.txt ./func_tests/data/pos_${i}_out.txt "POP_FRONT" > ./func_tests/data/pos_${i}_args.txt
done