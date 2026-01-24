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

signed main(){
    winton;
    int n, m;
    while (cin >> n >> m){
        if (n == 0 && m == 0) break;
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int mask = (1 << n) - 1;
        bool pos = false;
        vector<int> ans;

        queue<pair<int, vector<int>>> q;
        q.push({mask, {}});
        
        vector<bool> visited(1 << n, false);
        visited[mask] = true;

        while(!q.empty()){ 
            auto [cur_mask, seq] = q.front();
            q.pop();

            if (cur_mask == 0){
                pos = true;
                ans = seq;
                break;
            }

            for (int i = 0; i < n; i++){
                int next_mask = 0;
                int temp_state = cur_mask & ~(1 << i);

                for (int u = 0; u < n; u++) {
                    bool alive_neighbor = false;
                    for (int v : graph[u]) {
                        if ((temp_state >> v) & 1) {
                            alive_neighbor = true;
                            break;
                        }
                    }
                    if (alive_neighbor) {
                        next_mask |= (1 << u);
                    }
                }

                if (!visited[next_mask]) {
                    visited[next_mask] = true;
                    vector<int> next_seq = seq;
                    next_seq.push_back(i);
                    q.push({next_mask, next_seq});
                }
            }
        }
        
        if (pos) {
            cout << ans.size() << ":";
            for(int x : ans) cout << " " << x;
            cout << endl;
        } 
        else cout << "Impossible" << endl;
    }
}