// SegTree Update
//
// Recursiva sem Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
//
namespace SegTree {
    int tree[4*MAX];
    int n, *v;

    int build(int node=1, int l=0, int r=n-1) {
        if (l == r) return tree[node] = v[l];
        int m = (l+r)/2;
        return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
    }

    void build(int n2, int* v2) {
        n = n2, v = v2;
        build();
    }
   
    int query(int a, int b, int node=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return tree[node];
        int m = (l+r)/2;
        return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
    }
    
    void update(int i, int x, int node=1, int l=0, int r=n-1) {
        if (l == r) {
            tree[node] = x;
            return;
        }
        int m = (l+r)/2;
        if (i <= m) update(i, x, 2*node, l, m);
        else update(i, x, 2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
