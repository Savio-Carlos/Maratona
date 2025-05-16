#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;
const int INF = INT_MAX;

vector<vector<int>> graph;
int n, dist[3][MAXN];

void dfs(int v, int p, int id){
    for (auto u : graph[v]){
        if (u == p) continue;
        dist[id][u] = dist[id][v] + 1;
        dfs(u,v,id);
    }
}
int distance(int id){
    int u = -1, mx = 0;
    for (int i = 1; i <= n; i++){
        if (dist[id][i] > mx){
            u = i;
            mx = dist[id][i];
        }
    }
    return u;
}
int cont(int v, int p, int d){
    if (d == 0) return 1;
    int cur = 0;
    for (auto u : graph[v]){
        if (u == p) continue;
        cur += cont(u,v,d-1);
    }
    return cur;
}

signed main () {
    winton;
    cin >> n;
    graph.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0,0);
    int a = distance(0);
    dfs(a,0,1);
    int b = distance(1);
    dfs(b,0,2);
    cout << dist[2][a] << endl;
}