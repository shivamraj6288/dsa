#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int l;
int mp;

string *adtb;
string *fv;

int factorial (int n){
	return (n==1 || n==0) ? 1 : n*factorial(n-1);
}

void print (bool a[]){
	for (int i=0; i< m; i++)
		cout << a[i] << ",";
	cout << endl;
}	
int num1(int a){
	int rs=0;
	for (int i=0; i<l; i++){
		if (fv[a][i]=='1')
			rs++;

	}
	// cout << rs << endl;
	return rs;


}
string dtb(int a){
	string rs ="";
	for (int i=n-1; i>=0; i--){
		int k=a>>i;
		if (k&1)
			rs+='1';
		else 
			rs+='0';
	}
	// cout << rs;
	return rs;
}
int btd (string a){
	return stoi(a,0,2);
}
// int btd(string a) {
// 	string num = a;
//     int dec_value = 0;
 
//     int base = 1;
 
//     int len = num.length();
//     for (int i = len - 1; i >= 0; i--) {
//         if (num[i] == '1')
//             dec_value += base;
//         base = base * 2;
//     }
 
//     return dec_value;

// }

string permute(int p[], string a){
	string b=a;
	for (int i=0; i<n;i++){
		b[i]=a[p[i]];
	}
	return b;
}

bool check(int p[],int a, int b){
	bool rs =true;
	for(int i=0; i<l; i++){
		if (fv[a][i]!=fv[b][btd(permute(p,adtb[i]))]){
			rs=false;
			break;
		}
	}
	return rs;
}

bool checktf(int a, int b){
	int p[n];
	for (int i=0; i<n; i++){
		p[i]=i;
	}
	bool rs =false;
	while (next_permutation(p,p+n)){
		if (check(p,a,b)){
			rs=true;
			break;
		}
		

	}
	return rs;
}

int numatp2(int a){
	int i=0;
	int j=pow(2,i);
	int rs=0;
	while (j<l){
		if (fv[a][j]=='1')
			rs++;
		i++;
		j=pow(2,i);
	}
	return rs;
}
int nbat2(int a){
	int i=0; 
	int j=l-1-pow(2,i);
	int rs=0;
	while (j>=0){
		if(fv[a][j]=='1')
			rs++;
		i++;
		j=l-1-pow(2,i);
	}
	return rs;
}


int main () {
	cin >> n >> m;
	l=pow(2,n);
	adtb=new string[l];
	for (int i=0; i< l; i++){
		adtb[i]=dtb(i);
	}
	// string fv[m];
	fv=new string[m];
	for (int i=0; i<m; i++){
		cin >> fv[i];
	}

	int n1[m];
	int n2[m];
	int n3[m];
	for (int i=0; i<m; i++){
		n1[i]=num1(i);
		n2[i]=numatp2(i);
		n3[i]=nbat2(i);
	}
	// print (n2);

	int rs=m;
	bool visit[m];

	for (int i=0; i<m-1; i++){
		if (!visit[i]){
			int trs=0;
			for (int j=i+1; j<m; j++){
				// bool cl=!visit[j];
				// if(cl){
				// 	cl=(n1[i]==n1[j]);
				// 	if (cl){
				// 		cl=(n2[i]==n2[j]);
				// 		if (cl){
				// 			cl=(fv[i][0]==fv[j][0]);
				// 			if(cl){
				// 				cl=(fv[i][l-1]==fv[j][l-1]);
				// 				if (cl){
				// 					cl=(n3[i]==n3[j]);
				// 				}
				// 			}
				// 		}
				// 	}
				// }

				if (!visit[j] && n1[i]==n1[j] && n2[i]==n2[j] && fv[i][0]==fv[j][0] && fv[i][l-1]==fv[j][l-1] && n3[i]==n3[j]) {
					if(checktf(i,j)){
						trs++;
						visit[j]=true;
					}
				}
			}
			rs=rs-trs;

			visit[i]=true;	
		}
		
	}

	cout<<rs<< endl;
	// print (visit);

	





}