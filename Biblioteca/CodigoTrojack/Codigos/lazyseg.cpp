//Lazy SegTree
//updrange: O(logN)
//rangequery: O(logN)
struct lazyseg {
    int n;
    vector<int> t;
    vector<int> lazy;
    void init(int _n) {
        n = _n;
        t.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void propagate(int v, int l, int r){
        if(lazy[v] != 0){
            if((r - l + 1) & 1){
                t[v] ^= lazy[v];
            }
            if(l != r){
                lazy[2*v+1] = op(lazy[2*v+1], lazy[v]);
                lazy[2*v+2] = op(lazy[2*v+2], lazy[v]);
            }
            lazy[v] = 0;
        }
    }

    int op(int a, int b){
        return (a ^ b);
    }

    void updateRange(int v, int l, int r, int lx, int rx, int x){
        propagate(v, l, r);
        if(rx < l || r < lx) return;
        if(lx <= l && r <= rx){
            lazy[v] ^= x;
            propagate(v, l, r);
            return;
        }

        int m = (l+r)/2;
        updateRange(2*v+1, l, m, lx, rx, x);
        updateRange(2*v+2, m+1, r, lx, rx, x);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void updateRange(int l, int r, int val){
        updateRange(0, 0, n-1, l, r, val);
    }

    int queryRange(int v, int l, int r, int lx, int rx){
        propagate(v, l, r);
        if(rx < l || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return op(queryRange(2*v+1, l, m, lx, rx), queryRange(2*v+2, m+1, r, lx, rx));
    }

    int query(int l, int r){
        return queryRange(0, 0, n-1, l, r);
    }

    void build(vector<int> &a, int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(a, 2*v+1, l, m);
        build(a, 2*v+2, m+1, r);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }
    void build(vector<int> &a) {
        build(a, 0, 0, n-1);
    }

};