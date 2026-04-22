#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int LOG = 20;
const int INF = INT_MAX;

struct fence{
    int r, x, y, idx;
};

int n, m, depth[MAXN], ancestor[MAXN][LOG+1], visited[MAXN];
vector<pair<int,int>> posts(MAXN);
vector<fence> fences(MAXN);
vector<vector<int>> graph(MAXN);

void montagrafo(){
    for (int i = 1; i <= m; i++){
        int par = 0;
        for (int j = 1; j <= m; j++){
            if (i == j) continue;
            int dx = fences[i].x - fences[j].x;
            int dy = fences[i].y - fences[j].y;
            if (dx*dx + dy*dy <= fences[j].r * fences[j].r -fences[i].r * fences[i].r) {
                if (par == 0 || fences[j].r < fences[par].r)
                    par = j;
            }
        }
        ancestor[i][0] = par;
        graph[par].push_back(i);
    }
}

void dfs(int v, int p){
    visited[v] = 1;
    ancestor[v][0] = p;

    for (int i = 1; i <= LOG; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if (!visited[u]){
            depth[u] = depth[v] + 1;
            dfs(u,v);
        }
    }
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
    int k;
    cin >> n >> m >> k;
    posts.resize(n+1);
    fences.resize(m+1);
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        posts[i] = {a,b};
    }
    for(int i = 1; i <= m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        fences[i].r = a;
        fences[i].x = b;
        fences[i].y = c;
        fences[i].idx = i;
    }
    montagrafo();
    depth[1] = 0;
    for (int i = 1; i <= m; i++) {
        if (ancestor[i][0] == 0 && !visited[i]) {
            depth[i] = 1;
            dfs(i, 0);
        }
    }

    vector<int> control(n+1, 0);
    for (int i = 1; i <= n; i++){
        int root = 0;
        for (int j = 1; j <= m; j++){
            int dx = posts[i].first - fences[j].x;
            int dy = posts[i].second - fences[j].y;
            if(dx*dx + dy*dy < fences[j].r * fences[j].r){
                if(depth[j] > depth[root]) root = j;
            }
        }
        control[i] = root;
    }

    while(k--){
        int a, b;
        cin >> a >> b;
        int u = control[a];
        int v = control[b]; 
        int mac = lca(u,v);
        cout << depth[u] + depth[v] - 2*depth[mac] << endl;
    }
}