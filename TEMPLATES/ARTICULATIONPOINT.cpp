/*
Acha os articulation points do grafo
*/

int t, c, low[MAX], rec[MAX], visited[MAX];
vector<int> graph[MAX], ans;

void dfs(int v, int p){
    visited[v] = 1;
    low[v] = rec[v] = ++t;
    bool art = false;
    int filhos = 0;
    for (auto u : graph[v]){
        if (!visited[u]){
            filhos++;
            dfs(u,v);
            low[v] = min(low[v], low[u]);

            if(low[v] >= pre[v]) art = true;
        }   
        else {
            if (u == p) continue;
            low[v] = min(low[v], pre[u]);
        }
    }
    if (v == 1 && filhos >= 2) ans.push_back(v);
    if (v != 1 && art) ans.push_back(v);
}