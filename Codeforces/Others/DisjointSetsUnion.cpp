#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

int comp[MAXN], sz[MAXN];

void dsu(int n){
    for (int i = 1; i <= n; i++){
        comp[i] = i;
    }
}

int find(int u){
    if (comp[u] == u) return u;
    return comp[u] = find(comp[u]);
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if (sz[u] < sz[v]) swap (u,v);
    comp[v] = u;
    sz[u]+=sz[v];
}

signed main() {
    winton;
    int n, m;
    cin >> n >> m;
    dsu(n);
    while (m--){
        string s;
        cin >> s;
        if (s == "union"){
            int a, b;
            cin >> a >> b;
            unite(a,b);
        }
        else {
            int a, b;
            cin >> a >> b;
            int u = find(a);
            int v = find(b);
            if (u != v) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}