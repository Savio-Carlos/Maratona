//SegTree Bits
// Segment tree para bits com suporte a posicoes invalidas.
// v[i] = -1 => posicao invalida (nao conta)
// v[i] = 0  => desligado
// v[i] = 1  => ligado
//
// build(n2, v2)
// query(a,b)        -> 1's em [a,b]
// update(a,b)       -> flip em [a,b]
// range_set(a,b,x)  -> seta intervalo [a,b] para x (0/1)
// point_set(i, x)   -> seta posicao i para -1/0/1

namespace SegTreeBits {
    int tree[4*MAX];       // 1's no intervalo
    int valid[4*MAX];      // posicoes validas no intervalo
    int lazy_set[4*MAX];   // -1 = nenhum, 0 ou 1 = set pendente
    int lazy_flip[4*MAX];  // 0/1: flip pendente
    int n, *v;

    int build(int node = 1, int l = 0, int r = n-1) {
        lazy_set[node] = -1;
        lazy_flip[node] = 0;
        if (l == r) {
            if (v[l] == -1) {
                valid[node] = 0;
                tree[node] = 0;
            } else {
                valid[node] = 1;
                tree[node] = v[l];
            }
            return tree[node];
        }
        int m = (l + r)/2;
        build(2*node, l, m);
        build(2*node+1, m+1, r);
        valid[node] = valid[2*node] + valid[2*node+1];
        return tree[node] = tree[2*node] + tree[2*node+1];
    }

    void build(int n2, int* v2) {
        n = n2; v = v2;
        build();
    }

    inline void apply_set(int node, int l, int r, int x) {
        tree[node] = valid[node] * x;
        lazy_set[node] = x;
        lazy_flip[node] = 0;
    }

    inline void apply_flip(int node, int l, int r) {
        tree[node] = valid[node] - tree[node];
        if (lazy_set[node] != -1) {
            lazy_set[node] ^= 1;
        } else {
            lazy_flip[node] ^= 1;
        }
    }

    void prop(int node, int l, int r) {
        if (l == r) return;
        int m = (l + r)/2;
        if (lazy_set[node] != -1) {
            apply_set(2*node, l, m, lazy_set[node]);
            apply_set(2*node+1, m+1, r, lazy_set[node]);
            lazy_set[node] = -1;
        }
        if (lazy_flip[node]) {
            apply_flip(2*node, l, m);
            apply_flip(2*node+1, m+1, r);
            lazy_flip[node] = 0;
        }
    }

    int query(int a, int b, int node = 1, int l = 0, int r = n-1) {
        if (b < l || r < a) return 0;
        if (a <= l && r <= b) return tree[node];
        prop(node, l, r);
        int m = (l + r)/2;
        return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
    }

    int update(int a, int b, int node = 1, int l = 0, int r = n-1) {
        if (b < l || r < a) return tree[node];
        if (a <= l && r <= b) {
            apply_flip(node, l, r);
            return tree[node];
        }
        prop(node, l, r);
        int m = (l + r)/2;
        return tree[node] = update(a, b, 2*node, l, m) + update(a, b, 2*node+1, m+1, r);
    }

    int range_set(int a, int b, int x, int node = 1, int l = 0, int r = n-1) {
        if (b < l || r < a) return tree[node];
        if (a <= l && r <= b) {
            apply_set(node, l, r, x);
            return tree[node];
        }
        prop(node, l, r);
        int m = (l + r)/2;
        return tree[node] = range_set(a, b, x, 2*node, l, m) + range_set(a, b, x, 2*node+1, m+1, r);
    }

    int point_set(int idx, int val, int node = 1, int l = 0, int r = n-1) {
        if (l == r) {
            lazy_set[node] = -1;
            lazy_flip[node] = 0;
            if (val == -1) {
                valid[node] = 0;
                tree[node] = 0;
            } else {
                valid[node] = 1;
                tree[node] = val;
            }
            return tree[node];
        }
        prop(node, l, r);
        int m = (l + r)/2;
        if (idx <= m) point_set(idx, val, 2*node, l, m);
        else point_set(idx, val, 2*node+1, m+1, r);
        valid[node] = valid[2*node] + valid[2*node+1];
        return tree[node] = tree[2*node] + tree[2*node+1];
    }
}
