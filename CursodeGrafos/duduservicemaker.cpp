#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool toposort(int n, vector<vector<int>>& adj){
    vector<int> grauEntrada(n + 1, 0);

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            grauEntrada[v]++;
        }
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (grauEntrada[i] == 0){
            q.push(i);
        } 
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        for (auto u : adj[v]){
            grauEntrada[u]--;
            if (grauEntrada[u] == 0){
                q.push(u);
            } 
        }
    }
    return (cnt != n);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m; 
            cin >> n >> m;

            vector<vector<int>> adj(n + 1);

            while(m--){
                int a, b;
                cin >> a >> b;
                adj[a].push_back(b);
            }
            
    
            if (toposort(n, adj)) cout << "SIM" << endl;
            else cout << "NAO" << endl;
    }
    
}