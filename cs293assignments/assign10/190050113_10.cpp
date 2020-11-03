#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int l;

string *adtb;
string *fv;

int factorial (int n){
	return (n==1 || n==0) ? 1 : n*factorial(n-1);
}

void print (string a[]){
	for (int i=0; i< l; i++)
		cout << i<< "=" << a[i] << "\n";
	cout << endl;
}	

int num1s(string a){
	int rs=0;
	for (int i=0; i<n; i++){
		if (a[i]=='1')
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
// bool check2tf(int a, int b) {
// 	int p[n];
// 	for (int i=0; i<n; i++){
// 		p[i]=i;
// 	}
// 	int cr[n];
// 	bool lc=true;
// 	while (lc){
// 		for (int k=1; k<n; k++){
// 			for (int i=0; i<n-k; i++) cr[i]=0;
// 			for (int i=n-k; i<n; i++) cr[i]=1;

// 		}
// 	}
// }
bool combinations(string s1, string s2){

    if(s1[0]!=s2[0] || s1[s1.size()-1]!=s2[s2.size()-1]) return false;

    int arr[n];

	int curr[n];

	int j = n;
	while (j--) {
		arr[n-1-j] = n-1-j;
	}

    do{
        bool b = true;
        for (int k = 1; k < n; k++){
            for(int i=0;i<n-k;i++) curr[i]=0;
            for(int i=n-k;i<n;i++) curr[i]=1;
            do{
                int x=0,y=0,p2=1;
                for(int i=0;i<n;i++){
                    x+=curr[i]*p2;
                    y+=curr[arr[i]]*p2;
                    p2*=2;
                }
                if(s1[x]!=s2[y]) {
                    b=false;
                    continue;
                }
            }while (next_permutation(curr, curr+n));
        }
        if(b) return true;
    }while (next_permutation(arr, arr+n));

    return false;
    
}
bool compv(vector<int>a, vector<int>b){
	bool rs=true;
	for (int i=0; i<a.size(); i++){
		if (a[i]!=b[i]){
			rs=false;
			break;
		}
	}
	return rs;
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
	int numinb[l];
	adtb=new string[l];
	for (int i=0; i< l; i++){
		adtb[i]=dtb(i);
		numinb[i]=num1s(adtb[i]);
	}
	// print (adtb);
	fv=new string[m];
	for (int i=0; i<m; i++){
		cin >> fv[i];
	}
	int n1[m];
	int n2[m];
	int n3[m];
	int e[m],f[m],g[m],h[m];
	for (int i=0; i<m; i++){
		n1[i]=num1(i);
		n2[i]=numatp2(i);
		n3[i]=nbat2(i);
		e[i]=0;
        f[i]=0;
        g[i]=0;
        h[i]=0;
		for(int j=1;j<fv[i].size();j*=2){
            for(int k=j*2;j+k<fv[i].size();k*=2){
                if(fv[i][j+k]=='1') e[i]++;
                if(fv[i][fv[i].size()-1-j-k]=='1') f[i]++;
            }
        }
        for(int j=1;j<fv[i].size();j*=2){
            for(int k=j*2;j+k<fv[i].size();k*=2){
                for(int l=k*2;j+k+l<fv[i].size();l*=2){
                    if(fv[i][j+k+l]=='1') g[i]++;
                    if(fv[i][fv[i].size()-1-j-k-l]=='1') h[i]++;
                }
            }
        }
	}
	// vector <vector<int>> ind;
	// for (int i=0; i<m; i++){
	// 	vector<int> temp;
	// 	for (int j=0; j<l; j++){
	// 		if (fv[i][j]==1)
	// 			temp.push_back(j);

	// 	}
	// 	vector<int> temp1(n,0);
	// 	for (int i=0; i<temp.size(); i++){
	// 		temp1[numinb[i]]++;
	// 	}

	// 	ind.push_back(temp1);
	// }

	



	int rs=m;
	bool visit[m];

	for (int i=0; i<m-1; i++){
		if (!visit[i]){
			// cout << "parent = " << i << endl;
			int trs=0;
			for (int j=i+1; j<m; j++){
				if (!visit[j] && n1[i]==n1[j] && n2[i]==n2[j] && fv[i][0]==fv[j][0] && fv[i][l-1]==fv[j][l-1] && n3[i]==n3[j] && e[i]==e[j] && f[i]==f[j] && g[i]==g[j] && h[i]==h[j]) {
					if (combinations(fv[i],fv[j])){
						trs++;
						visit[j]=true;
						// cout << "child = " << j;
					
					}
					
				}
			}
			rs=rs-trs;

			visit[i]=true;	
			// cout << endl;
		}
		
	}

	cout<<rs<< endl;
	// print (visit);

	





}