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

const int LOG = 22;
const int MAX = 2e5+7;
const int INF = 1e18;

namespace sparse {
	int m[LOG+1][MAX], n;
	void build(int n2, vector<int> v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(m[j][a], m[j][b-(1<<j)+1]);
	}
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &u : a) cin >> u;
    for (auto &u : b) cin >> u;

    int ans = -INF;

    vector<int> pfx(n), sfx(n);

    int sum = a[0];
	int mx = a[0];
    pfx[0] = a[0];
	for (int i = 1; i < n; i++) {
		sum = max(sum + a[i], a[i]);
		mx = max(mx, sum);
        pfx[i] = sum;
	}
    int bob = mx;
    if (!(k&1)){
        cout << bob << endl;
        return;
    }
    sum = a[n-1];
	mx = a[n-1];
    sfx[n-1] = a[n-1];
	for (int i = n-2; i >= 0; i--) {
		sum = max(sum + a[i], a[i]);
		mx = max(mx, sum);
        sfx[i] = sum;
	}

    debug(pfx, sfx);
    for (int i = 0; i < n; i++){
        ans = max(ans, pfx[i] + sfx[i] + b[i] - a[i]);
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}