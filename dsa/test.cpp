#include <bits/stdc++.h>
using namespace std;
void fn(vector<int> &a){
	a[2] = 123;
}

int main(int argc, char *argsv[])
{
	vector<int> a(10, 2);
	fn(a);
	cout << a[2];
}