#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e5+7;

int n, dist = 0, arr[MAX], deg[MAX];
vector<vector<int>> graph;
set<pair<int,int>> edges;

void dfs(int v, int p){
    int cnt = 0;
    for (auto u : graph[v]){
        if (u==p) continue;
        dfs(u,v);

    }
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        graph.resize(n);
        for (int i = 0; i < n; i++){
            graph[i].clear();
        }
        for (int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
            deg[a]++;
            deg[b]++;
            edges.insert({a,b});
        }
        dfs(0,-1);
    
    }
}
