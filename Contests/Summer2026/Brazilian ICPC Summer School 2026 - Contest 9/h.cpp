#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'

const int MAX = 1e5+7;
const int MOD = 1e9+7;

int n;
vector<int> g[MAX];
vector<int> gi[MAX];
vector<int> g_scc[MAX];
bool vis[MAX];
stack<int> S;
int comp[MAX];
int com = 0;
int cost[MAX];

void dfs1(int u) {
	vis[u] = true;
	for (int v : g[u]) {
		if (!vis[v]) dfs1(v);
	}
	S.push(u);
}

void dfs2(int u, int c) {
	vis[u] = true;
	comp[u] = c;
    g_scc[c].push_back(u);
	for (int v : gi[u]) {
		if (!vis[v]) dfs2(v, c);
	}
}

void kosaraju() {
    memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)if (!vis[i]) dfs1(i);
    memset(vis, 0, sizeof(vis));
    com = 0;
	while (!S.empty()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) {
            com++;
            dfs2(u, com);
        }
    }
}

signed main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }
    kosaraju();
    int custo = 0;
    int ways = 1;
    for (int i = 1; i <= com; ++i) {
        int mn = 2e9;
        for (int u : g_scc[i]) {
            if (cost[u] < mn) {
                mn = cost[u];
            }
        }
        int cnt = 0;
        for (int u : g_scc[i]) {
            if (cost[u] == mn) {
                cnt++;
            }
        }
        custo += mn;
        ways = (ways * cnt) % MOD;
    }
    cout << custo << " " << ways << endl;
}
