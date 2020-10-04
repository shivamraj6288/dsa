#include <bits/stdc++.h>
using namespace std;
char *cl;
map <char, int> id;
int k;
string *fv;

vector <vector<bool>>check;
vector <vector<unsigned long long int>> lv;
vector<vector<unsigned long long int>> mat;

vector <vector<unsigned long long int>> squaremat (vector <vector<unsigned long long int>> a ) {
	// vector <unsigned long long int> temp(k,0);
	vector <vector<unsigned long long int>> mul;
	for (int i=0; i<k; i++){
		vector<unsigned long long int> temp;
		for (int i=0; i<k; i++){
			temp.push_back(0);
		}
		mul.push_back(temp);
	}

    for (int i = 0; i < k; i++) 

    {

        for (int j = 0; j < k; j++) 

        { 

            // mul[i][j] = 0; 

            for (int l = 0; l < k; l++) 

                mul[i][j] += a[i][l]*a[l][j]; 

        } 

    } 

    return mul;

}

vector <vector<unsigned long long int>> multiply (vector <vector<unsigned long long int>> a, vector <vector<unsigned long long int>>b ) {
	// vector <unsigned long long int> temp(k,0);
	vector <vector<unsigned long long int>> mul;
	for (int i=0; i<k; i++){
		vector<unsigned long long int> temp;
		for (int i=0; i<k; i++){
			temp.push_back(0);
		}
		mul.push_back(temp);
	}

    for (int i = 0; i < k; i++) 

    {

        for (int j = 0; j < k; j++) 

        { 

            // mul[i][j] = 0; 

            for (int l = 0; l < k; l++) 

                mul[i][j] += a[i][l]*b[l][j]; 

        } 

    } 

    return mul;

}

vector <vector<unsigned long long int>> power (vector <vector<unsigned long long int>> a, unsigned long long int n){
	if (n==1){
		// cout << "power is 1 : " << n << endl;
		return a;
	}



	if (n%2==0){
		// cout << "power is 2 : " << n << endl;
		return (squaremat(power(a,n/2)));
	}

	// cout << "power is 3 : " << n << endl;
	return (multiply(a, squaremat(power(a,n/2))));
	
}

unsigned long long int f1fast(unsigned long long int n){
	if (n==0){
		return 1;

	}
	// cout << "before\n";
	vector <vector<unsigned long long int>> val=power(mat,n);
	// cout << "after \n";
	unsigned long long int rs=0;
	// cout << "val size : " << val.size() << "," << val[0].size() << endl;
	for (int i=0; i<k; i++){
		// cout << "i value while calculating rs : " << i << endl;
		rs+=val[0][i];
	}	

	return rs;
}



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

char f2helper (unsigned long long int i, unsigned long long int n, char x){
	// cout << "f2helper check : i,n,x " << i << " " << n << " " << x << endl;
	if (n==1){
		// cout << "i, n, x : " <<i <<" " << n<< " "<< x << endl;
		return fv[id[x]][i];
	}
	unsigned long long int vl=0;
	char b;
	for (int j=0; j<fv[id[x]].length();j++){
		vl += lv[id[fv[id[x]][j]]][n-1];
		if (vl>= i+1){
			b=fv[id[x]][j];
			vl -= lv[id[fv[id[x]][j]]][n-1];
			i-=vl;
			break;
		}
	}

	return f2helper(i, n-1, b);
}

char f2 (unsigned long long int n,char x){
	unsigned long long int val=11110;
	// bool bch=true;
	// // cout <<val << endl;
	// if (lv.size()>0){
	// 	// cout << lv[id[x]][check[id[x]].size()-1] << " check 1 complete\n";
	// 	if (lv[id[x]][check[id[x]].size()-1]>n+1){
	// 		for (unsigned long long int i=check[id[x]].size()-1; i>=0; i--){
	// 			if (lv[id[x]][i]<n+1){
	// 				val=i+1;
	// 				bch=false;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	// if (bch) {
	// 	for (unsigned long long int i=check[id[x]].size(); true; i++){
	// 		if (f1(i)>=n+1){
	// 			val=i;
	// 			// cout << "check 2 " << val << endl;
	// 			break;
	// 		}
	// 	}
	// }
	// // if (val==11110){
	// 	// return ('s');
	// // }
	// // cout << "req value greater than given i : " << val << endl;

	// return (f2helper(n,val,x));

	for (unsigned long long int i=0; true; i++){
		if (f1(i)>=n+1){
			val=i;
			// cout << "check 2 " << val << endl;
			break;
		}
	}

	return (f2helper(n,val,x));


	

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


	for (int i=0; i<k; i++){
		vector <unsigned long long int> temp(k,0);
		for (int j=0; j<fv[i].length(); j++){
			switch (fv[i][j]){
				case 'a' :
					temp[0]++;
					break;
				case 'b':
					temp[1]++;
					break;
				case 'c':
					temp[2]++;
					break;
				case 'd':
					temp[3]++;
					break;
				case 'e':
					temp[4]++;
					break;
				case 'f':
					temp[5]++;
					break;

			}

		}
		mat.push_back(temp);

	}

	// cout << "mat size : "<< mat.size() << ","<< mat[0].size() << endl;

	for (int i=0; i<k; i++){
		for (int j=0; j<k; j++){
			// cout << mat[i][j] << " ";
		}
		// cout << endl;
	}

	// cout << "mat is formed" << endl;

	int T;
	cin >> T;

	for (int t=0; t<T; t++){
		int q;
		cin >> q;
		switch (q) {
			// case 0:
			// 	unsigned long long int n;
			// 	cin >> n;
			// 	cout << f1(n)<< endl;
			// break;

			case 0:
				unsigned long long int n;
				cin >> n;
				cout << f1fast(n)<< endl;

				break;

			case 1:
				cin >> n;
				// cout << n << endl;	
				cout <<f2(n,'a')<< endl;
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