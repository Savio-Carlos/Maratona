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

struct DSU {
	vector<int> comp, sz;
	DSU(int n) : comp(n + 1), sz(n + 1, 1) {
		iota(all(comp), 0);
	}
	int find(int u) {
		if (u == comp[u]) return u;
		return comp[u] = find(comp[u]);
	}
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		sz[a] += sz[b];
		comp[b] = a;
		return true;
	}
};

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    map<int, int> pos;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    DSU dsu(n);
    vector<bool> active(n + 1, false);
    int ans = 1;
    
    for (int k = 1; k <= n; k++){
        if (!pos.count(k)) break; 
        
        int u = pos[k];
        active[u] = true;
        
        for (int v : graph[u]){
            if (active[v]){
                dsu.merge(u, v);
            }
        }
        
        int root1 = dsu.find(pos[1]);
        if (dsu.sz[root1] == k){
            ans = k;
        }
    }
    
    cout << ans << endl;
}

signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}

