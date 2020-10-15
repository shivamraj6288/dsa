g++ 190050113_2.cpp
time ./a.out < thirdTest/input_r3 >out 
a=$(diff out thirdTest/ans_r3)
if [ $a -ne 0 ]
then
	echo "error in thirdTest/input_r3"
	cat out 
fi 
