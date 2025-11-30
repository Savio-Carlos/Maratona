#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

const int INF = 1e18;

struct dinitz {
	const bool scaling = false;
	int lim;
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_): to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	int F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); 
        lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; 
        q.push(s);
		while (!q.empty()){
			int u = q.front(); 
            q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int &i = beg[v]; i < g[v].size(); i++) {
			auto &e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	int max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};


signed main(){
    fastio;
    int n, g, c, m;
    cin >> n >> g >> c >> m;
    dinitz d(n+2);
    
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d.add(a,b,c);
    }
    for (int i = 1; i <= g; i++){
        d.add(0, i, INF);
    }
    for (int i = n-c+1; i <= n; i++){
        d.add(i, n+1, INF);
    }
    cout << d.max_flow(0, n+1) << endl;
}