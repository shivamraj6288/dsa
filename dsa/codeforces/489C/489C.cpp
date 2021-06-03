#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, s;
    cin >> m >> s;
    if (m==1 && s==0){
        cout << "0 0";
        return 0;
    }
    if (s==0 || s> 9*m){
        cout << "-1 -1";
        return 0;
    }
    // cout << m << " " << s << endl;
    int rs1[m];
    int rs2[m];

    int s0=s;
    rs1[0]=1;
    for (int i=1; i<m; i++){
        rs1[i]=0;
    }
    s--;
    for (int i=m-1; i>=0; i--) {
        
       rs1[i]=rs1[i]+min(9,s);
       s=s-rs1[i];
        if (s<=0){
            break;
        }
            // break;

    }
    // cout << m << endl;

    for (int i=0; i<m; i++){
        cout << rs1[i];
    }
    // cout << "min\n";
    cout << " ";
    s=s0;
    for (int i=0; i<m; i++){
        if (s<=0){
            rs2[i]=0;
            continue;
        }
        rs2[i]=min(9,s);
        s=s-rs2[i];
        
    }
    for (int i=0; i<m; i++){
        cout << rs2[i];
    }
    // cout << endl;
    return 0;
    

}