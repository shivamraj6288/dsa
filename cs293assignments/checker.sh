#!/bin/bash 
g++ 190050113_9.cpp

for file in ls *.in
do
	echo $file
	./a.out < $file > out.ans
	out2=$(sed -i 's/.in/.ans' $file)
	diff out.ans $out2
done


