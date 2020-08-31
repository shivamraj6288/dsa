#include <bits/stdc++.h>
using namespace std;

int c[52];
int numCoin;
long long int value[52][252];
bool check[52][252];

// bool check (int c[],int m, int num){
// 	for (int i=0; i<m; i++){
// 		if (c[i]<=num)
// 			return true;
// 	}

// 	return false;
// }

// bool checkExact(int c[], int m, int num){
// 	for (int i=0; i<m; i++){
// 		if (c[i]==num)
// 			return true;
// 	}
// 	return false;
// }

long long int get (int i, int n){
	if (check[i][n])
		return value[i][n];
	if (i>numCoin)
		return 0;
	// if (c[i]>n)
	// 	return 0;
	if (n<0)
		return 0;
	if (n==0)
		return 1;
	
	value[i][n]= get(i, n-c[i])+get(i+1, n);
	check[i][n]=true;
	return value[i][n];
}
int main (int argc , char *argsv[]){
	int n;
	cin>> n>> numCoin;
	
	for (int i=1; i<=numCoin; i++){
		cin >> c[i];
	}

	// long long int value[n+1];
	// for (int i=0; i< n+1; i++){
	// 	value[i]=-1;
	// }

	// cout <<value[0] << value [n-1];

	// for (int i=0; i<n+1; i++){
	// 	if (!check(c,m,i))
	// 		value[i]=0;
	// }

	// cout << check[5][200];

	cout <<get(1,n);
	// cout << value[1][n];

	// for (int i=1; i<=numCoin; i++){
	// 	cout << value[i][n] << " , ";
	// }

	// cout << endl;
	// cout<<value[n];
	// cout << endl;



}