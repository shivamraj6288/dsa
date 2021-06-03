#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,t;
    cin >> n >> t;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int s=0;
    int ms=0;
    int sid=0;
    int pms=0;
    for (int i=0; i<n; i++){
        s=s+a[i];
        if(s<=t){
            ms++;
            pms=max(pms,ms);
            continue;
        } 
        else {
            while (s>t){
                s-=a[sid];
                sid++;
                
            }
            ms=i-sid+1;
            pms=max(ms,pms);
            // s=s-a[sid];
            // if (s<=t){
            //     sid++;
            //     continue;
            // }
            // else {
            //     pms=max(pms,ms);
            //     s=0;
            //     sid=i+1;
            //     ms=0;
            // }
        }
    }
    // cout << sid << "\n";
    // cout << pms << "\n";
    // cout << ms << "\n";
    cout << max(ms,pms);
}