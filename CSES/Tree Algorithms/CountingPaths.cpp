#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

int n, m, visited[MAXN], ancestor[MAXN][LOG+1], depth[MAXN], pfx[MAXN];
vector<int> order;
vector<vector<int>> graph;

void dfs(int v, int p){
    visited[v] = 1;
    ancestor[v][0] = p;
    for (int i = 1; i <= LOG; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if(!visited[u]){
            depth[u] = depth[v]+1;
            dfs(u,v);
        }
    }
    order.push_back(v);
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u,v);
    
    for (int i = LOG; i >= 0; i--){
        if(depth[u] - (1<<i) >= depth[v]){
            u = ancestor[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--){
        if(ancestor[u][i] != ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return ancestor[u][0];
}



signed main () {
    winton;
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    depth[1] = 0;
    dfs(1,1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int mac = lca(a,b);
        pfx[a]++;
        pfx[b]++;
        pfx[mac]--;
        if (mac != ancestor[mac][0] )pfx[ancestor[mac][0]]--;
    }
    for (auto v : order){
            if (ancestor[v][0] != v)pfx[ancestor[v][0]] += pfx[v];
    }

    for (int i = 1; i <= n; i++){
        cout << pfx[i] << " ";
    }
}

/*
        for (int i = 1; i <= n; i++){
            cout << pfx[i] << " ";
*/