//Minimum Spanning Tree

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
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges; 
    DSU dsu(n);
    edges.resize(m);
       for (int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w,a,b};
    }
    sort(all(edges));
    int cost = 0;
    for(int i = 0; i < m; i++){
        auto [w,u,v] = edges[i];
        if (dsu.merge(u,v)){
            cost += w;
        }
    }
}