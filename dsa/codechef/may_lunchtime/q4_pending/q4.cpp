#include <bits/stdc++.h>
using namespace std;


int main () {
    int T;
    cin >> T;

    while (T--){
        int N; int K; 
        cin >> N >> K;
        string a;
        cin >> a;
        int l=0;
        for (int i=1; i<N; i++){
            if (a[i]==a[i-1]){
                l+=2;;
            }
            else {
                l+=1;
            }
        }
        int cq;
        if (N==1){
            while (K--){
                cout << "0\n";
            }
            continue;
        }
        
        while (K--){
           
            
            
            cin >> cq;
            --cq;
            // cout << "cq " << cq << endl;
            if (cq==0){
                if (a[cq]==a[cq+1]){
                    l=l-1;
                }
                else {
                    ++l;
                }
                // cout << "l1 " << l<< endl;
            }
            
            else if (cq==N-1){
                if (a[cq]==a[cq-1]){
                    --l;
                }
                else {
                    ++l;
                }
            }
            else {
                if (a[cq]==a[cq+1]){
                    --l;
                }
                else {
                    ++l;
                }
                if (a[cq]==a[cq-1]){
                    --l;
                }
                else {
                    ++l;
                }
                
            }
            cout << l << "\n";
            if (a[cq]=='1'){
                a[cq]='0';
            }
            else {
                a[cq]='1';
            }
            // cout << a << endl;
            
            
        }
    }
}