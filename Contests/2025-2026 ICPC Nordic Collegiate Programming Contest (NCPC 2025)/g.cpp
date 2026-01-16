#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct DSU {
    vector<int> comp, sz;
    DSU(int n) : comp(n), sz(n, 1) {
        iota(all(comp), 0);
    }

    int find(int u){
        if(u == comp[u]) return u;
        return comp[u]= find(comp[u]);
    }

    void merge(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[b] > sz[a]) swap(a,b);
        sz[a] += sz[b];
        comp[b] = a;
    }
};

signed main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        dsu.merge(a, b);
    }

    map<int, set<int>> mp;

    for (int i = 0; i < n; i++){
        mp[dsu.comp[i]].insert(i);
    }
    vector<int> ans(n);
    for (auto [c, v] : mp){
        int cnt = 1;
        if (v.size() != 0 && v.size() < k){
            cout << "impossible\n";
            return 0;
        }
        for (auto u : v){
            if (cnt <= k) ans[u] = cnt;
            else ans[u] = 1;
            cnt++;
        }
    }
    for (auto u : ans) cout << u << " ";
}