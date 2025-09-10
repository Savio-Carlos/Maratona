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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif
/*Segtree que guarda o maior intervalo de 0 consecutivos presente
como dar merge?
*/
const int MAX = 2e5+7;

struct gap{
    int l, r, mx, len;
};//armazenar a quantidade de 0's a esquerda, meio e direita em cada intervalo

int base[MAX];

namespace SegTree {
    int n, *v;
    int lazy[4*MAX];
    gap tree[4*MAX];

    gap merge(gap left, gap right){
        gap cur;
        cur.l = left.l + (left.len == left.l ? right.l : 0);
        cur.r = right.r + (right.len == right.r ? left.r : 0);
        cur.mx = max({right.l + left.r, right.mx, left.mx});
        cur.len = left.len + right.len;
        return cur;
    }

    void build(int node = 1, int l = 0, int r = n-1){
        lazy[node] = -1;
        if (l == r){
            if (!v[l]) tree[node] = {1,1,1,1};
            else tree[node] = {0,0,0,1};
            return;
        }
        int m = (l+r)/2;
        build(node*2, l, m);
        build(node*2+1, m+1, r);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

    void change(int node){
        if (lazy[node] == 1){
            tree[node].l = tree[node].r = tree[node].mx = 0; 
        }
        else if (lazy[node] == 0){
            tree[node].l = tree[node].r = tree[node].mx = tree[node].len; 
        }
    }
    
    void prop(int node){
        if (lazy[node] != -1){
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
            change(node*2);
            change(node*2+1);
            lazy[node] = -1;
        }
    }
    
    void update(int a, int b, int x, int node = 1, int l = 0, int r = n-1){
        if(b < l or r < a) return;
        if(a <= l && r <= b){
            lazy[node] = x;
            change(node);
            return;
        }
        prop(node);
        int m = (l+r)/2;
        update(a, b, x, 2*node, l, m);
        update(a, b, x, 2*node+1, m+1, r);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }
}
    
signed main(){
    winton;
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 0; i < n; i++) cin >> base[i];
    
    SegTree::build(n,base);
    
    if (SegTree::tree[1].mx <= k) cout << "SIM\n";
    else cout << "NAO\n";

    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) SegTree::update(a, b, t);
        else {
            t = 0;
            SegTree::update(a, b, t);
        }
        debug(SegTree::tree[1].mx);
        if (SegTree::tree[1].mx <= k) cout << "SIM\n";
        else cout << "NAO\n";
    }

}