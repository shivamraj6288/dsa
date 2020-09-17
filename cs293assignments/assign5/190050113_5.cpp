#include <bits/stdc++.h>
using namespace std;
// int num (vector <int> s){
// 	int rs=0;
// 	for (int i=0; i< s.size(); i++){
// 		rs=rs+pow(2,s[i]);
// 	}

// 	return rs;
// }

// vector<vector<int>> nos(vector<int> s){
// 	int n=s.size();
// 	vector <vector<int>> temp;
// 	vector <vector<int>> ls(pow(2,n));

// 	vector <int> t(0);
// 	temp.push_back(t);
// 	ls[0]=t;
// 	cout << "ls[0] assigned" << endl;

// 	for (int i=0; i<n; i++){
// 		cout << i<<" loop entered" << endl;
// 		int tn=temp.size();
// 		for (int j=0; j<tn; j++){
// 			cout << j << " inner loop entered" << endl;
// 			temp.push_back(temp[j]);
// 			temp[temp.size()-1].push_back(s[i]);
// 			ls [num(temp[temp.size()-1])]=temp[temp.size()-1];
// 		}


// 	}

// 	return ls;
// }

// vector <vector<int>> asub (vector <int> s){
// 	int n=s.size();
// 	vector <vector<int>> temp (pow(2,n));

// 	vector <int> t(0);
// 	temp.push_back(t);

// 	for (int i=0; i<n; i++){
// 		int tn=temp.size();
// 		for (int j=0; j<tn; j++){
// 			temp.push_back(temp[j]);
// 			temp[temp.size()-1].push_back(s[i]);
// 		}


// 	}

// 	return temp;

// }

// vector <int> sqg(int n){
// 	vector <int> seq;
// 	for (int i=0; i<n; i++){
// 		seq.push_back(i);
// 		// cout << i << " ";
// 	}
// 	return seq;
// }

// int main (int argc, char *argv[]){
// 	int n;
// 	cin >> n;
// 	cout << n << endl;

// 	vector <int> f;
// 	int nmax=pow(2,n);
// 	for (int i=0; i<nmax; i++){
// 		int v;
// 		cin >> v;

// 		f.push_back(v);

// 		cout << f[i] << " ";
// 	}

// 	cout << endl;

// 	vector <int> seq = sqg(n);
// 	cout << "check" << endl;
// 	for (int i=0; i<n; i++){
// 		cout << seq[i] << " ";
// 	}

// 	cout << endl;
	
// 	vector<vector<int>> ls ;
// 	ls=nos(seq);

// 	for (int i=0; i<ls.size(); i++){
// 		for (int j=0; j<ls[i].size(); j++){
// 			cout << ls[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	vector <long long int> result;
// 	cout << "first part begin\n";

// 	for (int i=0; i<ls.size(); i++){
// 		cout << i<< endl;
// 		vector <vector<int>> subsets=asub(ls[i]);
// 		for (int i=0; i<subsets.size(); i++){
// 			for (int j=0; j<subsets[i].size(); j++){
// 				cout << subsets[i][j] << " bb";
// 			}
// 			cout << endl;
// 		}
// 		long long int trs=0;
// 		cout << subsets.size() << " is size\n";
// 		for (int j=0; j<subsets.size(); j++){
// 			// cout << subsets[j];
// 			trs+=f[num(subsets[j])];
// 		}

// 		cout << trs << endl << "====\n";

// 		result.push_back(trs);
// 	}

// 	// for (int i=0; i< result.size(); i++){
// 	// 	cout << result[i] << " ";
// 	// }

// 	cout << endl;





// } 

// int* p1 (int s[], int n){
// 	int *temp=new int[n/2];
// 	for (int i=0; i<n/2; i++){
// 		temp[i]=s[i];
// 	}

// 	return temp;
// }
// int* p2 (int s[], int n){
// 	int *temp=new int[n/2];
// 	for (int i=0; i<n/2; i++){
// 		temp[i]=s[i+n/2];
// 	}

// 	return temp;
// }

long long int ff(long long int* s,int n, int i){
	if (n==1){
		int rs=s[0];
		// delete[] s;
		return rs;
	}
	if (i>=n/2){
		return ff(s,n/2,i-n/2)+ff(s+n/2,n/2, i-n/2);
	}
	return ff(s,n/2,i);
	

}

int main (){
	int n;
	cin >>n;

	
	int nmax=pow(2,n);
	long long int *f=new long long int[nmax];
	for (int i=0; i< nmax; i++){
		cin >> f[i];
		// cout << ff(f,nmax,i)<< " ";
	}
	// for (int i=0; i<nmax; i++){
	// 	cout << f[i] << " ";
	// }
	// cout << endl
	// vector<long long int> fcap;
	long long int v;
	for(int i=0; i<nmax; i++){
		v= ff(f,nmax,i);
		// cout << ff(f,nmax,i)<< " ";
		cout << v<< " ";
	}

	cout << endl;

	// vector <int> res2;
	int check;
	for (int i=0; i<nmax; i++){
		
		cin >> check;

		if (check){
			long long int t=f[i];
			f[i]=0;
			f[i]=t-ff(f,nmax,i);
			cout << f[i] << " ";

		}

		else {
			cout << ff(f,nmax,i)<< " ";
		}

		
	}

	cout << endl;







}

