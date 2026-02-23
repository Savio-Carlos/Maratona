#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


const int INF = 2e18;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
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
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
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
		for (int& i = beg[v]; i < (int)g[v].size(); i++) {
			auto& e = g[v][i];
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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,int> cnta, cntb;
    for (auto &u : a){
        cin >> u;
        cnta[u]++;
    } 
    for (auto &u : b){
        cin >> u;
        cntb[u]++;
    } 

    for (int i = 1; i <= n; i++){
        if ((cnta[i] + cntb[i]) % 2 != 0){ 
            cout << -1 << endl; 
            return; 
        }
    }

    vector<int> diff(n+2, 0);
    int need = 0;
    for (int i = 1; i <= n; i++) {
        diff[i] = (cnta[i] - cntb[i]) / 2;
        if (diff[i] > 0) need += diff[i];
    }

    if (!need) {
        cout << 0 << endl << endl;
        return;
    }

    int S = n, T = n+1;
    dinitz dinic(n+2);

    for (int i = 1; i <= n; i++) {
        if (diff[i] > 0) dinic.add(S, i-1, diff[i]);
        else if (diff[i] < 0) dinic.add(i-1, T, -diff[i]);
    }

    vector<int> order;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]) order.push_back(i);
    }

    sort(order.begin(), order.end(), [&](int i, int j){
        if (a[i] != a[j]) return a[i] < a[j];
        return b[i] < b[j];
    });

    struct GroupInfo { int u, v, edge_idx, start, cap; };
    vector<GroupInfo> groups;

    int i = 0;
    while (i < (int)order.size()) {
        int u = a[order[i]], v = b[order[i]];
        int j = i;
        while (j < (int)order.size() && a[order[j]] == u && b[order[j]] == v) j++;
        int cap = j - i;
        int eidx = dinic.g[u-1].size();
        dinic.add(u-1, v-1, cap);
        groups.push_back({u, v, eidx, i, cap});
        i = j;
    }

    int flow = dinic.max_flow(S, T);
    if (flow != need) { cout << -1 << endl; return; }

    vector<int> result;
    for (auto& [u, v, eidx, start, cap] : groups) {
        int used = dinic.g[u-1][eidx].flow;
        for (int k = start; k < start + used; k++)
            result.push_back(order[k] + 1); // 1-indexed
    }

    cout << result.size() << endl;
    for (int x : result) cout << x << ' ';
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}