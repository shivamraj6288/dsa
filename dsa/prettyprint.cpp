#include<bits/stdc++.h>
using namespace std;
void fn(vector<int> &a, int k){
    for (int i = 0; i < a.size(); i++){
        if (a[a.size()/2 -i]==k){
            a[a.size() / 2 - i] = k + 1;
            a[a.size() / 2 + i] = k + 1;
        }
        else {
            break;
        }
    }
}

vector<vector<int>> prettyPrint(int n)
{
    int l = 2 * n - 1;
    vector<vector<int>> rs(l);
    vector<int> tp;

    for (int i = n; i >= 1;i--)
        tp.push_back(i);
    for (int i = 2; i <= n;i++)
        tp.push_back(i);
    
    for (int i = 0; i <n;i++){
        fn(tp, i);
        rs[l / 2 - i] = tp;
        rs[l / 2 + i] = tp;

    }
    return rs;
}
int main (){
    int n;
    cin >> n;
    vector<vector<int>> ab = prettyPrint(n);
    for (int i = 0; i < ab.size(); i++){
        for (int j = 0; j < ab[i].size(); j++){
            cout << ab[i][j] << " ";
        }
        cout << endl;
    }
}
