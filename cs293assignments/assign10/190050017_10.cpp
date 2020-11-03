#include <iostream>
#include <algorithm>
using namespace std;

bool combinations(int n, string s1, string s2){

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

int main(){
	int n,m; cin>>n>>m;
    string arr[m];
    int a[m];
    int c[m],d[m],e[m],f[m],g[m],h[m];
    bool b[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
        a[i]=0;
        c[i]=0;
        d[i]=0;
        e[i]=0;
        f[i]=0;
        g[i]=0;
        h[i]=0;
        b[i]=false;
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]=='1') a[i]++;
        }
        for(int j=1;j<arr[i].size();j*=2){
            if(arr[i][j]=='1') c[i]++;
            if(arr[i][arr[i].size()-1-j]=='1') d[i]++;
        }
        for(int j=1;j<arr[i].size();j*=2){
            for(int k=j*2;j+k<arr[i].size();k*=2){
                if(arr[i][j+k]=='1') e[i]++;
                if(arr[i][arr[i].size()-1-j-k]=='1') f[i]++;
            }
        }
        for(int j=1;j<arr[i].size();j*=2){
            for(int k=j*2;j+k<arr[i].size();k*=2){
                for(int l=k*2;j+k+l<arr[i].size();l*=2){
                    if(arr[i][j+k+l]=='1') g[i]++;
                    if(arr[i][arr[i].size()-1-j-k-l]=='1') h[i]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        if(!b[i]){
            b[i]=true;
            ans++;
            for(int j=i+1;j<m;j++){
                if(a[i]==a[j] && c[i]==c[j] && d[i]==d[j] && e[i]==e[j] && f[i]==f[j] && g[i]==g[j] && h[i]==h[j]){
                    if(combinations(n,arr[i],arr[j])) b[j]=true;
                }
            }
        }
    }
    cout<<ans<<"\n";
	return 0;
}