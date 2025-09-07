#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define endl "\n"
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
    #define minecraft (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define minecraft ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
    #define debug(...) (void)0
#endif

const int MAX = 2e5+7;
const int LOG = 20;
const int MOD = 1e9+7;

/*
euler tour com segtree e lca
guardar na seg a soma do caminho da raiz ate o no i
update em range da subarvore inteira 
update da soma no lca dos dois nos e update de menos em cada um das subarvores dos nos
mas isso da errado no caso em que o lca e a raiz
 
*/

int n, timer = 0, tin[MAX], tout[MAX], depth[MAX], dist[MAX], tree[4*MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<vector<pair<int,int>>> graph; //0 indexado

void dfs(int v, int p){
    tin[v] = et.size();
    et.push_back(v);
    for (auto [u, c] : graph[v]){
        if (u!=p){
            depth[u] = depth[v]+1;
            dist[u] = (dist[v] + c) % MOD;
            dfs(u,v);
            et.push_back(v);
        }
    }
}

void buildtable(){
    for (int i = 0; i < (int)et.size(); i++){
        sp[i][0] = {depth[et[i]], et[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)et.size(); i++){
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


void build(int node, int l, int r){
    if (l == r){
        tree[node] = 0;//alguma coisa
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
}

int get(int node, int l, int r, int i){
    if (l == r) return tree[node];
    int m = (l+r)/2;
    int res;
    if (i > m) res = get(node*2+1, m+1, r, i);
    else res = get(node*2, l, m, i); 
    return res + tree[node];
}

void add(int node, int l, int r, int a, int b, int x){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        tree[node] += x;
        return;
    }
    int m = (l+r)/2;
    add(2*node, l, m, a, b, x);
    add(2*node+1, m+1, r, a, b, x);
}

signed main() {
    minecraft;
    int q;
    cin >> n >> q;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[--a].push_back({--b, c});
        graph[b].push_back({a, c});
    }
    dfs(0,0);
    buildtable();
    while(q--){
        int a, b, x;
        cin >> a >> b >> x;
        a--;b--;
        int mac = lca(a,b);
        debug(dist[a], dist[b], a, b, dist[mac]);
        cout << (((((dist[a] + dist[b]) % MOD) - ((2*dist[mac]) % MOD)) % MOD ) * x) % MOD << endl;
    }
}