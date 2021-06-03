#include <bits/stdc++.h>
using namespace std;
// vector <int>dp;
// int sd (int n, int m){
//     cout << n << " " <<m<< endl;
//     if (dp[n]!=-1){
//         return dp[n];
//     }
//     if (n>m){
//         dp[n]=n-m;
//         return dp[n];
//     }
//     if (n==1){
//         int step=(int)(log(10)/log(2));
//         step=step+(m-pow(2,step));
//         dp[n]=step;
//         return dp[n];

//     }
//     else {
//         dp[n]= 1+(min(sd(n-1,m),sd(2*n,m)));    
//         return dp[n];
//     }
// }
int main(){
    int n,m;
    cin >>n >>m;
    // for (int i=0; i<2*max(n,m); i++){
    //     dp.push_back(-1);
    // }
    if (n>=m){
        cout << n-m;
        return 0;
    }
    // int t;
    int step=0;
    while (n!=m){
        if (m<n){
            m++;
            step++;
            continue;
        }
        if (m%2==0){
            m=m/2;
            step++;
        }
        else {
            m++;
            step++;
        }
        // cout << m << endl;
        // t=2*n;
        // if (t<=m){
        //     n=t;
        //     step++;
        // }
        // else if (t-m==1){
        //     n=t-1;
        //     step+=2;
        // }
        // else {
        //     step++;
        //     n--;

        // }
    }
    // cout << "==\n";
    cout  <<step;



}