#include <bits/stdc++.h>
using namespace std;

long long int mcost(int n, int k, vector<int> a){
    sort(a.begin(), a.end(), greater<int>());
    long long int sum0,sum1;
    sum0=0;
    sum1=0;
    for (int i=0; i<2*k; i++){
        if (i%2==0){
            sum0+=a[i];
        }
        else {
            sum1+=a[i];
        }
    }
    sum1+=a[2*k];
    return max(sum0, sum1);
}
 

int main () {
    int T;
    cin >> T;
    while (T--){
        int N,K;
        cin >> N >> K;
        vector <int> a(N);
        for (int i=0; i<N; i++){
            cin >> a[i];
        }
        cout << mcost(N,K,a) << "\n";
    }
}