#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> rs(vector<int> &a){
    int n = a.size();
    vector<int> output(n);
    int maxc[n];
    for (int i = 0; i < n;i++){
        maxc[i] = -1;
    }
    output[0] = 1;
    maxc[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i]<a[i-1]){
            output[i] = 1;
            maxc[i] = i - 1;
            continue;
        }
        int j = i - 1;
        int oj = i;
        while (a[j] <= a[i])
        {
            oj = j;
            j = maxc[j];
            if(j==-1){
                // oj = j;
                break;
            }
        }

        // cout << i << " " << j << "\n";

        maxc[i] = maxc[oj];

        output[i] = output[oj] + (i - oj);
    }
    
    return output;
}

int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++){
            cin >> a[i];
        }

        // display(a);

        vector<int> result;
        result = rs(a);

        // cout << result.size() << endl;
        display(result);
    }
}
