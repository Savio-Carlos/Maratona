//Coin Collector

vector<vector<int>> graph, rgraph;
vector<set<int>> gcomp;
stack<int> st;
int n, com, indeg[MAX], dp[MAX], coins[MAX], visited[MAX], comp[MAX], gcoins[MAX];
 
void dfs(int v) {
	visited[v] = 1;
	for (auto u : graph[v]){
		if (!visited[u]) dfs(u);
    }
	st.push(v);
}
 
void scc(int v, int c) {
	visited[v] = 1;
	comp[v] = c;
	for (auto u : rgraph[v]){
		if (!visited[u]) scc(u, c);
    }
}
 
void kosaraju() {
	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++) if (!visited[i]) dfs(i);
	for (int i = 0; i < n; i++) visited[i] = 0;
	while (st.size()) {
		int u = st.top();
		st.pop();
		if (!visited[u]) {
            scc(u, com++);
        }
    }
}
 
signed main(){
    int m;
    cin >> n >> m;
    graph.resize(n);
    rgraph.resize(n);
 
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        rgraph[b].push_back(a);
    }
    kosaraju();
    gcomp.resize(com);
    for(int v = 0; v < n; v++){
        for (auto u : graph[v]){
            if (comp[u] == comp[v]) continue;
        
            if (gcomp[comp[v]].insert(comp[u]).second){
                indeg[comp[u]]++;
            }
        }
    }
    for(int i = 0; i < n; i++) gcoins[comp[i]] += coins[i];
    for(int i = 0; i < n; i++) dp[i] = gcoins[i];
    for(int i = 0; i < n; i++) {
        debug(i, comp[i], gcoins[i], indeg[i]);
    }
 
    queue<int> q;
    for (int i = 0; i < com; i++){
        if (indeg[i] == 0) q.push(i);
    }
 
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto u : gcomp[v]){
            debug(u);
            dp[u] = max(dp[u], dp[v] + gcoins[u]);
            if (--indeg[u] == 0) q.push(u);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}