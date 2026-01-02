//Kosaraju

int n, com;
vector<int> g[MAX];
vector<int> gi[MAX];
vector<int> g_scc[MAX]; 
int vis[MAX];
stack<int> S;
int comp[MAX];

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) {
            com++;
            scc(u, com);
        }
    }
}

// funcao para construir o grafo de componentes
void build_component_graph() {
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            if (comp[u] != comp[v]) {
                g_scc[comp[u]].push_back(comp[v]);
            }
        }
    }
    //remove duplicatas
    for (int i = 1; i <= com; i++){
        sort(g_scc[i].begin(), g_scc[i].end());
        if (g_scc[i].empty())continue;
        g_scc[i].erase(unique(g_scc[i].begin(), g_scc[i].end()), g_scc[i].end());
    }
}
