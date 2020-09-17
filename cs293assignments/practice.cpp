#include <bits/stdc++.h>
using namespace std;
int main () {
	vector <int> v= {10,20,30,20,37,40};
	// cout << v[2] << endl;
	cout << lower_bound(v.begin(),v.end(),35)-v.begin();
	cout << endl;

}