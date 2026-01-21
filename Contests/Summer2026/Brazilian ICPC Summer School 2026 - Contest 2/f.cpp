#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
// #define int long long
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

const int MAX = 2e3+7;

vector<int> graph[MAX];
int n, dist[3][MAX];

void dfs(int v, int p, int id){
    for (auto u : graph[v]){
        if (u == p || dist[id][u] > 0) continue;
        dist[id][u] = dist[id][v] + 1;
        dfs(u,v,id);
    }
}
int distance(int id){
    int u = -1, mx = 0;
    for (int i = 1; i <= n; i++){
        if (dist[id][i] > mx){
            u = i;
            mx = dist[id][i];
        }
    }
    return u;
}
int cont(int v, int p, int d){
    if (d == 0) return 1;
    int cur = 0;
    for (auto u : graph[v]){
        if (u == p) continue;
        cur += cont(u,v,d-1);
    }
    return cur;
}

void solve(){
    cin >> n;
    if (n == 1){
        cout << 1 << endl << "1 0" << endl;
        return;
    }
    for (int i = 0; i <= n; i++){
        graph[i].clear();
        dist[0][i] = dist[1][i] = dist[2][i] = 0;
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0,0);
    int a = distance(0);
    dfs(a,0,1);
    int b = distance(1);
    dfs(b,0,2);
    
    vector<int> center;
    for (int i = 1; i <= n; i++){
        if (dist[1][i] + dist[2][i] == dist[1][b] && abs(dist[1][i] - dist[2][i]) <= 1){
            center.push_back(i);
        }
    }
    if (center.size() == 1){
        int c = center[0];
        set<int> s;

        function<void(int,int,int)> get_dist = [&]( int u, int p, int d) -> void {
            s.insert(d);
            for(auto v : graph[u]){
                if(v != p) get_dist(v, u, d+1);
            }
        };
        get_dist(c, -1, 0);

        cout << s.size() << endl;
        for(auto x : s) cout << c << " " << x << endl;
    } 
    else {
        vector<pair<int,int>> ans;
        int diam = dist[1][b];
        int range = (diam + 1) / 2;
        
        for (int i = 1; i <= range; i+=2){
            ans.push_back({center[0], i});
            ans.push_back({center[1], i});
        }
        cout << ans.size() << endl;
        for(auto p : ans) cout << p.first << " " << p.second << endl;
    }
}

signed main () {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}