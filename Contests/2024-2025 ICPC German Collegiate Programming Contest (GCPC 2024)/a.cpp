#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct DSU {
	vector<int> comp, sz;
	DSU(int n) : comp(n), sz(n, 1) {
		iota(all(comp), 0);
	}
	int find(int u) {
		if (u == comp[u]) return u;
		return comp[u] = find(comp[u]);
	}
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		sz[a] += sz[b];
		comp[b] = a;
		return true;
	}
};

vector<vector<int>> graph;

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    DSU dsu(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        dsu.merge(a,b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int a = dsu.find(i);
        ans = max(ans, dsu.sz[a]);
    }

    if (!ans) cout << 1 << endl;
    else cout << ans << endl;
}