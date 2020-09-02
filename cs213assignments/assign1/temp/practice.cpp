#include <iostream>
#include "./190050113_1.h"
using namespace std;

// class pr{
// 	int l;
// 	int k;
// 	public :
// 	int a[l];
// 	for (int i=0; i<l ;i++){
// 		a[i]=i;
// 	}
// 	pr(int n, int m){
// 		l=n;
// 		k=m;
// 	}

// 	int get(){
// 		return l;
// 	}
// };

int main(){
	// pr a(10,20);
	int a[5]={4,2,3,1,0};
	permutation r(5,a);

	permutation b= r^2;
	cout << endl << "nnnn" << endl;
	cout <<b.size()<< endl;
	cout << b.to_array()[2] << endl;
	b.square_root();
	r.square_root();
	// pr b(10,20);
	// pr c(1,2);

	// int a[2];
	// a[0]=1; a[1]=2;
	// int b[2];
	// b[0]=1; b[1]=2;
	// // cout << a.get();

	// cout << (a==b) << endl;
	// cout << (a==c) << emdl;
}