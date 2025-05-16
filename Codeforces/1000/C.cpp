#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

void dfs(int v, vector<vector<int>> &graph, vector<int> &visited){
    visited[v] = 1;
    for (auto u : graph[v]){
        if (!visited[u]) dfs
    }
}

signed main() {_
    int t; cin >> t;
    while (t--){
        int n;
        vector<vector<int>> graph(n);
        vector<int> visited(n);
        for (int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
}
