#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	int rs[T];
	for (int t=0; t<T; t++ ){
	    string s;
	    cin >> s;
	    int n=s.length();
	    int len[n];
	    len[0]=0;
	    
	    for (int i=1; i<n; i++){
	    	// cout << i << endl;
	    	bool check=false;
	        if (s[i]==s[len[i-1]]) {
	        	len[i]=len[i-1]+1;
	        	check=true;
	        }
	        else {
	        	// cout << "che in" << endl;
	            for (int k=i-len[i-1]+1; k<i; k++){
	            	// cout << "ch 2  " << k << endl;
	                if (s[0]==s[k]){
	                	int insl;
	                    for (insl=1; insl <= i-k; insl++){
	                    	if (s[insl]!=s[insl+k]) break;
	                    }
	                    if (k+insl==i) {
	                    	len[i]=insl+1; 
	                    	check=true;

	                    }
	                }
	            }

	            
	        }
	        if (!check) len[i]=0;

	        // cout << len[i] << endl;
	        
	    }
	    
	    rs[t]=len[n-1];
	}
	
	for (int i=0; i<T;i++){
	    cout << rs[i]<< endl;
	}
	return 0;
}