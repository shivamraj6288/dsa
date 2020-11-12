#include <bits/stdc++.h> 
using namespace std; 
  
const int MAXX = 10000, INF = 1e9; 
  
vector<vector<pair<int, int> > > 
    adj(MAXX * 10 + 3); 
  
vector<int> dist(MAXX * 10 + 3, INF); 
  

int even(int x) 
{ 
    return x * 10 + 2; 
} 

int odd(int x) 
{ 
    return x * 10 + 1; 
} 
  

void addEdge(int a, int b, int cost) 
{ 
    adj[even(a)].push_back( 
        { odd(b), cost }); 
    adj[odd(a)].push_back( 
        { even(b), cost }); 
    adj[odd(b)].push_back( 
        { even(a), cost }); 
    adj[even(b)].push_back( 
        { odd(a), cost }); 
} 
  

int dijkstra(int source, 
             int destination) 
{ 
  
    
    priority_queue<pair<int, int>, 
                   vector<pair<int, int> >, 
                   greater<pair<int, int> > > 
        pq; 
  
   
    pq.push({ 0, even(source) }); 
    dist[even(source)] = 0; 
  
    while (!pq.empty()) { 
  
        
        int u = pq.top().second; 
        pq.pop(); 
  
        
        for (pair<int, int> p : 
             adj[u]) { 
  
           
            int v = p.first; 
            int c = p.second; 
  
            
            if (dist[u] + c 
                < dist[v]) { 
  
                dist[v] = dist[u] + c; 
                pq.push({ dist[v], v }); 
            } 
        } 
    } 
  
   
    return dist[even(destination)]; 
} 
  
int main() 
{ 
    
    int n , m ,u,v; 
    cin >>n >> m>>u >>v;
    for (int i=0;i<m; i++){
        int a,b;
        cin>> a >>b;
        a++; b++;
        addEdge(a,b,1);
    }
  
    int source = u+1; 
    int destination = v+1; 
    int ans = dijkstra(source, destination); 
  
   
    if (ans == INF) 
        cout << "impossible\n"; 
    else
        cout << "possible\n" << ans/2 << endl;; 
  
    return 0; 
} 