#include <bits/stdc++.h>
using namespace std;
float ptg(int e, int w){
    float e1=e*1.0;
    float w1=w*1.0;
    return (e1/(e1+w1))*100;
}
int minStep(float k){
    int step=0;
    int e=0;
    int w=0;
    e++;
    step++;
    float p=ptg(e,w);
    while(p!=k){
        // cout << p << "\n";
        if (p<k){
            e++;
            step++;
            p=ptg(e,w);
        }
        else {
            w++;
            step++;
            p=ptg(e,w);
        }
    }
    return step;
}
int gcd (int a, int b){
    int d1=min(a,b);
    int d2=max(a,b);
    if (d2%d1==0){
        return d1;
    }
    return gcd(d2%d1,d1);
}
int mins(int k){
    if (k==100){
        return 1;
    }
    else if (k==0){
        return 1;
    }
    int hcf=gcd(k,100-k);
    return k/hcf +(100-k)/hcf;
}
int main () {
    int t;
    cin >> t;
    float k;
    for (int i=0; i<t; i++){
        cin>> k;
        // cout << minStep(k) << "\n";
        cout << mins(k) << "\n";

    }
}