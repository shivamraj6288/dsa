#include "bits/stdc++.h"
using namespace  std;

void bfs (vector<vector<int>>data , int u=1, int n=1, int e=1){
    bool visited[n+1]= {false};
    queue<int> q;
    q.push(u);
    visited[u]= true;
    cout << u << ",";
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for (int v : data[current]){
            if (!visited[v]){
                q.push(v);
                visited[v]= true;
                cout << v << ",";
            }

        }
    }


}
class dfsSearch {
public :
    bool *dfs_visited;
    dfsSearch (int n) {
        this->dfs_visited=new bool[n];
//        this->dfs_visited={false};
    }
    void dfs( vector<vector<int>>data, int u, int n=1){
        if (!this->dfs_visited[u]){
            cout << u << ",";
            this->dfs_visited[u]=true;
            for (int v : data[u]){
                dfs(data, v, n);
            }
        }

    }

    ~dfsSearch(){
//        cout << "destructor called";
        delete [] dfs_visited;
    }
};


int main (int argc, char *argsv[]){


    int n ;
    cin >> n;
    vector <vector<int>> data(n+1) ;
//    cout << data.size();
    int edges;
    cin >> edges;
    data[0].push_back(-1);
    for (int i=1; i<=edges; i++){
//        cout << "relation" << endl;
        int v1, v2;
        cin >> v1 >> v2;
        data[v1].push_back(v2);
        data[v2].push_back(v1);

    }
    int u;
    cin >> u;

    bfs(data, u, n, edges);
    cout <<endl<< "=====" << endl;
    dfsSearch d1(n);
    d1.dfs(data, u, n);
    cout << endl;
    return 0;


}