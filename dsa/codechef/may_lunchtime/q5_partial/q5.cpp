#include <bits/stdc++.h>
using namespace std;

int fn(int &n){
    list<int> a;
    for (int i=2; i<=n; i++){
        a.push_back(i);
    }
    queue<int>q;
    // int i=0; 
    int count=0;
    while (!a.empty()){ 
        q.push(*a.begin());
        a.pop_front();
        // cout  <<"front " <<q.front() << endl;
        while (!q.empty()){
            int cs=q.front();
            // cout  <<"front " <<cs << endl;
            q.pop();
            list<int> :: iterator it ;
            // list<int> :: iterator endit ;
            list<int> :: iterator tempit;
            // for (it =b.begin(); it!=a.end(); it++){
            //     cout << "current it " << *it << endl;
            //     if (max(*it,cs)%min(*it,cs)==0){
            //         q.push(*it);
            //         a.erase(it);
            //     }
            // }
            // endit=a.end();
            it=a.begin();
            while(it!=a.end()){
                // int cnum=*it;
                // cout << "current it " << cnum << endl;
                if (max(*it,cs)%min(*it,cs)==0){
                    // cout << "entered in if \n";
                    q.push(*it);
                    tempit=it;
                    it++;
                    a.erase(tempit);
                    // endit=a.end();
                }
                else {
                    ++it;
                }
            }
        }
        ++count;
    }
    return count;
}

int main () {
    int t;
    cin >> t;
    while (t--){
        int N;
        cin >> N;
        cout << fn(N)<< endl;
        // cout << "=========\n";
    }
}