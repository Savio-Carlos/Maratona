struct DSU {
    vector<int> comp;
    int n;
    void build(){
        comp.resize(n);
        for (int i = 1; i < n; i++){
            comp[i] = i;
        }
    }
    int find(int u){
        if (comp[u] == u) return u;
        return comp[u] = find(comp[u]);
    }
    void unite(int u, int v, int w){
        u = find(u);
        v = find(v);
        comp[v] = u; 
    }
};
