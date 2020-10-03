#include <bits/stdc++.h>
using namespace std;
char *cl;
map <char, int> id;
int k;
string *fv;

vector <vector<bool>>check;
vector <vector<unsigned long long int>> lv;


unsigned long long int f1 (unsigned long long int n){
	// unsigned long long int lv[k][n+1];

	if (check[0].size()==0){
		for (int i=0; i<k; i++){
			// lv[i][0]=1;
			// lv[i][1]=fv[i].length();
			vector <unsigned long long int>t0;
			t0.push_back(1);
			// t0.push_back(fv[i].length());
			// vector <unsigned long long int>t1;
			lv.push_back(t0);
			// vector<bool> bt;
			// bt.push_back(true);
			check[i].push_back(true);
		}
	}

	if (check[0].size()==1){
		for (int i=0; i<k; i++){
			lv[i].push_back(fv[i].length());
			check[i].push_back(true);
		}
	}
	if (n==0 || n==1){
		return lv[0][n];
	}

	for (unsigned long long int i=check[0].size(); i<=n; i++){
		for (int j=0; j<k; j++){
			lv[j].push_back(0);
			for (int al=0; al<fv[j].length(); al++){
				lv[j][i]+=lv[id[fv[j][al]]][i-1];
			}
			check[j].push_back(true);


			// cout << lv[j][i] << " ";
		}

		// cout << endl;
	}
	return lv[0][n];
}

char f2 (unsigned long long int n){

	return 'a';

}
int main () {
	cin >> k;
	char tcl[6]={'a','b','c','d','e','f'};
	id['a']=0; id['b']=1; id['c']=2; id['d']=3; id['e']=4; id['f']=5;
	cl=new char[k];

	fv=new string[k];

	vector <bool> bt1;

	for (int i=0; i<k; i++){
		cin >> fv[i];
		cl[i]=tcl[i];
		check.push_back(bt1);
	}



	int T;
	cin >> T;

	for (int t=0; t<T; t++){
		int q;
		cin >> q;
		switch (q) {
			case 0:
				unsigned long long int n;
				cin >> n;
				cout << f1(n)<< endl;
			break;

			case 1:
				cin >> n;	
				cout <<f2(n);
			break;

			case 2:
				cout << "not complete" << endl;
			break ;

			case 3:
				cout << "not complete" << endl;
			break;

		}
	}

}