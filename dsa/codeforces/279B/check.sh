if [[ $# -le 0 ]]
then 
file=$(ls | grep 'cpp')
else 
file=$1
fi

g++ "$file"
FD1=7
FD2=8

exec 7<"test.in"
exec 8<"test.out"

eof1=0 
eof2=0

while [[ $eof1 -eq 0 && $eof2 -eq 0 ]]
do
    if read data1<&$FD1; then
    if read data2<&$FD2; then 
    # echo "$data1">1.in
    val=$(echo "$data1" | ./a.out)
    if [[ $val != $data2 ]]
    then
    echo "$data1"
    echo "Your Output: $val"
    echo "Correct Output: $data2"
    echo "====="
    fi
    else
    eof2=1
    fi
    else 
    eof1=1
    fi
done 
