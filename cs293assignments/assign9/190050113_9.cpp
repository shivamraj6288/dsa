#include <bits/stdc++.h>
using namespace std ;

class T {
public:
	int index;
	int n1;
	int n2;

	T(int id, int num1, int num2){
		index=id; 
		n1=num1;
		n2=num2;
	}
};
struct compare1 {
	bool operator() (T const &t1, T const &t2) {
		return (t1.n1 <= t2.n1);
	}
};

struct compare2 {
	bool operator() (T const &t1, T const &t2) {
		return (t1.n2<=t2.n2);
	}
};

bool comp2 (T t1, T t2){
	return (t1.n2<=t2.n2);
}	

int findlmin(int a, vector<T> s){

	for (int i=s.size()-1; i>=0 ; --i){
		if (s[i].n2<=a){
			return i;
		}
	}

	return -1;
}

// int findlmax (int a, vector<T>s){
// 	for (int i=0; i<s.size())
// }

int main () {
	int n;
	cin >>n;
	int a[n], b[n], c[n], d[n];
	bool possible=true;
	vector <int> rsp;
	vector <int> rsq;
	for (int i=0; i< n; i++){
		cin >> a[i];
	}
	for (int i=0; i< n; i++){
		cin >> b[i];
	}
	for (int i=0; i< n; i++){
		cin >> c[i];
	}
	for (int i=0; i< n; i++){
		cin >> d[i];
	}

	vector <T> s1;
	vector <T> s2;

	// cout << "values accepted" << endl;

	for (int i=1; i<=n; i++){
		T temp(i, a[i-1], b[i-1]);
		s1.push_back(temp);

		T temp1(i, c[i-1], d[i-1]);
		s2.push_back(temp1);
	}

	// cout << "s1 and s2 created \n";

	sort (s1.begin(), s1.end(), compare1());
	sort (s2.begin(), s2.end(), compare1());

	// for (int i=0; i<n; i++){
	// 	cout << "("<<s1[i].n1<<","<<s1[i].n2<<") , ";
	// }
	// cout << "\n";
	// for (int i=0; i<n; i++){
	// 	cout << "("<<s2[i].n1<<","<<s2[i].n2<<") , ";
	// }
	// cout << "\n";
	// cout << "s1.size() = " << s1.size() << endl;
	// cout << "s2.size() = " << s2.size() << endl;
	vector <T> ta;
	vector <T> tc;

	while (!s1.empty() || !ta.empty()){
		// cout << "initial : size of s1, ta, s2, tc :" << s1.size()<< " " << ta.size()<< " " << s2.size()<< " " << tc.size() << " "<< endl;
		if (ta.empty()){
			int a0=s1[0].n1;
			ta.push_back(s1[0]);
			s1.erase(s1.begin());
			while (true && !s1.empty()){
				if (s1[0].n1==a0){
					ta.push_back(s1[0]);
					s1.erase(s1.begin());
				}
				else {
					break;
				}
			}

			sort(ta.begin(), ta.end(),compare2());
			// cout << "ta created \n";
		}

		if (tc.empty()){
			int c0=s2[0].n1;
			tc.push_back(s2[0]);
			s2.erase(s2.begin());
			while (true && !s2.empty()){
				if (s2[0].n1==c0){
					tc.push_back(s2[0]);
					s2.erase(s2.begin());
				}
				else {
					break;
				}
			}

			sort(tc.begin(),tc.end(),compare2());
			// cout << "tc creatdx \n";

		}
		// cout << "size of s1, ta, s2, tc : " << s1.size() << ","<< ta.size() << ","<< s2.size() << ","<< tc.size()<< "," << endl;

		if (ta.size()<=tc.size()){
			while(!ta.empty()){
				if (ta[0].n2<tc[0].n2){
					possible=false;
					break;

				}
				else {
					int rindex=findlmin(ta[0].n2,tc);
					// if (rindex==-1){
					// 	cout << "-1 error of findlmin \n";
					// }
					rsp.push_back(ta[0].index);
					ta.erase(ta.begin());
					rsq.push_back(tc[rindex].index);
					tc.erase(tc.begin()+rindex);

				}
			}

			if (!possible){
				break;
			}
		}

		else {
			while(!tc.empty()){
				if (tc[0].n2>ta[ta.size()-1].n2){
					possible=false;
					break;
				}
				else {
					vector<T>::iterator l1;
					l1=lower_bound(ta.begin(),ta.end(),tc[0],comp2);
					rsp.push_back(ta[l1-ta.begin()].index);
					ta.erase(l1);
					rsq.push_back(tc[0].index);
					tc.erase(tc.begin());
				}
			}

			if(!possible){
				break;
			}


		}


	}

	if (!possible){
		cout << "impossible\n";
	}
	else {
		for (int i=0; i<n; i++){
			cout << rsp[i] << " ";

		}
		cout << endl;
		for (int i=0; i<n; i++){
			cout << rsq[i]<< " ";
		}
		cout << endl;
	}
}