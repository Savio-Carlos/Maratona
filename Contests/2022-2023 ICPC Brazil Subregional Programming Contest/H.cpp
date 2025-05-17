#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e5+7;

int n, com;
vector<int> g[MAX];
vector<int> gi[MAX];
int vis[MAX];
stack<int> S;
int comp[MAX], indeg[MAX], outdeg[MAX];

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
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
            scc(u, u);
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
    for (int i = 0; i < n; i++){
        for (auto u : g[i]){
            if (comp[i] == comp[u]) continue;
            indeg[comp[u]]++;
            outdeg[comp[i]]++;
        }
    }
    vector<int> compvisited(MAX, 0);
    int in = 0, out = 0;
    for (int i = 0; i < n; i++){
        if (compvisited[comp[i]]) continue;
        compvisited[comp[i]] = 1;
        if (indeg[comp[i]] == 0) in++;
        if (outdeg[comp[i]] == 0) out++;
    }
    if (com == 1) cout << 0 << endl;
    else cout << max(in,out) << endl;
}