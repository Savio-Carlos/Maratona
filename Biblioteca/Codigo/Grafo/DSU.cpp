//DSU 

struct DSU {
	vector<int> comp, sz;
	DSU(int n) : comp(n), sz(n, 1) {
		iota(all(comp), 0);
	}
	int find(int u) {
		if (u == comp[u]) return u;
		return comp[u] = find(comp[u]);
	}
	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		sz[a] += sz[b];
		comp[b] = a;
		return true;
	}
};