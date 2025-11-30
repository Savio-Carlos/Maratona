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

const int MOD = 998244353;

int fastExpo(int base, int exp) {
    base %= MOD;
    if (base < 0) base += MOD;
    int res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res % MOD;
}

int modiv(int a, int b){
    return ((a%MOD) * fastExpo((b%MOD), MOD-2)) % MOD;
}

signed main() {
    winton;
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a[c - 1]++;

    vector<pair<int,int>> r(n);
    for (int i = 0; i < n; i++) r[i] = {a[i], i};
    sort(all(r));
    debug(r);

    vector<int> sortedA(n + 1), pos(n);
    for (int i = 0; i < n; i++) {
        sortedA[i + 1] = r[i].first;
        pos[r[i].second] = i + 1;
    }

    vector<int> pfx(n + 1, 0);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += sortedA[i];
        pfx[i] = pfx[i - 1] + sortedA[i];
    }
    int S = tot - 1;

    vector<int> e_sorted(n + 1, 0);
    int acc = 0;

    for (int i = n; i >= 1; i--) {
        e_sorted[i] = modiv(S % MOD + acc % MOD, (S - pfx[i - 1] % MOD + MOD) % MOD);
        acc = (acc + (sortedA[i] % MOD) * (e_sorted[i] % MOD)) % MOD;
    }

    vector<int> e(n, 0);
    for (int i = 0; i < n; i++) e[i] = e_sorted[pos[i]];

    cout << (e[c - 1] % MOD + MOD) % MOD << endl;
}
