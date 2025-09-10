//LCA Binary Lifting

int n, ancestor[MAXN][LOG+1], depth[MAXN], visited[MAXN];
vector<vector<int>> graph;

void dfs(int v, int p){
    visited[v] = 1;
    ancestor[v][0] = p;

    for (int i = 1; i <= LOG; i++){
        ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
    }

    for (auto u : graph[v]){
        if (!visited[u]){
            depth[u] = depth[v]+1;
            dfs(u, v);
        }
    }
}

int lca(int v, int u){
    if (depth[v] < depth[u]) swap(v,u);

    for (int i = LOG-1; i >=  0; i--){
        if ((depth[v] - (1<<i)) >= depth[u]){
            v = ancestor[v][i];
        } 
    }

    if (u == v) return v;

    for (int i = LOG-1; i >= 0; i--){
        if (ancestor[v][i] != ancestor[u][i]){
            v = ancestor[v][i];
            u = ancestor[u][i];
        }
    }
    return ancestor[v][0];
}