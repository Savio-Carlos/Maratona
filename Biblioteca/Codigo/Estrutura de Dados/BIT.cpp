struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n = 0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, int x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}

	int pref(int i) { // soma [0, i]
		int ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	int query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
};