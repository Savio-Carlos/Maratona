#include <bits/stdc++.h>
using namespace std;
 
using int64 = long long;
const int MAXN = 200000 + 5;
const int64 NEG_INF = LLONG_MIN / 4;
 
int n, q;
vector<int> adj[MAXN];
int64 val[MAXN];
 
int parentArr[MAXN], depthArr[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], szArr[MAXN];
int curPos;
vector<int64> baseArr;
 
struct SegTree {
    int N;
    vector<int64> st;
    void init(int n) {
        N = 1;
        while (N < n) N <<= 1;
        st.assign(2*N, NEG_INF);
    }
    void build(const vector<int64>& a) {
        init((int)a.size());
        for (int i = 0; i < (int)a.size(); ++i) st[N+i] = a[i];
        for (int i = N-1; i >= 1; --i) st[i] = max(st[2*i], st[2*i+1]);
    }
    void update(int idx, int64 value) {
        int p = N + idx;
        st[p] = value;
        p >>= 1;
        while (p) {
            st[p] = max(st[2*p], st[2*p+1]);
            p >>= 1;
        }
    }
    int64 queryRange(int l, int r) { // inclusive l,r
        if (l > r) return NEG_INF;
        l += N; r += N;
        int64 res = NEG_INF;
        while (l <= r) {
            if (l & 1) res = max(res, st[l++]);
            if (!(r & 1)) res = max(res, st[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
} seg;
 
// first dfs: compute sizes and heavy child
int dfs(int u, int p) {
    parentArr[u] = p;
    depthArr[u] = (p == -1 ? 0 : depthArr[p] + 1);
    szArr[u] = 1;
    int maxSub = 0;
    heavy[u] = -1;
    for (int v : adj[u]) if (v != p) {
        int sub = dfs(v, u);
        if (sub > maxSub) {
            maxSub = sub;
            heavy[u] = v;
        }
        szArr[u] += sub;
    }
    return szArr[u];
}
 
// decompose: assign head and positions, fill baseArr
void decompose(int u, int h) {
    head[u] = h;
    pos[u] = curPos++;
    baseArr[pos[u]] = val[u];
    if (heavy[u] != -1) decompose(heavy[u], h);
    for (int v : adj[u]) if (v != parentArr[u] && v != heavy[u]) {
        decompose(v, v);
    }
}
 
int64 query_path(int a, int b) {
    int64 res = NEG_INF;
    while (head[a] != head[b]) {
        if (depthArr[head[a]] < depthArr[head[b]]) swap(a,b);
        int ha = head[a];
        res = max(res, seg.queryRange(pos[ha], pos[a]));
        a = parentArr[ha];
    }
    if (depthArr[a] < depthArr[b]) swap(a,b);
    res = max(res, seg.queryRange(pos[b], pos[a]));
    return res;
}
 
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        adj[i].clear();
    }
    for (int i = 0; i < n-1; ++i) {
        int a,b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    curPos = 0;
    baseArr.assign(n, NEG_INF);
    decompose(0, 0);
    seg.build(baseArr);
 
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s; int64 x; cin >> s >> x; --s;
            val[s] = x;
            seg.update(pos[s], x);
        } else {
            int a,b; cin >> a >> b; --a; --b;
            int64 ans = query_path(a,b);
            cout << ans << '\n';
        }
    }
    return 0;
}