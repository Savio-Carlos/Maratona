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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 1e6+7;
const int INF = 1e18;

vector<int> graph[MAX];
int n, cost[MAX];
map<string, int> cnt;
map<int, string> pref;

void dfs(int v){
    for (auto &u : graph[v]){
        cost[u] = cost[v] + n-2*cnt[pref[u]];
        dfs(u);
    }
}

signed main(){
    winton;
    cin >> n;
    map<string, int> mp;
    int node = 0, tot = 0;
    mp["/"] = 0;
    for (int i = 0; i < n; i++){
        int prev = 0;
        string s;
        cin >> s;
        s += '/';
        string cur = "", pfx = "";
        int depth = 1;
        for (int c = 1; c < sz(s); c++){
            if (s[c] != '/'){
                cur += s[c];
                continue;
            }
            tot++;
            cur += pfx;
            pfx += cur;
            cnt[pfx]++;
            
            if (mp.find(cur) != mp.end()){//ja tenho esse caminho no map
                prev = mp[cur];
                cur = "";
                continue;
            } 
            else {
                graph[prev].push_back(++node);
                pref[node] = pfx;
            }
            // debug(cur);
            // debug(mp);
            mp[cur] = node;
            prev = mp[cur];
            cur = "";
        }
    }
    debug(mp);
    debug(cnt);
    for (int i = 0; i <= node; i++){debug(i, graph[i]);}
    cost[0] = tot; 
    dfs(0);
    int ans = INF;
    for (int i = 0; i <= node; i++){
        if (sz(graph[i]) > 0){
            ans = min(cost[i], ans);
            debug(cost[i]);
        }
    }
    cout << ans << endl;
}