#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int LOG = 20;
const int INF = INT_MAX;

int n, dist[MAXN], depth[MAXN], ancestor[MAXN][LOG+1], visited[MAXN];
vector<vector<pair<int,int>>> graph(MAXN);

void dfs(int v, int p){
    ancestor[v][0] = p;
    visited[v] = 1;

    for (int i = 1; i <= LOG; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if (!visited[u.first]){
            depth[u.first] = depth[v] + 1;
            dist[u.first] = dist[v] + u.second;
            dfs(u.first,v);
        }
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u,v);

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

int binarylifting(int u, int v, int k){
    int mac = lca(u,v);
    int diff = depth[u] - depth[mac];

    for (int i = LOG; i >= 0; i--){
        if ((1<<i) <= diff && (1<<i) <= k){
            u = ancestor[u][i];
            k -= (1<<i);
            diff -= (1<<i);
        }
    }
    if (k == 0) return u;
    int diff2 = depth[v] - depth[mac];
    int k2 = diff2 - k;
    for (int i = LOG; i >= 0; i--){
        if ((1<<i) <= diff2 && (1<<i) <= k2){
            v = ancestor[v][i];
            k2 -= (1<<i);
            diff2 -= (1<<i);
        }
    }
    return v;
}

signed main () {
    winton;
    int t; cin >> t;
    while(t--){
        cin >> n;
        graph.clear();
        graph.resize(n+1);
        memset(visited, 0, sizeof(visited));
        memset(ancestor, 0, sizeof(ancestor));
        memset(dist, 0, sizeof(dist));
        memset(depth, 0, sizeof(depth));

        for (int i = 1; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
    
        depth[1] = 0;
        dist[1] = 0;    
        dfs(1,1);

        string q = "a"; 
        while(1){
            cin >> q;
            if (q == "DONE") break;
            int x, y;
            cin >> x >> y;
            if (q == "DIST"){
                int mac = lca(x,y);
                cout << dist[x] + dist[y] - 2*dist[mac] << endl;
            }
            else if (q == "KTH"){
                int k;
                cin >> k;
                cout << binarylifting(x,y,k-1) << endl;
            }   
        }
        cout << endl;
    }
}