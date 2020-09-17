#include <iostream>
using namespace std ;
#include<vector>
#include <algorithm>

int n;
// vector <int> a;
int *a;
// vector <int> id;

// int head(vector <int> v){
// 	return v[0];
// }

// vector <int> tail(vector <int> v){
// 	vector <int> t;
// 	if (v.size()==1)
// 		return t;
// 	return (v.erase(v.begin()));
// }
// vector <int> push(vector <int> v, int n){
// 	return(v.insert(v.begin(),n));
// }


// vector <int> merge (vector <int>v1, vector <int> v2){
// 	if (v1.size()==0)
// 		return v2;
// 	if (v2.size()==0)
// 		return v1;
// 	if (f[head(v1)<=f[head(v2)]])
// 		return push(merge(tail(v1),v2), head(v1));
// 	else 
// 		return push(merge(v1,tail(v2)),head(v2));
// }

// vector <int> odd(vector<int> v){
// 	if (v.size()==0)
// 		return v;
// 	else 
// 		return push(even(tail(v)),head(v));
// }

// vector <int> even(vector<int> v){
// 	if (v.size()==0)
// 		return v;
// 	else 
// 		return(odd(tail(v)));
// }

// vector<int> msort(vector <int> v){
// 	if (v.size()<=1)
// 		return v ;
// 	return merge(msort(odd(index)), msort(even(index)));
// }



int main (){
	cin>> n;
	a=new int [n];
	// for (int i=0; i<n; i++){
	// 	id[i]=i;
	// }

	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	int *v=new int [n];
	v[0]=-1;

	int ns[n];
	ns[0]=1;

	for (int i=1; i<n; i++){
		int j=i-1;
		while (j>=0 && a[j]<a[i])
			j=v[j];

		v[i]=j;
		ns[i]=i-j;
	}
	delete[] v;
	v=new int[n];

	v[n-1]=n;

	for (int i=n-2; i>=0; i--){
		int j=i+1;
		while (j<n && a[j]<a[i])
			j=v[j];
		v[i]=j;
		ns[i]+=(j-i-1)*ns[i];
	}

	for (int i=0; i<n; i++){
		cout << ns[i] << " ";
	}




}