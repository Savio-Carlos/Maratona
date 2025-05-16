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

int ancestor[MAXN][LOG+1], visited[MAXN], depth[MAXN]; 
vector<vector<int>> graph(MAXN);

void dfs(int v, int p){
    ancestor[v][0] = p;
    visited[v] = 1;
    for (int i = 1; i <= LOG; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }
    for (auto u : graph[v]){
        if(!visited[u]){
            depth[u]  = depth[v] + 1;
            dfs(u,v);
        }
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v])swap(u,v);

    for (int i = LOG; i >= 0; i--){
        if (depth[u] - (1<<i) >= depth[v]){
            u = ancestor[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--){
        if (ancestor[u][i] != ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return ancestor[u][0];
}

int dist (int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

signed main () {
    winton;
    int q;
    cin >> q;
    for (int i = 2; i <= 4; i++){
        graph[i].push_back(1);
        graph[1].push_back(i);
    }
    dfs(1,1);
    int l = 2, r = 4;
    int node = 5;
    int ans = dist(l, r);
    for (int i = 0; i < q; i++){
        int a;
        cin >> a;
        ancestor[node][0] = a;
        ancestor[node+1][0] = a;
        depth[node] = depth[a] + 1;
        depth[node+1] = depth[a] + 1;

        for (int k = 1; k <= LOG; k++){
            ancestor[node][k] = ancestor[ancestor[node][k-1]][k-1];
            ancestor[node+1][k] = ancestor[ancestor[node+1][k-1]][k-1];
        }
        int d1 = dist(node, l);
        int d2 = dist(node, r);
        if(d1 > ans || d2 > ans) {
            if(d1 >= d2) {
                ans = d1;
                r = node;
            } else {
                ans = d2;
                l = node;
            }
        }
        cout << ans << endl;
        node += 2;
    }
}
