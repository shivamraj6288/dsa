#include <bits/stdc++.h>
using namespace std;

int min(map<string, int> m){
	int rs=0;
	map<string, int>::iterator itr;
	itr=m.begin();
	rs=itr->second;
	for (itr=m.begin(); itr!=m.end(); itr++){
		if (itr->second < rs)
			rs=itr->second;
	}

	return rs;
}
int minValueIndexVec(vector<int>a){
	int l=a.size();
	int rs=a[1];
	int index=1;
	for (int i=1; i<l; i++){
		// cout << i << "\t" << a[i] << endl;
		if (a[i]<rs){
			rs=a[i];
			index=i;
		}
	}
	return index;
}

int maxVecValue(vector<int> v){
    int max=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]>max) max=v[i];
    }
    return max;
}
char max(map<char, int> m){
	int rs=0;
	char rv;
	map<char, int>::iterator itr;
	itr=m.begin();
	rs=itr->second;
	rv=itr->first;
	for (itr=m.begin(); itr!=m.end(); itr++){
		if (itr->second > rs){
			rs=itr->second;
			rv=itr->first;
		}

	}

	return rv;
}

int maxValue(map<char, int>m){
	int rs=0;
	map<char, int>::iterator itr;
	itr=m.begin();
	rs=itr->second;
	for (itr=m.begin(); itr!=m.end(); itr++){
		if (itr->second > rs)
			rs=itr->second;
	}

	return rs;
}

char maxChar(string a){
	int n=a.length();

	map <char, int> count;

	for (int i=0; i<n; i++){
		count[a[i]]++;

	}

	return max(count);
}

int maxCharCount(string a){
	int n=a.length();

	map <char, int> count;

	for (int i=0; i<n; i++){
		count[a[i]]++;

	}

	return maxValue(count);
}

// int* arrayForm()



int function1(string a, int k){
	int l=a.length();
	int ss= l/k;
	string store[ss];

	for (int i=0; i<l; i=i+ss){
		string index=a.substr(i,ss);

		for (int j=0;j<index.length(); j++){
			store[j]+=index[j];
		}

		// fq[index]=0;
		// fq[index]=false;
		// ap[index]++;
	}

	int firstAns=0;

	for (int i=0; i<ss; i++){
		firstAns+=store[i].length()-maxCharCount(store[i]);
	}

	return firstAns;
}

int main () {
	// map <string, int> fq;
	// map <string, int> ap;
	// map <string, bool> fc;
	// fq["abc"]=1;
	// fq["abd"]=2;
	// cout << fq.count("abc")<< endl;
	// cout << fq.begin() << endl << fq.end() << endl;
	// cout << fq.find("ab")==fq.end() << endl;
	string a;
	cin >>a;
	int k;
	cin >>k;
	int l=a.length();
	int ss= l/k;

	cout << function1(a,k) << endl;

	int num_oper;
	int num_oper_min=(l+1)/2,k_min=2;
    for(int sb=(3*l)/4;sb>0;sb--){
        num_oper=0;
        for(int i=0;i<sb;i++){
            vector<int> v(26,0);
            for(int j=i;j<l;j+=sb){
                v[a[j]-97]++;
            }
            num_oper+=maxVecValue(v);
        }
        k=l/sb;
        if(l%sb!=0) k++;
        num_oper=(k*sb)-num_oper;
        if(num_oper<num_oper_min){
            num_oper_min=num_oper;
            k_min=k;
        }
    }
    cout<<num_oper_min<<" "<<k_min<<"\n";



	// int finalLength;

	// vector <int> op(((3*l)/4)+2,0);

	// for (int tss=1; tss<=((3*l)/4)+1; tss++){
	// 	string tstore[tss];
	// 	string ta=a;

	// 	for (int i=0; i<l; i=i+tss){
	// 		string index=a.substr(i,tss);
	// 		for (int j=0; j<index.length(); j++){
	// 			tstore[j]+=index[j];
	// 		}
	// 	}

	// 	int rem=l%tss;
	// 	int toAdd=tss-rem;
	// 	op[tss]=op[tss]+toAdd;

	// 	int tk=(l+toAdd)/tss;

	// 	// for (int i=rem; i<tss && rem>0 ; i++){
	// 	// 	ta=ta+maxChar(tstore[i]);
	// 	// }

	// 	// int tk=ta.length()/tss;

	// 	op[tss]=op[tss]+function1(ta,tk);




	// }

	// int bsize=minValueIndexVec(op);

	// int rem=l%bsize;
	// int toAdd=bsize-rem;
	// int finalk=(l+toAdd)/bsize;

	// cout << op[bsize] << " " <<finalk;

	// for (int i=2; i<=l; i++){
	// 	string ta=a;
		
	// 	int rem=l%i;
	// 	int toAdd=i-rem;

	// 	int tss=(l+rem)/i;

	// 	op[i]+=toAdd;
	// 	string tstore[tss];

	// 	for (int j=0; j<l; j=j+tss){
	// 		string index=a.substr(j,tss);

	// 		for (int x=0;x<tss; x++){
	// 			tstore[x]+=index[x];
	// 		}

	// 		// fq[index]=0;
	// 		// fq[index]=false;
	// 		// ap[index]++;
	// 	}

	// 	if (rem!=0){
	// 		// cout << "rem != 0" << endl;
	// 		int lastInd=l%tss;
	// 		for (int j=0; j<toAdd; j++){

	// 			// cout << maxChar(tstore[(lastInd+j)%tss])<< endl << "check";
	// 			ta=ta+maxChar(tstore[(lastInd+j)%tss]);
	// 		}

	// 		// cout << ta << endl;
	// 	}

		


	// 	op[i]+=function1(ta,i);

	// }

	// int mink= minValueIndexVec(op);

	// cout << op[mink] << " " << mink;


	

	// cout << endl;


	// // cout << endl << store[0] << endl << store[1] << endl;

	// // fir (int i=0; )

	// map < string, int>::iterator itr;

	// // for (itr=f.begin(); itr)

	// for (itr=fq.begin(); itr!=fq.end(); itr++){

	// 	string cr=itr->first;
	// 	if (!fc[cr]){
	// 		map <string, int>::iterator temp;
	// 		temp=itr;
	// 		temp++;

	// 		for (temp; temp!= fq.end(); temp++){
	// 			string tcr=temp->first;

	// 			for (int i=0; i<ss; i++){
	// 				if (cr[i]!=tcr[i]){
	// 					fq[cr]+=ap[tcr];
	// 					fq[tcr]+=ap[cr];

	// 					// cout << cr << "\t" << fq[cr] << endl;
	// 					// cout << tcr << "\t" << fq[tcr] << endl;
	// 				}

	// 			}
	// 		}

	// 		fc[cr]=true;

	// 	}

		
	// }

	// cout << min(fq);





}