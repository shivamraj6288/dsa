#include <bits/stdc++.h>
using namespace std ;
int pid(vector<int> &a){
    for (int i=0; i<a.size(); i++){
        if (a[i]>0)
        return i;
    }
    return -1;
}

int maxs1(vector<int> &a){
    int si=pid(a);
    if (si==-1){
        // return *min_element(a.begin(), a.end());
        return 0;
    }
    int ls=0,cs=0;
    for (int i=si; i<a.size(); ++i){
        // cout << i << endl;
        if (a[i]>0){
            cs+=a[i];
        }
        else {
            ls=max(cs,ls);
            cs=0;
            
        }
    }
    ls=max(ls,cs);
    return ls;

}

int main () {
    int T;
    cin >> T;
    int N, K;
    int sum;
    while (T--) {
        cin >> N >> K;
        vector <int> a(N);
        sum=0;
        for (int i=0; i< N ; i++){
            cin >> a[i];
        }
        if (K==1){
            cout << maxs1(a) << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        int fp=pid(a);
        if (fp==-1){
            cout << 0 << "\n";
            continue;
        }
        if (N-fp >=K){
           for (int i=1; i<=K; i++){
               if (i==K){
                   int ts=0;
                   for (int j=fp+i-1; j<N; j++){
                       ts=ts+a[j];
                   }
                   sum=sum+(ts*i);
               }
               else{
                   sum=sum+(a[fp+i-1]*i);
               }
           }
           cout << sum;
           
        }
        else {
            int sp=fp-(K-(N-fp));
            int sum=0;
            for (int i=1; i<=K; i++){
               if (i==K){
                   int ts=0;
                   for (int j=sp+i-1; j<N; j++){
                       ts=ts+a[j];
                   }
                   sum=sum+(ts*i);
               }
               else{
                   sum=sum+(a[sp+i-1]*i);
               }
               
           }
           cout << sum;
        }

    }
}