#include <bits/stdc++.h>
using namespace std;
int sqrt(int A ) {
    if(A==1 || A==0)
        return A;
    int a0 = A;
    int l=A/2;
    while(true){
        
        cout << l << " " << A<< endl;
        int k0 = l * l;
        int k2=(l+1)*(l+1);
        if(k0==a0){
            return l;
        }
        if(k0<a0 && k2>a0){
            return l;
        }
        if (k0< a0 && k2 <= a0){
            l = (l + A) / 2;
            // continue;
        }
        // 
        else if(k0>a0){
            l = l / 2;
            A = A / 2;
        }

        if (A<=0 || l<=0){
            break;
        }
    }
    return A;
}

int main(){
    int n;
    cin >> n;
    cout << sqrt(n);
}