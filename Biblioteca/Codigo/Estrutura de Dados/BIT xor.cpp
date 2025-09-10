// BIT
//
// BIT de xor 1-based
// faz o xor no intervalo
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
 
struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	void update(int i, int x) { // xor x na posicao i
		for (i; i <= n; i += i & -i) bit[i] ^= x;
	}
	int pref(int i) { // xor [0, i]
		int ret = 0;
		for (i; i; i -= i & -i) ret ^= bit[i];
		return ret;
	}
	int query(int l, int r) {  // xor [l, r]
        debug(pref(r), pref(l-1));
		return pref(r) ^ pref(l - 1); 
	}
};