#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
// int min_v (vector <int> a){
// 	int n=a.size();
// 	int value=a[0];
// 	for (int i=1; i<n; i++){
// 		if (a[i]<value)
// 			value=a[i];
// 	}
// 	return value;
// }
// int cost(vector<int> a){
// 	int n=a.size();
// 	int m=min(a);
// 	int d=0;
// 	for (int i=0; i<n; i++){
// 		d+=abs(a[i]-d);
// 	}

// 	return d;

// }
// bool cmp (vector<int> a, vector <int> b){
// 	return (cost(a)<cost(b));

// }

// int chek_after(vector <int> a, int i){
// 	int n=a.size();
// 	for (int j=n-1; j>i; j--){
// 		if a[j]!=0
// 			return j;
// 	}
// }


vector <int> distribute (vector <int> a, int i){
	int n=a.size();
	int r=a[i];
	a[i]=0;
	while (r>0){
		a[i+1]++;
		r--;
		i=(i+1)%n;
	}

	return a;
}


// int last_z (vector <int>a){
// 	int n=a.size();
// 	for (int j=n-1; j>0; j--){
// 		if (a[j]!=0)
// 			return j;
// 	}
// 	return 0;
// }

int last_z(vector <int> a){
	int n=a.size();
	if (n==1){
		return a[0];
	}
	int max=a[1];
	int index=1;

	for (int i=2; i<n; i++){
		if (max<a[i]){
			index=i;
			max=a[i];
		}

	}
	if (max==0)
		return 0;
	return index;
}


int main (int argc, char*argsv[]){
	int n, k;
	cin >>n >>k;
	vector <int> d;
	for (int i=0; i<k; i++){
		int input;
		cin >>input;
		d.push_back(input);
	}

	vector <int> result;

	int start=last_z(d);

	while (start){
		result.push_back(start);
		d=distribute(d,start);
		start=last_z(d);
		// cout << start;
	}
	result.push_back(0);

	for (int i=0; i<result.size(); i++){
		cout << result[i] << " ";

	}
	// cout << 0;





}