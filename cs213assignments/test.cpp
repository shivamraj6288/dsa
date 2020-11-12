#include <bits/stdc++.h>
using namespace std;
#include "190050113_3.h"

int main(){
	int n;
	cin>>n;
	n=4;
	quad_tree a(n);
	cout << a.size();
	cout << a.node[0]<<endl << a.node[1] << endl;
	quad_tree b(a);
	cout << "b created";
	cout << "b created";
	cout << "b created";
	cout << "b created";
	cout << "b created";
	cout <<endl << b.size();
	quad_tree c(5,68,4,4);
	cout << c.size() << endl;
	
	a.set(6,6,8,9,1);
	cout << "set checked \n";
	cout << a.get(8,8) << endl;
	
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << a.get(i,j) << ",";
		}
		cout << endl;
	}
	cout <<"c values " << c.get(4,5) << endl;
	a.complement();
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << a.get(i,j) << ",";
		}
		cout << endl;
	}
	b.set(0,0,5,5,1);
	cout << " b matrix is \n";
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << b.get(i,j) << ",";
		}
		cout << endl;
	}
	a.resize(8);
	cout <<"resize =============================\n";
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << a.get(i,j) << ",";
		}
		cout << endl;
	}
	a.overlap(b);
	cout <<"=============================\n";
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << a.get(i,j) << ",";
		}
		cout << endl;
	}
	a.intersect(b);
	cout <<"=============================\n";
	for(int i=0; i<pow(2,n); i++){
		for (int j=0; j<pow(2,n); j++){
			cout << a.get(i,j) << ",";
		}
		cout << endl;
	}
	
}
