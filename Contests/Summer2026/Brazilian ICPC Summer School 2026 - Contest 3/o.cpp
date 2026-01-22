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
    stream& operator<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

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

const int MAX = 1e5 + 5;

int edx[MAX];
int n;

namespace SegTree {
    int tree[4*MAX];
    int n, *v;

    int build(int node=1, int l=0, int r=n-1) {
        if (l == r) return tree[node] = v[l];
        int m = (l+r)/2;
        return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
    }

    void build(int n2, int* v2) {
        n = n2, v = v2;
        build();
    }
   
    int query(int a, int b, int node=1, int l=0, int r=n-1) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return tree[node];
        int m = (l+r)/2;
        return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
    }
    
    void update(int i, int x, int node=1, int l=0, int r=n-1) {
        if (l == r) {
            tree[node] = x;
            return;
        }
        int m = (l+r)/2;
        if (i <= m) update(i, x, 2*node, l, m);
        else update(i, x, 2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

namespace HLD {
    vector<pair<int,int>> graph[MAX];
    int timer, pos[MAX], sz[MAX], sobe[MAX], ancestor[MAX], h[MAX], v[MAX]; 

    void build_hld(int node, int p = -1, int f = 1){
        v[pos[node] = timer++] = sobe[node];
        sz[node] = 1;
        for (auto &i : graph[node]){
            auto [u, w] = i;
            if (u == p) continue;
            sobe[u] = w;
            ancestor[u] = node;
            h[u] = (i == graph[node][0] ? h[node] : u); 
            build_hld(u, node, f);
            sz[node] += sz[u];

            if (sz[u] > sz[graph[node][0].first] || graph[node][0].first == p){
                swap(i, graph[node][0]);
            }
        }
        if (p*f == -1)build_hld(h[node] = node, -1, timer = 0);
    }

    void build(int root = 0){
        timer = 0;
        build_hld(root);
        SegTree::build(timer, v);
    }

    int query_path(int a, int b){
        if (a == b) return 0;
        if (pos[a] < pos[b]) swap(a,b);
        if (h[a] == h[b]) return SegTree::query(pos[b] + 1, pos[a]);
        return SegTree::query(pos[h[a]], pos[a]) + query_path(ancestor[h[a]], b);
    }

    void update_path(int a, int b, int x){
        if (a == b) return;
        if (pos[a] < pos[b]) swap(a,b);

        if (h[a] == h[b]) return (void)SegTree::update(pos[b]+1, pos[a], x);
        SegTree::update(pos[h[a]], pos[a], x);
        update_path(ancestor[h[a]], b, x);
    }

    int lca(int a, int b){
        if (pos[a] < pos[b]) swap(a,b);
        return h[a] == h[b] ? b : lca(ancestor[h[a]], b);
    }
    
    int dist(int a, int b) {
        if (a == b) return 0;
        if (pos[a] < pos[b]) swap(a,b);
        if (h[a] == h[b]) return pos[a] - pos[b];
        return pos[a] - pos[h[a]] + 1 + dist(ancestor[h[a]], b);
    }
}

signed main(){
    winton;
    cin >> n;
    vector<pair<int,int>> edges(n); 
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        HLD::graph[u].push_back({v, 0});
        HLD::graph[v].push_back({u, 0});
    }
    
    HLD::build();
    
    for (int i = 1; i <= n - 1; i++) {
        //guarda a posicao de cada edge na seg
        //se v e pai de u entao a aresta u-v vai ser colocada na posicao de u da seg
        auto [u, v] = edges[i];
        if (HLD::ancestor[u] == v) edx[i] = HLD::pos[u];
        else edx[i] = HLD::pos[v];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int id;
            cin >> id;
            SegTree::update(edx[id], 0);
        } 
        else if (op == 2) {
            int id;
            cin >> id;
            SegTree::update(edx[id], 1);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            if (a == b) cout << 0 << endl;
            else {
                int white = HLD::query_path(a, b);
                if (white > 0) cout << -1 << endl;
                else cout << HLD::dist(a, b) << endl;
            }
        }
    }
}