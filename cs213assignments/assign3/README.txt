Author: Vibhav Aggarwal

Usage:

1) First include your header file in main.cpp (Line 4).
2) Compile it: g++ -O2 -o yourname main.cpp
3) Generating testcase:
	a) Compile gen.cpp: g++ -O2 -o gen gen.cpp
	b) Run: ./gen n t > in		(Ex: ./gen 10 1000 > input)
	c) n denotes height of tree and t denotes number of testcases
4) Run your code on input file: ./yourname < in > out
5) Run the given binary on input: ./vib < in > out2 (If it shows permission denied then run: chmod +x ./vib)
6) Do a diff: diff out out2
7) On doing diff, only 7 lines should be shown from both files. They show the time taken by your code and attached binary in milliseconds for each function separately.
