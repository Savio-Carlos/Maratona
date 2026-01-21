#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define int long long

const int MAXN = 5e5+7;
vector<int> graph[MAXN];
int tin[MAXN], tout[MAXN];
int t = -1;

struct segseg {
    int tree[4*MAXN], lazy[4*MAXN];
    int n;

    void build(int node, int l, int r) {
        lazy[node] = 0;
        tree[node] = 0;
        if (l == r) return;
        int m = (l+r)/2;
        build(2*node, l, m);
        build(2*node+1, m+1, r);
    }

    void init(int _n) {
        n = _n;
        build(1, 0, n-1);
    }

    void prop(int node, int l, int r) {
        if (lazy[node]) {
            tree[node] = lazy[node];
            if (l != r) {
                lazy[2*node] = lazy[node];
                lazy[2*node+1] = lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int a, int b, int x, int node=1, int l=0, int r=MAXN-1) {
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            lazy[node] = x;
            prop(node, l, r);
            return;
        }
        int m = (l+r)/2;
        update(a, b, x, 2*node, l, m);
        update(a, b, x, 2*node+1, m+1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int a, int b, int node=1, int l=0, int r=MAXN-1) {
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return tree[node];
        int m = (l+r)/2;
        return max(query(a, b, 2*node, l, m), query(a, b, 2*node+1, m+1, r));
    }
};

void dfs(int v, int p){
    tin[v] = ++t;
    for (auto u : graph[v]){
        if (u!=p) dfs(u, v);
    }
    tout[v] = t;
}

segseg segr, segp;

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    // for(int i = 0; i < n; i++){
    //     cout << tin[i] << " " << tout[i] << endl;
    // }
    int q; cin >> q;
    segr.init(n+1);
    segp.init(n+1);
    for(int i = 1; i <= q; i++){
        int op, v; cin >> op >> v;
        op--;
        if(!op) segr.update(tin[v], tout[v], i);
        else if(op == 1) segp.update(tin[v], tin[v], i);
        else{
            int lstr = segr.query(tin[v], tin[v]);
            int lstp = segp.query(tin[v], tout[v]);
            if(lstr > lstp) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}