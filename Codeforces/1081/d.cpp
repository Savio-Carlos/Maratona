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

const int MAX = 2e5+7;
vector<int> graph[MAX];
int a[MAX], subsum[MAX], cost[MAX], mxdp[MAX], ans[MAX], bg[MAX], maxcs[MAX];

void dfs(int v, int p) {
    subsum[v] = a[v];
    cost[v] = 0;
    mxdp[v] = 0;
    bg[v] = 0;
    maxcs[v] = 0;

    vector<pair<int,int>> ch;
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u, v);
        subsum[v] += subsum[u];
        cost[v] += cost[u] + subsum[u];
        mxdp[v] = max(mxdp[v], mxdp[u] + 1);
        maxcs[v] = max(maxcs[v], subsum[u]);
        ch.push_back({mxdp[u]+1, subsum[u]});
    }
    int d1 = 0, d2 = 0;
    for (auto& [d, s] : ch) {
        if (d >= d1) { d2 = d1; d1 = d; }
        else if (d > d2) { d2 = d; }
    }
    for (auto u : graph[v]){
        if (u == p) continue;
        int dc = mxdp[u] + 1;
        int ec = (dc == d1) ? d2 : d1;
        bg[v] = max(bg[v], subsum[u] * ec);
        bg[v] = max(bg[v], max(0LL, ec - 1) * maxcs[u]);
        bg[v] = max(bg[v], bg[u]);
    }

    ans[v] = cost[v] + bg[v];
}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        graph[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}