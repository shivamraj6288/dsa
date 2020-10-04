#! /bin/bash 
g++ 190050113_2.cpp

echo "testcases2/input_fibo"
time ./a.out < testcases2/input_fibo > out 
a=$(diff out testcases2/ans_fibo | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_fibo \n"
	exit 1
fi

rm out 
echo "testcases2/input_task0_1"
time ./a.out < testcases2/input_task0_1 > out 
a=$(diff out testcases2/ans_task0_1 | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_task0_1 "
	exit 1
fi


echo "testcases2/input_thue"
time ./a.out < testcases2/input_thue > out 
a=$(diff out testcases2/ans_thue | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_thue"
	exit 1
fi


echo "testcases/input_bigrand.txt"
time ./a.out < testcases/input_bigrand.txt > out 
a=$(diff out testcases/ans_bigrand.txt | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_bigrand.txt "
	exit 1
fi

echo "testcases/input_linear.txt"
time ./a.out < testcases/input_linear.txt > out 
a=$(diff out testcases/ans_linear.txt | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_linear.txt "
	exit 1
fi


echo "testcases/input_random.txt"
time ./a.out < testcases/input_random.txt > out 
a=$(diff out testcases/ans_random.txt | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_random.txt "
	exit 1
fi


echo "testcases/input_random1.txt"
time ./a.out < testcases/input_random1.txt > out 
a=$(diff out testcases/ans_random1.txt | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_random1.txt "
	exit 1
fi


echo "testcases/input_thue.txt"
time ./a.out < testcases/input_thue.txt > out 
a=$(diff out testcases/ans_thue.txt | wc -l)

if [ $a -ne 0 ]
then 
	echo "error in testcases2/input_thue.txt "
	exit 1
fi

echo "A22"
time ./a.out < A22 >out 
a=$(diff out O22 | wc -l)
if [ $a -ne 0 ]
then
	echo "error in A22"
	exit 1
fi 

exit 0