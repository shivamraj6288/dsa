#include <bits/stdc++.h>
using namespace std ;


int main() {
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> edges(n);
	for (int i=0; i<m; i++){
		int a,b;
		cin >> a>>b;
		edges[a].insert(b);
		edges[b].insert(a);
	}

	for (int i=0; i<n; i++){
		// cout << edges[i].size() << endl;

	}
	// cout << "================\n";

	queue<int> dg1;

	for (int i=0; i<n; i++){
		if (edges[i].size()==1){
			dg1.push(i);
		}
	
	}

	while (!dg1.empty()){
		int a =dg1.front();
		dg1.pop();
		int b=*edges[a].begin();
		edges[a].erase(edges[a].begin());
		edges[b].erase(a);
		if (edges[b].size()==1){
			dg1.push(b);
		}
	}
	// cout << "degree 1 deleted \n";
	for (int i=0; i<n; i++){
		if (edges[i].size()==2)
			dg1.push(i);
	}
	// cout << "degree 2 collected \n";

	while (!dg1.empty()){
		int a =dg1.front();
		dg1.pop();
		if (edges[a].size()==2){
			int b=*edges[a].begin();
		edges[a].erase(edges[a].begin());
			// cout << a<<"=b deletd\n";
			int c=*edges[a].begin();
			edges[a].erase(edges[a].begin());
			// cout <<a << "=c deleted\n ";
			edges[b].erase(a);
			if (edges[b].size()==2)
				dg1.push(b);
			edges[c].erase(a);
			if (edges[c].size()==2)
				dg1.push(c);
		}
		

	}
	// cout << "degree 2 done \n";

	bool check=true;
	for (int i=0; i<n; i++){
		// cout << edges[i].size() << endl;
		if (edges[i].size()>2){
			check=false;
			break;
		}
	}

	if(check)
		cout << "yes\n";
	else 
		cout << "no\n";

}