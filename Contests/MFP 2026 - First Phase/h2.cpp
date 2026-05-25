#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int sub[MAXN];

void dfs(int v, int p){
    sub[v] = 1;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        sub[v] += sub[u];
    }
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> c;
    for(int i = 0; i < n-1; i++){
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        c.push_back({a, b, w});
    }

    dfs(1, 1);

    // for(int i = 1; i <= n; i++){
    //     cout << sub[i] << endl;
    // }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        auto [a, b, w] = c[i];
        int x = min(sub[a], sub[b]);
        ans = (ans + ((x*(n-x))%MOD*w)%MOD)%MOD;
    }   


    while(m--){
        int edge, cost; cin >> edge >> cost;
        auto [a, b, w] = c[edge-1];
        int x = min(sub[a], sub[b]);
        int res = ((x*(n-x))%MOD*w)%MOD;
        
        ans = (ans - res + MOD)%MOD;

        ans = (ans + ((x*(n-x))%MOD*cost)%MOD)%MOD;
        c[edge-1] = {a, b, cost};
        cout << ans << endl;
    }
}
