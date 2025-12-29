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

//#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 1e6+7;

int q, k;
int original[MAX], st = 0;

namespace SegTree {
	int tree[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int node=1, int l=0, int r=n-1) {
		lazy[node] = 0;
		if (l == r) return tree[node] = v[l];
		int m = (l+r)/2;
		return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int node, int l, int r) {
		tree[node] += lazy[node]*(r-l+1);
		if (l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
		lazy[node] = 0;
	}
	int query(int a, int b, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) return tree[node];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r);
	}
	int update(int a, int b, int x, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) {
			lazy[node] += x;
			prop(node, l, r);
			return tree[node];
		}
		if (b < l or r < a) return tree[node];
		int m = (l+r)/2;
		return tree[node] = update(a, b, x, 2*node, l, m) + update(a, b, x, 2*node+1, m+1, r);
	}
}

int PA(int a, int b){
    if (b < a) return 0;
    if (!a) return (b*(b+1)/2); 
    return (b*(b+1)/2) - ((a-1)*(a)/2); 
}

int soma(int l, int r){
    if (r < l) return SegTree::query(0, r) + SegTree::query(l, k-1);	            
    else return SegTree::query(l, r);
}

signed main(){
    winton;
    for (int i = 0; i < MAX; i++) original[i] = i;
    cin >> q >> k;

    SegTree::build(MAX,original);

    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            int p;
            cin >> p;
            st = (st + p) % k;

            debug(st);
        }
        else if (t == 2){
            int s, t;
            cin >> s >> t;
            
            int prev_s = original[(s+st)%k];
            int prev_t = original[(t+st)%k];

            original[(s+st)%k] = prev_t;
            original[(t+st)%k] = prev_s;

            SegTree::update((s+st)%k, (s+st)%k, prev_t - prev_s);
            SegTree::update((t+st)%k, (t+st)%k, prev_s - prev_t);
        }
        else{
            int l, r;
            cin >> l >> r;
            int bloco_l = l/k;
            int bloco_r = r/k;
            debug(st);
            l %= k;
            r %= k;
            debug(bloco_l, bloco_r);
            
            int l_na_seg = (l + st) % k;
            int r_na_seg = (r + st) % k;
            int ans = 0;
            
            debug(l_na_seg, r_na_seg);
            
            if (bloco_l == bloco_r){
                
                int sum = soma(l_na_seg, r_na_seg);
                ans = ((r-l+1) * bloco_l * k) + sum;
                debug(ans);
            }
            else {
                int pfx = soma(l_na_seg, ((k-1)+st)%k);
                int sfx = soma(st, r_na_seg);

                int mid = soma(st, ((k-1)+st)%k) * max(0LL, (bloco_r - bloco_l - 1)) + PA(bloco_l+1, bloco_r-1) * k * k;
                pfx += (k - (l%k)) * bloco_l * k;
                sfx += (r+1) * bloco_r * k;
                ans = pfx + sfx;
                if (bloco_r > bloco_l + 1) ans += mid;
                debug(ans);
            }
            
            cout << ans << endl;

        }
    }
}