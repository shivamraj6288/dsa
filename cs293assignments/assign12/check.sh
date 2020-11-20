
g++ 190050113_12.cpp

for i in {0..9}
do 
	# echo "foor loop"
	inf="$i.in"
	ouf="$i.out"
	# echo $inf 
	output=$(./a.out < $inf)
	ans=''
	while IFS= read line 
	do 
		ans="$line"
		# echo "$ans"
		break
	done < $ouf 
	if [ "$output" != "$ans" ]
	then 
		echo "$inf"
		echo "correct answer=$ans"
		echo "your answer=$output"
		# exit 1
	fi 
done 
echo "all good"
exit 0

