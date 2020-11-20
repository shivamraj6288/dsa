rm valgrind-out.txt
g++ -ggdb3 test.cpp 
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./a.out < i1