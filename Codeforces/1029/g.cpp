#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;
const int MOD = 1e9+7;
/*
faco meio que um mst onde vou unindo os caras a partir do menor custo
a cada insercao, se 1 e n tiverem conectados eu vejo o custo minimo e o custo da edge atual
e vejo se a soma deles e menor que minha resposta atual
*/

struct DSU {
    vector<int> comp, mn;
    int n;

    void build(){
        comp.resize(n);
        mn.resize(n);
        for (int i = 1; i < n; i++){
            comp[i] = i;
            mn[i] = INF;
        }
    }
    
    int find(int u){
        if (comp[u] == u) return u;
        return comp[u] = find(comp[u]);
    }

    int menor(){
        return mn[find(1)];
    }

    void unite(int u, int v, int w){
        u = find(u);
        v = find(v);
        int mini = min({mn[u],mn[v],w});
        mn[u]=mini;
        mn[v]=mini;
        comp[v] = u; 
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges; 
    DSU dsu;
    dsu.n = n+1;
    dsu.build();
    edges.resize(m);
       for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w,a,b};
    }
    sort(all(edges));
    int ans = INF;
    for(int i = 0; i < m; i++){
        auto [w,a,b] = edges[i];
        dsu.unite(a,b,w);
        int mini = dsu.menor();
        if (dsu.find(1) == dsu.find(n)){
            ans = min(w+mini, ans);
        }
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}