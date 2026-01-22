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

const int MAX = 5e4+6;
const int LOG = 25;

int n, m, q, timer = -1, xoxo[MAX], tin[MAX], tout[MAX], depth[MAX], ancestor[MAX];
int xox1[MAX], xox0[MAX];
vector<int> graph [MAX];
pair<int,int> sp[MAX*2][LOG+1];
vector<int> euler;

void dfs(int v, int p){
    tin[v] = euler.size();
    euler.push_back(v);
    if(depth[v]&1) xox1[v] ^= xoxo[v];
    else xox0[v] ^= xoxo[v];
    for (auto u : graph[v]){
        if (u != p){
            ancestor[u] = v;
            depth[u] = depth[v]+1;
            dfs(u,v);
            xox1[v] ^= xox1[u];
            xox0[v] ^= xox0[u];
            euler.push_back(v);
        }
    }
    tout[v] = euler.size()-1;
}

void buildtable(){
    for (int i = 0; i < (int)euler.size(); i++){
        sp[i][0] = {depth[euler[i]], euler[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)euler.size(); i++){
            sp[i][j] = min (sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pair<int,int> query (int a, int b){
    int len =  b - a + 1;
    int lg = 31 - __builtin_clz(len);
    return min(sp[a][lg], sp[b - (1<<lg) + 1][lg]);
}

int lca(int a, int b){
    if (tin[a] > tin[b]) swap(a,b);
    return query(tin[a], tin[b]).second;
}

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> xoxo[i];

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    buildtable();

    int q;
    cin >> q;
    int x0 = xox0[1];
    int x1 = xox1[1];
    debug(x1, x0);
    for (int i = 1; i <= n; i++){
        debug(i, xox1[i], xox0[i]);
    }
    while(q--){
        int u, v;
        cin >> u >> v;

        if (lca(u,v) == u) cout << "INVALID" << endl;
        else {
            int x1o = x1, x0o = x0;
            if (depth[u]%2 == depth[v]%2){
                x1 ^= xox1[u];
                x1 ^= xox0[u];
                x0 ^= xox0[u];
                x0 ^= xox1[u];
                
                debug(u,v,x1,x0);
                cout << ((x1) ? "YES" : "NO") << endl;
            }
            else cout << ((x1) ? "YES" : "NO") << endl;

            x1 = x1o;
            x0 = x0o;
        }
    }
}
