// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))
//
// build (n, vector)
// query (int a, int b)
// update (int a, int b, int x)
// se for de multiplicacao mudar o lazy pra 1 e tirar o lazy * (r-l+1)

namespace SegTree {
	int tree[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int node=1, int l=0, int r=n-1) {
		lazy[node] = 0;
		if (l == r) return tree[node] = v[l];
		int m = (l+r)/2;
		return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int node, int l, int r) {
		tree[node] += lazy[node]*(r-l+1);
		if (l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
		lazy[node] = 0;
	}
	int query(int a, int b, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) return tree[node];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
	}
	int update(int a, int b, int x, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) {
			lazy[node] += x;
			prop(node, l, r);
			return tree[node];
		}
		if (b < l or r < a) return tree[node];
		int m = (l+r)/2;
		return tree[node] = update(a, b, x, 2*node, l, m) + update(a, b, x, 2*node+1, m+1, r);
	}
}


