#include<bits/stdc++.h>
using namespace std;
// #define long long int long long int

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int t;
    cin>>t;


    vector<long long int> temporary(n-1,0);
    vector<vector<long long int>> r(n,temporary);
    for(int i=0;i<n-1;i++){
        r[1][i]=i+2;
    }
    for (int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            r[i][j]=((j+1)*r[i-1][j])+r[i-1][j+1];
        }
    }

    while(t--){
        char op;
        cin>>op;
        if(op=='R'){
            int p[n];
            for(int i=0;i<n;i++){
                cin>>p[i];
            }
            long long int ran=p[n-1];
            int max=p[0];
            for(int i=1;i<n-1;i++){
                ran+=(p[i]*r[n-i-1][max]);
                if(p[i]>max) max=p[i];
            }
            cout<<ran<<"\n";
        }
        else{
            long long int ran;cin>>ran;
            int p[n];
            p[0]=0;
            int max=0;
            for(int i=1;i<n-1;i++){
                int x=ran/r[n-i-1][max];
                if(x>max){
                    x=max+1;
                }
                p[i]=x;
                ran-=(x*r[n-i-1][max]);
                if(x>max){
                    max=x;
                }
            }
            p[n-1]=ran;
            for(int i=0;i<n;i++){
                cout<<p[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}