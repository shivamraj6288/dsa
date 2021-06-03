#include <bits/stdc++.h>
using namespace std;

int  peak(vector<int> &A,int s, int e){
    int id=s+(e-s)/2;
    if(id==0 || id==A.size()-1){
        return id;
    }
    bool b1=A[id]>A[id-1];
    bool b2=A[id]>A[id+1];
    if (b1 && b2){
        return id;
    }
    if (!b1){
        return peak(A,s,id-1);
    }
    if(!b2){
        return peak(A,id+1,e);
    }
    return 1;
}
int solveh1(vector<int> &a, int B, int s,int e){
    // cout << " h1 Enter \n" << s << endl << e;
    int id = s + (e - s) / 2;
    if(s==e){
        if(a[s]!=B){
            return -1;
        }
        return s;
    }
    
    // if (s>e){
    //     return -1;
    // }
    if (a[id]==B){
        return id;
    }
    if (a[id]<B){
        return solveh1(a, B, id+1, e);
    }
    else {
        return solveh1(a, B, s, id - 1);
    }
    return -1;
}
int solveh2(vector<int>&a, int B, int s, int e){
    // cout << "h2 ente r\n";
    int id = s + (e - s) / 2;
    if(s==e){
        if(a[s]!=B){
            return -1;
        }
        else {
            return s;
        }
    }
    if(a[id]==B){
        return id;
    }
    if (a[id]<B){
        return solveh2(a, B, s, id - 1);

    }
    else {
        return solveh2(a, B, id+1 , e);
    }
    return -1;
}
int solve(vector<int> &A, int B) {
    int pk = peak(A,0,A.size()-1);
    int rs = solveh1(A, B, 0, pk);
    // cout << "h1 exit \n";
    if (rs != -1)
        return rs;
    return (solveh2(A, B, pk + 1, A.size() - 1));
}
int main(){
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    int B;
    cin >> B;
    // cout << a[peak(a, 0, n - 1)] << endl;
    cout << solve(a, B) << endl;
}