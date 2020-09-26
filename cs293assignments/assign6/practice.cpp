#include <bits/stdc++.h>
using namespace std;
int main () {
	vector <int> v= {40,20,60,30,80,};
	// cout << v[2] << endl;
	cout << lower_bound(v.begin(),v.end(),35)-v.begin();
	cout << endl;

}