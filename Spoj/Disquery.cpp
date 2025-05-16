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

int n, ancestor[MAXN][LOG+1], visited[MAXN], depth[MAXN];
vector<vector<pair<int,int>>> graph(MAXN);
pair<int,int> dist[MAXN][LOG+1];

void dfs(int v, int p){
    visited[v] = 1;
    ancestor[v][0] = p;
    for (auto u: graph[v]){
        if (!visited[u.first]){
            dist[u.first][0] = {u.second, u.second};
            depth[u.first] = depth[v] + 1;
            dfs(u.first,v);
        }
    }
}

pair<int,int> lca(int u, int v){
    int mn = INF, mx = 0;
    if (depth[u] < depth[v]) swap(u,v);

    for (int i = LOG; i >= 0; i--){
        if (depth[u] - (1<<i) >= depth[v]){
            mn = min(mn, dist[u][i].first);
            mx = max(mx, dist[u][i].second);
            u = ancestor[u][i];
        }
    }
    if(u == v) return {mn,mx};
    for (int i = LOG; i >= 0; i--){
        if (ancestor[u][i] != ancestor[v][i]){
            mn = min({mn, dist[u][i].first, dist[v][i].first});
            mx = max({mx, dist[u][i].second, dist[v][i].second});
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    mn = min({mn, dist[u][0].first, dist[v][0].first});
    mx = max({mx, dist[u][0].second, dist[v][0].second});
    
    return {mn, mx};
}

signed main () {
    winton;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= LOG; j++){
            dist[i][j].first = INF;
            dist[i][j].second = 0;
        }
    }
    depth[1] = 0;
    dfs(1,1);

    for (int i = 1; i <= LOG; i++){
        for (int j = 1; j <= n; j++){
            int par = ancestor[j][i-1];
            ancestor[j][i] = ancestor[par][i-1];
            dist[j][i].first = min(dist[j][i-1].first, dist[par][i-1].first);
            dist[j][i].second = max(dist[j][i-1].second, dist[par][i-1].second);
        }
    }

    int q; cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        pair<int,int> mac = lca(x,y);
        cout << mac.first << " " << mac.second << endl;
    }
}