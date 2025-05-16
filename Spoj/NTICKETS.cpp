#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int LOG = 20;
const int INF = INT_MAX;

int n, fee[MAXN][LOG+1], depth[MAXN], ancestor[MAXN][LOG+1], visited[MAXN];
vector<vector<pair<int,int>>> graph(MAXN);

void dfs(int v, int p){
    ancestor[v][0] = p;
    visited[v] = 1;
    for (auto u : graph[v]){
        if (!visited[u.first]){
            depth[u.first] = depth[v] + 1;
            fee[u.first][0] = u.second;
            dfs(u.first,v);
        }
    }
}

int lca(int u, int v){
    int mx = 0;
    if (depth[u] < depth[v]) swap(u,v);

    for (int i = LOG; i >= 0; i--){
        if (depth[u] - (1<<i) >= depth[v]){
            mx = max(mx, fee[u][i]);
            u = ancestor[u][i];
        }
    }

    if (u == v) return mx;

    for (int i = LOG; i >= 0; i--){
        if (ancestor[u][i] != ancestor[v][i]){
            mx = max({mx, fee[u][i], fee[v][i]});
            u = ancestor[u][i]; 
            v = ancestor[v][i];
        }
    }

    mx = max({mx, fee[u][0], fee[v][0]});

    return mx;
}

signed main () {
    winton;
    while(1){
        cin >> n;
        if (n == 0) break;

        graph.clear();
        graph.resize(n+1);
        memset(visited, 0, sizeof(visited));
        memset(ancestor, 0, sizeof(ancestor));
        memset(fee, 0, sizeof(ancestor));
        memset(depth, 0, sizeof(depth));

        for (int i = 1; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
    
        depth[1] = 0;
        dfs(1,1);

        for (int i = 1; i <= LOG; i++){
            for (int j = 1; j <= n; j++){
                int par = ancestor[j][i-1];
                ancestor[j][i] = ancestor[par][i-1];
                fee[j][i] = max(fee[j][i-1], fee[par][i-1]);
            }
        }
        int q; cin >> q;
        while(q--){
            int x, y;
            cin >> x >> y;
            int ans = lca(x,y);
            cout << ans << endl;
        }
        cout << endl;
    }
}