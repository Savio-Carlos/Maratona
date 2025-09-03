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

int n, timer = -1, tin[MAX], tout[MAX], tree[4*MAX];
vector<pair<int,int>> topics;
vector<vector<int>> graph;

void dfs(int v, int p){
    tin[v] = ++timer;
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
    }
    tout[v] = timer;
}

int build(int node, int l, int r){
    if (l == r){
        return tree[node] = 0;
    }
    int m = (l + r)/2;
    return tree[node] = build(node*2, l, m) + build(node*2+1, m+1, r);
}

int query(int node, int l, int r, int a, int b){
    if (b < l || r < a) return 0;
    if (l >= a && r <= b) return tree[node];
    int m = (l + r)/2;
    return query(node*2, l, m, a, b) + query(node*2+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if (i < l or i > r) return;
    if (l == r){
        tree [node] = x;
        return;
    }
    int m = (l + r)/2;
    update(node*2, l, m, i, x);
    update(node*2+1, m+1, r, i, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

signed main() {

    winton;
    int q;
    cin >> n >> q;
    map<int,vector<int>> employeetopic;
    topics.resize(n);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        topics[i] = {x, i};
    }
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    } 

    vector<tuple<int,int,int>> queries(q);
    for (int i = 0; i < q; i++){
        int x, k;
        cin >> x >> k;
        queries[i] = {k, x-1, i};
    }

    dfs(0,-1);

    for (int i = 0; i < n; i++){
        auto [x, in] = topics[i];
        employeetopic[x].push_back(tin[in]);
        topics[i] = {x, tin[in]}; //vetor de topics guarda o indice na seg de cada topico
    }

    sort(queries.begin(), queries.end()); //queries ordenadas pelo k
    //pegar todas as queries com o mesmo k, pegar todos os caras com esse mesmo k e colocar na seg
    // depois tirar todos esses caras da seg    
    vector<int> ans(q); 
    int i = 0;
    while (i < q){
        int j = i;
        int curk = get<0>(queries[i]);
        while (j < q && get<0>(queries[j]) == curk) j++;

        auto it = employeetopic.find(curk);
        if (it != employeetopic.end()){
            for (int pos : it->second) update(1, 0, n-1, pos, 1);
            for (int t = i; t < j; ++t){
                int x = get<1>(queries[t]);
                int qi = get<2>(queries[t]);
                ans[qi] = query(1, 0, n-1, tin[x], tout[x]);
            }
            for (int pos : it->second) update(1, 0, n-1, pos, 0);
        } else {
            for (int t = i; t < j; ++t){
                int qi = get<2>(queries[t]);
                ans[qi] = 0;
            }
        }

        i = j;
    }

    for (auto u : ans) cout << u << '\n';
}