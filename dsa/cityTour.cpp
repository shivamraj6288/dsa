#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
	if (n==0 || n==1){
		return 1;
	}
	return n*factorial(n-1);
}
int solve(int A, vector<int> &B) {
	int nb=B.size();
	if (nb==1){
		return 0;
	}

	int nv=A-nb;
	sort(B.begin(),B.end());

	



}

int main(){
	int A;
	cin >>A;
	int nb;
	cin >> nb;
	vector<int> B;

	for (int i=0; i<nb; i++){
		int a;
		cin >> a;
		B.push_back(a);

	}
	cout << solve(A,B);

}

