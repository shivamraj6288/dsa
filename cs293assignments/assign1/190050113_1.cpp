#include <iostream>
using namespace std;
int jn(long long int n, int k){
	if (n==1) return 0;
	if (n<k){
		return ((jn(n-1,k)+k)%n);
	}
	long long int change= n/k;
	long long int value= jn(n-change ,k);

	value -= n%k;
	
	if (value<0)
		value+=n;
	
	else 
		value += value /(k-1);

	
	return value;

}

int main (int argc, char *argsv[]){
	long long int n;
	int k;
	cin >> n >> k;
	cout << jn(n,k)+1;

}