#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

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

const int MAX = 1e5+7;

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
    winton;
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