//DSU 

struct DSU{
    int n;
    vector<int> p, r;
    void init(int _n){
        n = _n;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            p[b] = a;
            r[a]++;
        }else{
            p[a] = b;
            r[b]++;
        }
        return true;
    }
}


struct DSU {
	vector<int> id, sz;

	DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

