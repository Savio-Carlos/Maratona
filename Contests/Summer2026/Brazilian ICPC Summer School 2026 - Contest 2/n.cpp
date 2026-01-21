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

const int INF = 1e12;
int n;

struct seg_pa {
	struct Data {
		int sum;
		int set_a, set_r, add_a, add_r;
		Data() : sum(0), set_a(INF), set_r(0), add_a(0), add_r(0) {}
	};
	vector<Data> seg;
	int n;

	seg_pa(int n_) {
		n = n_;
		seg = vector<Data>(4*n);
	}

	void prop(int p, int l, int r) {
		int tam = r-l+1;
		int &sum = seg[p].sum, &set_a = seg[p].set_a, &set_r = seg[p].set_r,
			&add_a = seg[p].add_a, &add_r = seg[p].add_r;

		if (set_a != INF) {
			set_a += add_a, set_r += add_r;
			sum = set_a*tam + set_r*tam*(tam+1)/2;
			if (l != r) {
				int m = (l+r)/2;

				seg[2*p].set_a = set_a;
				seg[2*p].set_r = set_r;
				seg[2*p].add_a = seg[2*p].add_r = 0;

				seg[2*p+1].set_a = set_a + set_r * (m-l+1);
				seg[2*p+1].set_r = set_r;
				seg[2*p+1].add_a = seg[2*p+1].add_r = 0;
			}
			set_a = INF, set_r = 0;
			add_a = add_r = 0;
		} else if (add_a or add_r) {
			sum += add_a*tam + add_r*tam*(tam+1)/2;
			if (l != r) {
				int m = (l+r)/2;

				seg[2*p].add_a += add_a;
				seg[2*p].add_r += add_r;

				seg[2*p+1].add_a += add_a + add_r * (m-l+1);
				seg[2*p+1].add_r += add_r;
			}
			add_a = add_r = 0;
		}
	}

	int inter(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first) swap(a, b);
		return max(0LL, min(a.second, b.second) - b.first + 1);
	}
	int set(int a, int b, int aa, int rr, int p, int l, int r) {
		prop(p, l, r);
		if (b < l or r < a) return seg[p].sum;
		if (a <= l and r <= b) {
			seg[p].set_a = aa;
			seg[p].set_r = rr;
			prop(p, l, r);
			return seg[p].sum;
		}
		int m = (l+r)/2;
		int tam_l = inter({l, m}, {a, b});
		return seg[p].sum = set(a, b, aa, rr, 2*p, l, m) + set(a, b, aa + rr * tam_l, rr, 2*p+1, m+1, r);
	}
	void update_set(int l, int r, int aa, int rr) {
		set(l, r, aa, rr, 1, 0, n-1);
	}
	
	int query(int a, int b, int p, int l, int r) {
		prop(p, l, r);
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p].sum;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
    int query(int l, int r) { return query(l, r, 1, 0, n-1); }
};

signed main() {
    winton;
    int m, q;
    cin >> n >> m >> q;
    set<int> harbors;
    vector<int> haha(m);
    vector<int> values (n+1); 
    seg_pa seg(n+1);

    for (int i = 0; i < m; i++){
        cin >> haha[i];
    }
    for (int i = 0; i < m; i++){
        int v;
        cin >> v;
        values[haha[i]] = v;
        harbors.insert(haha[i]);
    }

    auto it = harbors.begin();
    auto prev = it;
    it++;
    for (int i = 1; i < m; i++){
        int l = (*prev);
        int r = (*it);
        int aa = values[*prev] * (r - l);
        int rr = -values[*prev];
        debug(l, r, aa, rr);
        seg.update_set(l+1, r-1, aa, rr);
        prev = it;
        it++;
    }

    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1){
            harbors.insert(a);
            values[a] = b;
            seg.update_set(a, a, 0, 0);

            auto ll = harbors.lower_bound(a);
            auto rr = ll;

            ll--;
            int primeiro = values[*ll] * (a - (*ll));
            int razao = -values[*ll];
            seg.update_set((*ll) + 1, a - 1, primeiro, razao);

            debug(*ll, a, primeiro, razao);
            
            rr++;
            primeiro = values[a] * (*rr - a);
            razao = -values[a];
            seg.update_set(a + 1, (*rr) - 1, primeiro, razao);
            debug(a, *rr, primeiro, razao);
        }  
        else {
            cout << seg.query(a, b) << endl;
        }

    }
}