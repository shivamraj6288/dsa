#include <bits/stdc++.h>
using namespace std;

int main(){
	int b[2][3];
	b[0][0]=10;
	b[0][1]=11;
	b[0][2]=12;
	b[1][0]=20;
	b[1][1]=21;
	b[1][2]=22;
	cout << b<< endl;
	cout << *b << endl;
	cout << &b[0][0] << endl;
	cout << **b << endl;

	cout << b+1 << endl;
	cout << *(b+1) << endl;
	cout << *b+1 << endl;
	cout << **(b+1) << endl << *(*b+1) << endl;
}