#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

struct DSU {
    vector<int> comp, sz;
    DSU(int n) : comp(n), sz(n,1){
        iota(all(comp), 0);
    }

    int find(int u) {
        if (u == comp[u]) return u;
        return comp[u] = find(comp[u]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        comp[b] = a;
    }
};

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<vector<int>> graph(n);
    vector<int> energy(n);
    vector<pair<int,int>> order(n);
    for (int i = 0; i < n; i++){
        cin >> energy[i];
        order[i] = {energy[i], i};
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    sort(all(order));
    vector<int> ans(n);
    for (int i = 0; i < n;){
        int j = i;
        vector<pair<int,int>> cur;
        while (j < n && order[i].first == order[j].first){
            cur.push_back(order[j]);
            j++;
        }
        for (auto &[v, idx] : cur){
            for (auto u : graph[idx]){
                if (v >= energy[u]){
                    debug(idx,v,energy[u]);
                    dsu.unite(idx,u);
                }
            }
        }
        for (auto [_, idx] : cur){
            int a = dsu.find(idx);    
            debug(a);
            ans[idx] = dsu.sz[a];
        }
        i = j;
    }
    for (auto u : ans) cout << u << endl;
}