// HLD - aresta
//
// SegTree de soma
// query / update de soma das arestas
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))

// namespace SegTree { ... }

namespace HLD {
    vector<pair<int,int>> graph[MAX];
    int timer, pos[MAX], sz[MAX], sobe[MAX], ancestor[MAX], h[MAX], v[MAX]; 

    void build_hld(int node, int p = -1, int f = 1){
        v[pos[node] = timer++] = sobe[node];
        sz[node] = 1;
        for (auto &i : graph[node]){
            auto [u, w] = i;
            if (u == p) continue;
            sobe[u] = w;
            ancestor[u] = node;
            h[u] = (i == graph[node][0] ? h[node] : u); 
            build_hld(u, node, f);
            sz[node] += sz[u];

            if (sz[u] > sz[graph[node][0].first] || graph[node][0].first == p){
                swap(i, graph[node][0]);
            }
        }
        if (p*f == -1)build_hld(h[node] = node, -1, timer = 0);
    }

    void build(int root = 0){
        timer = 0;
        build_hld(root);
        SegTree::build(timer, v);
    }

    int query_path(int a, int b){
        if (a == b) return 0;
        if (pos[a] < pos[b]) swap(a,b);
        if (h[a] == h[b]) return SegTree::query(pos[b] + 1, pos[a]);
        return SegTree::query(pos[h[a]], pos[a]) + query_path(ancestor[h[a]], b);
    }

    void update_path(int a, int b, int x){
        if (a == b) return;
        if (pos[a] < pos[b]) swap(a,b);

        if (h[a] == h[b]) return (void)SegTree::update(pos[b]+1, pos[a], x);
        SegTree::update(pos[h[a]], pos[a], x);
        update_path(ancestor[h[a]], b, x);
    }

    int query_subtree(int a){
        if(sz[a] == 1) return 0;
        return SegTree::query(pos[a]+1, pos[a] + sz[a]-1);
    }

    void update_subtree(int a, int x){
        if(sz[a] == 1) return;
        SegTree::update(pos[a]+1, pos[a] + sz[a]-1, x);
    }

    int lca(int a, int b){
        if (pos[a] < pos[b]) swap(a,b);
        return h[a] == h[b] ? b : lca(ancestor[h[a]], b);
    }
    int dist(int a, int b) {
        if (a == b) return 0;
        if (pos[a] < pos[b]) swap(a,b);
        if (h[a] == h[b]) return pos[a] - pos[b];
        return pos[a] - pos[h[a]] + 1 + dist(ancestor[h[a]], b);
    }
}