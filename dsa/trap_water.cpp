#include <bits/stdc++.h>
using namespace std;
void print (vector<int> &v){
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}
int first_id(vector<int> &v){
    int n=v.size();
    // int t=0;
    int cm =v[0];
    for (int i=1; i<n; i++){
        if (v[i]<cm){
            return --i;
        }
        else {
            cm=v[i];
        }
    }
    return n-1;
}
int last_id(vector<int>&v){
    int n=v.size();
    int cm=v[n-1];
    for (int i=n-2; i>=0;i--){
        if (v[i]<cm){
            return ++i;
        }
        else {
            cm=v[i];
        }
    }
    return n-1;
}
vector<int> evl(vector<int> &v, int c){
    int n=v.size();
    int fid=first_id(v);
    int lid=last_id(v);
    // cout << fid<< " " << lid << endl;
    if (c==0){
        vector<int>t(n,0);
        for (int i=fid+1;i<lid;i++){
            t[i]=v[i-1]-v[i];
        }
        vector<int>rs(n,0);
        // rs[0]=t[0];
        for (int i=fid+1;i<lid;i++){
            rs[i]=t[i]+rs[i-1];
            if (rs[i]<0){
                rs[i]=0;
            }
        }
        return rs;

    }
    else {
        vector<int> t(n,0);
        for (int i=lid-1;i>fid; i--){
            t[i]=v[i+1]-v[i];
        }
        vector<int>rs(n,0);
        for (int i=lid-1;i>fid; i--){
            rs[i]=t[i]+rs[i+1];
            if (rs[i]<0){
                rs[i]=0;
            }
        }
        return rs;
    }
}
vector<int> comp(vector<int>&v1,vector<int>&v2){
    int n=v1.size();
    vector<int> rs(n,0);
    for (int i=0; i<n; i++){
        rs[i]=min(v1[i],v2[i]);
    }
    return rs;
}
int trap(vector<int>& height) {

    int n=height.size();
    if (n<=1){
        return 0;
    }
    vector<int> rs;
    vector<int>s1=evl(height,0);
    // print (s1);
    vector<int>s2=evl(height,1);
    // print (s2);
    rs=comp(s1,s2);
    // print (rs);
    int vol=0;
    for (int i=0; i<n; i++){
        vol+=rs[i];
    }
    return vol;
}
int main(){
    int n;
    cin>> n;
    vector<int> height(n);
    for (int i=0; i<n; i++){
        cin>> height[i];
    }
    cout << trap(height);
    return 0;

}