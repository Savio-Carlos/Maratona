#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int LOG = 20;
const int MAXN = 2*1e5+7;

int n, visited[MAXN], ancestor[MAXN][LOG+1], depth[MAXN];
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
}

int binarylifting(int u, int k){
    if (k > depth[u]) return -1;
    for (int i = LOG; i>= 0; i--){
        if(k & (1 << i)){
            u = ancestor[u][i];
        }
    }
    return u;
}

signed main () {
    winton;
    int q;
    cin >> n >> q;
    graph.clear();
    graph.resize(n+1);
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }
    ancestor[1][0] = 1;
    depth[1] = 0;
    dfs(1,1);
    while(q--){
        int u, k;
        cin >> u >> k;
        cout << binarylifting(u, k) << endl;
    }
}