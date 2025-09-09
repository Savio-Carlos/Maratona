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

const int MAX = 2e5+7;

namespace SegTree {
	int tree[4*MAX];
	int n, *v;
    
	int build(int node=1, int l=0, int r=n-1) {
		if (l == r) return tree[node] = v[l];
		int m = (l+r)/2;
		return tree[node] = max(build(2*node, l, m), build(2*node+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	int query(int a, int b, int node=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return tree[node];
		int m = (l+r)/2;
		return max(query(a, b, 2*node, l, m), query(a, b, 2*node+1, m+1, r));
	}
	void update(int i, int x, int node=1, int l=0, int r=n-1) {
		if (l == r) {
            tree[node] = x;
			return;
		}
		if (i < l or r < i) return;
        int m = (l+r)/2;
        if (i <= m) update(i, x, 2*node, l, m);
        else update(i, x, 2*node+1, m+1, r);
	}
}

namespace HLD{
    vector<int> graph[MAX];
    int timer, h[MAX], ancestor[MAX], sz[MAX], pos[MAX], base[MAX], peso[MAX], depth[MAX];
    
    void build_hld(int v, int p = -1, int f = 1) {
		base[pos[v] = timer++] = peso[v]; 
        sz[v] = 1;
		for (auto &i : graph[v]) if (i != p) {
			ancestor[i] = v;
            depth[i] = depth[v]+1;
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
        int res = LLONG_MIN;
        while (h[a] != h[b]) {
            if (depth[h[a]] < depth[h[b]]) swap(a, b); // comparar profundidade da head, NÃO pos
            // head[a] é mais profunda
            res = max(res, SegTree::query(pos[h[a]], pos[a]));
            a = ancestor[h[a]]; // sobe para o pai da head
        }
        // agora mesma head
        if (depth[a] < depth[b]) swap(a, b);
        res = max(res, SegTree::query(pos[b], pos[a]));
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
    for (int i = 0; i < n; i++){
        debug(i, HLD::pos[i]);
    }
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