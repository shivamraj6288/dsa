#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--){
        int a,b,c,d,k;
        cin >> a >> b >> c>> d>>k;

        int mink=abs(a-c)+abs(b-d);
        if (mink>k){
            cout << "NO\n";
        }
        else if ((k-mink)%2==0){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}