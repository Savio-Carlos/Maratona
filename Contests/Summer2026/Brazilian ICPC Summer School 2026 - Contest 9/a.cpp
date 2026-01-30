#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'

const int MAX = 300005;
int t, low[MAX], pre[MAX];
bool visited[MAX];
vector<int> graph[MAX];
vector<pair<int, int>> ans;
bool pos = true;

void dfs(int v, int p){
    visited[v] = true;
    pre[v] = low[v] = ++t;
    for (auto u : graph[v]){
        if (u == p) continue;
        if (visited[u]){
            low[v] = min(low[v], pre[u]);
            if (pre[u] < pre[v]){
                ans.push_back({v, u});
            }
        }
        else {
            ans.push_back({v, u});
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > pre[v]){
                pos = false;
            }
        }
    }
}
 
signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    if(!pos){
        cout << 0 << endl;
        return 0;
    }
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
}
