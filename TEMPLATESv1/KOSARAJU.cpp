int n, com;
vector<int> g[MAX];
vector<int> gi[MAX];
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

signed main(){
    winton;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        gi[b].push_back(a);
    }
    kosaraju();
}