#!/bin/bash

numtests=10000

for i in $(seq 1 $numtests); do
rm in.txt
rm out.txt
g++ generator.cpp
./a.out >in.txt
# g++ 190050113_2.cpp
time ./190050113_2 <in.txt >out.txt
./check in.txt out.txt

done