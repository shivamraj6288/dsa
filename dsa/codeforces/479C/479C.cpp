#include <bits/stdc++.h> 
using namespace std;
// void print(vector<vector<int>>a){
    // for (int i=0; i<a.size(); i++){
        // cout << a[i][0] << " " << a[i][1] << endl;
    // }
// }
vector<vector<int>> merge(vector<vector<int>> &a,vector<vector<int>> &b){
    // cout << a.size() << " " << b.size() << endl;
    vector<vector<int>>rs;
    int i=0, j=0; 
    while (i<a.size() && j<b.size()){
        if (a[i][0]<b[j][0]){
            rs.push_back(a[i]);
            i++;
        }
        else if (a[i][0]==b[j][0]){
            if (a[i][1]<=b[j][1]){
                rs.push_back(a[i]);
                i++;
            }
            else {
                rs.push_back(b[j]);
                j++;
            }
        }
        else {
            rs.push_back(b[j]);
            j++;
        }
    }
    for (i; i< a.size(); i++){
        rs.push_back(a[i]);
    }
    for (j; j<b.size(); j++){
        rs.push_back(b[j]);
    }
    // cout << a.size() << " " << b.size() <<" " << "done\n" ;
    return rs;
}

vector<vector<int>> merge_sort(vector<vector<int>> &a){
    int n=a.size();
    // cout << n<< "\n";
    if (n==1|| n==0){
        // cout << n << " done \n";
        return a;
    }
    if (n==2){
        vector<vector<int>> rs;
        if (a[0][0]<a[1][0]){
            rs.push_back(a[0]);
            rs.push_back(a[1]);
            
        }
        else {
            rs.push_back(a[1]);
            rs.push_back(a[0]);
            
        }
        // cout << n << " done \n";
        return rs;
    }
    vector<vector<int>> mid1;
    vector<vector<int>> mid2;

    for (int i=0; i<n/2; i++){
        mid1.push_back(a[i]);
    }
    for (int i=n/2; i<n; i++){
        mid2.push_back(a[i]);
    }
    mid1=merge_sort(mid1);
    mid2=merge_sort(mid2);
    // cout << n << " done \n";
    return merge(mid1,mid2);
}

int main (){
    vector<vector<int>> a;
    int n;
    cin >> n;

    vector<int> t(2);
    for (int i=0; i<n; i++){
        cin>> t[0];
        cin >> t[1];

        a.push_back(t);
    }
    // cout << "============\n";
    // print (a);
    // cout << "============\n";
    a=merge_sort(a);
    // cout << "============\n";
    // print (a);
    int day=0;
    for (int i=0; i<n; i++){
        if (day<=a[i][1]){
            day=a[i][1];
        }
        else {
            day=a[i][0];
        
        }

    }
    cout << day;
    return 0;
    
}

// 01010101
//     111  
100=>
00001000000

111=-4+2+1=-1
4=100
011+1
100