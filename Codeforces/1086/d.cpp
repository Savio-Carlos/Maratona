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


void solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    bool self = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][i] != '1') self = false;
    }

    if (!self) {
        cout << "No" << endl;
        return;
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || s[i][j] != '1') continue;
            bool direto = true;
            for (int k = 0; k < n && direto; k++) { 
                if (k == i || k == j) continue;;
                if (s[i][k] == '1' && s[k][j] == '1') direto = false;
            }
            debug(i,j,direto);
            if (direto) edges.push_back({i, j});
        }
    }
    debug(edges);

    if (edges.size() != n - 1) {
        cout << "No" << endl;
        return;
    }

    vector<vector<int>> und(n), dir(n);
    for (auto &[u, v] : edges) {
        und[u].push_back(v);
        und[v].push_back(u);
        dir[u].push_back(v);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : und[v]) {
            if (vis[u]) continue;
            vis[u] = 1;
            cnt++;
            q.push(u);
        }
    }

    if (cnt != n) {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        vector<int> alcanca(n, 0);
        queue<int> q2;
        q2.push(i);
        alcanca[i] = 1;
        while (!q2.empty()) {
            int v = q2.front();
            q2.pop();
            for (auto u : dir[v]) {
                if (alcanca[u]) continue;
                alcanca[u] = 1;
                q2.push(u);
            }
        }

        for (int j = 0; j < n; j++) {
            if (alcanca[j] != (s[i][j] == '1')) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << endl;
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}