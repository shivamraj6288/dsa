#include <bits/stdc++.h>
using namespace std;

string finds(int n, int r, int m){
	vector <int> city[n+1];
	bool pr[n+1];
	for (int i=0; i<(n+1); i++){
		pr[i]=false;
	}
	string value="na";

	for (int rr=1; rr<r+1; rr++){
		int c1, c2;
		cin >> c1 >> c2;
		city[c1].push_back(c2);
		city[c2].push_back(c1);
	}

	for (int mm=1; mm<m+1; mm++){
		int c, s;
		cin >> c >> s;
		if (pr[c]){
			value= "No";
		}
		else {
			pr[c]=true;
		}
		queue <int> origins;
		origins.push(c);
		int ss=0;
		int father[n];
		father[c]=-1;
		while (!origins.empty() && ss<s){
			vector <int> sources;
			while (!origins.empty()) {
				sources.push_back(origins.front());
				origins.pop();
			}
			ss++;

			for (int source : sources){
				for (int cities : city[source] ){
					cout << cities << endl;
					if (cities==father[source]){
						continue;
						cout << "father"<< endl;
					}
					else if (pr[cities]){
						cout << endl << "current "<< cities << "\t source " << source << endl;
						value= "No";
						cout << "already accesse";
					}

					else{
						pr[cities]=true;
						cout << "checkpoint assigned"<< endl;
						cout << "status of " << cities <<"\t" <<  pr[cities]<< endl;
						father[cities]=source;
						if (ss<(s+1)){
							origins.push(cities);
						}
					}
				}
			}

		}
		
	}

	for (int nn=1; nn<n+1; nn++){
		cout<< nn << "\t" << pr[nn]<< endl;
		if (!pr[nn]){
			return "No";
		}
	}
	if (value=="na"){
		value="Yes";
	}

	return value;

}

int main(int argc, char *argv[]){

	int T;
	cin >> T;
	string results[T];
	for (int t=0;t<T; t++){
		int n,r,m;
		cin >> n >> r >> m;
		results[t]= finds(n,r,m);


	}

	for (int t=0 ; t<T; t++){
		cout << results[t]<< endl;
	}
}