#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int MAXL = 20;

int n, ancestor[MAXN][MAXL+1], depth[MAXN], visited[MAXN];
vector<vector<int>> graph;

void dfs(int v, int p){
    visited[v] = 1;
    ancestor[v][0] = p;

    for (int i = 1; i <= MAXL; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if (!visited[u]){
            depth[u] = depth[v]+1;
            dfs(u, v);
        }
    }
}

int lca(int v, int u){
    if (depth[v] < depth[u]) swap(v,u);

    for (int i = MAXL-1; i >=  0; i--){
        if ((depth[v] - (1<<i)) >= depth[u]){
            v = ancestor[v][i];
        } 
    }

    if (u == v) return v;

    for (int i = MAXL-1; i >= 0; i--){
        if (ancestor[v][i] != ancestor[u][i]){
            v = ancestor[v][i];
            u = ancestor[u][i];
        }
    }
    return ancestor[v][0];
}

signed main () {
    winton;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n;

        graph.clear();
        graph.resize(n+1);
        memset(visited, 0, sizeof(visited));
        memset(ancestor, 0, sizeof(ancestor));
        memset(depth, 0, sizeof(depth));

        for (int i = 1; i <= n; i++){
            int m;
            cin >> m;
            for (int j = 1; j <= m; j++){
                int a;
                cin >> a;
                graph[i].push_back(a);
                graph[a].push_back(i);
            }
        }
        ancestor[1][0] = 1;
        depth[1] = 1;
        dfs(1,1);

        int q;
        cin >> q;
        cout << "Case " << tt << ":" << endl;

        while(q--){
            int u, v;
            cin >> v >> u;
            cout << lca(v,u) << endl; 
        }
    }
}