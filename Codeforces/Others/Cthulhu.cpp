#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;

vector<vector<int>> graph;
vector<bool> visited;
int cycles = 0;

bool dfs(int v, int pai){
    visited[v] = true;
    for(auto u : graph[v]){
        if(!visited[u]){
            if (dfs(u,v)) return true;
        }
        else if (u != pai) cycles++;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    bool ans = true;

    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b;
        a--; 
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited.resize(n);
    bool df = dfs(0,-1);
    
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            ans = false;
        }    
    }
    
    if (ans && cycles == 2)cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;
}