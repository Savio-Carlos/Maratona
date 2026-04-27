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



const int MAX = 2e3 + 7;
const ld NEG_INF = -1e18;

int n, m;
bool visited[MAX];
vector<int> graph[MAX];

struct Edge {
    int u, v;
    int w;
};

void dfs(int v) {
    visited[v] = 1;
    for (auto u : graph[v]) {
        if (visited[u]) continue;
        dfs(u);
    }
}

signed main() {
    winton;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v, w] = edges[i];
        cin >> u >> v >> w;
        graph[u].push_back(v);
    }

    dfs(1);

    vector<Edge> redges;
    for (auto& e : edges) {
        if (visited[e.u]) {
            redges.push_back(e);
        }
    }
    
    vector<vector<ld>> d(n + 1, vector<ld>(n + 1, NEG_INF));
    d[0][1] = 0;

    for (int k = 1; k <= n; k++) {
        for (auto& e : redges) {
            if (d[k - 1][e.u] > NEG_INF / 2) {
                d[k][e.v] = max(d[k][e.v], d[k - 1][e.u] + (ld)e.w);
            }
        }
    }

    ld ans = 0;

    for (int v = 1; v <= n; v++) {
        if (d[n][v] <= NEG_INF / 2) continue;
        ld best_for_v = 1e18;
        bool has_any = false;
        for (int k = 0; k < n; k++) {
            if (d[k][v] <= NEG_INF / 2) continue;
            ld candidate = (d[n][v] - d[k][v]) / (ld)(n - k);
            best_for_v = min(best_for_v, candidate);
            has_any = true;
        }
        if (has_any) {
            ans = max(ans, best_for_v);
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
}