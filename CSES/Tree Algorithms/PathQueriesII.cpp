#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
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

const int MAX = 2e5+7;

namespace SegTree {
    int n;
    int pot2;
    vector<int> tree;

    void build(int n2, int* v2) {
        n = n2;
        pot2 = 1;
        while (pot2 < n) pot2 <<= 1;
        tree.assign(2 * pot2, 0);
        for (int i = 0; i < n; ++i) tree[pot2 + i] = v2[i];
        for (int i = pot2 - 1; i >= 1; --i) tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    int query(int a, int b) {
        if (a > b) return 0;
        a += pot2; b += pot2;
        int res = 0;
        while (a <= b) {
            if (a & 1) res = max(res, tree[a++]);
            if (!(b & 1)) res = max(res, tree[b--]);
            a >>= 1; b >>= 1;
        }
        return res;
    }

    void update(int i, int x) {
        int p = i + pot2;
        tree[p] = x;
        p >>= 1;
        while (p >= 1) {
            tree[p] = max(tree[2*p], tree[2*p+1]);
            p >>= 1;
        }
    }
}

namespace HLD{
    vector<int> graph[MAX];
    int timer, h[MAX], ancestor[MAX], sz[MAX], pos[MAX], base[MAX], peso[MAX];
    
    void build_hld(int v, int p = -1, int f = 1) {
        base[pos[v] = timer++] = peso[v]; 
        sz[v] = 1;
        for (auto &i : graph[v]) if (i != p) {
            ancestor[i] = v;
            h[i] = (i == graph[v][0] ? h[v] : i);
            build_hld(i, v, f); sz[v] += sz[i];

            if (sz[i] > sz[graph[v][0]] or graph[v][0] == p) swap(i, graph[v][0]);
        }
        if (p*f == -1) build_hld(h[v] = v, -1, timer = 0);
    }

    void build(int root = 0) {
        timer = 0;
        build_hld(root);
        SegTree::build(timer, base);
    }

    int query_path(int a, int b) {
        int res = 0;
        while (h[a] != h[b]) {
            if (pos[a] < pos[b]) swap(a, b);
            res = max(res, SegTree::query(pos[h[a]], pos[a]));
            a = ancestor[h[a]];
        }
        if (pos[a] > pos[b]) swap(a, b);
        res = max(res, SegTree::query(pos[a], pos[b]));
        return res;
    }
    
    void update_node(int i, int x) {
        peso[i] = x;
        SegTree::update(pos[i], x);
    }
}


signed main(){
    winton;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> HLD::peso[i];
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        HLD::graph[a].push_back(b);
        HLD::graph[b].push_back(a);
    }
    HLD::build();
    while(q--){
        int type;
        cin >> type;
        if (type == 1){
            int s, x;
            cin >> s >> x;
            s--;
            HLD::update_node(s,x);
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << HLD::query_path(a,b) << endl;
        }
    }
}
