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

const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
const int P1   = 91138233LL;
const int P2   = 97266353LL;

struct hashing {
    string s;
    int n;
    vector<int> h1, h2;
    vector<int> p1, p2;

    hashing(const string &_s) : s(_s) {
        n = (int)s.size();
        h1.assign(n+1, 0);
        h2.assign(n+1, 0);
        p1.assign(n+1, 0);
        p2.assign(n+1, 0);
    }

    void build() {
        p1[0] = 1;
        p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1[i] = (p1[i-1] * P1) % MOD1;
            p2[i] = (p2[i-1] * P2) % MOD2;
        }
        for (int i = 0; i < n; i++) {
            int val = (s[i] - 'a' + 1);
            h1[i+1] = (h1[i] + val * p1[i]) % MOD1;
            h2[i+1] = (h2[i] + val * p2[i]) % MOD2;
        }
    }

    pair<int,int> get_hash(int l, int len) {
        int r = l + len;
        int x1 = ((h1[r] - h1[l]) + MOD1) % MOD1;
        int x2 = ((h2[r] - h2[l]) + MOD2) % MOD2;
        return {x1, x2};
    }
};


int solve(string &s, string &t, hashing &hs) {
    int n = s.size();
    int m = t.size();
    hashing ht(t);
    ht.build();
    auto hash_t = ht.get_hash(0, m);

    int cnt = 0;
    for (int i = 0; i + m <= n; ) {
        auto cur = hs.get_hash(i, m);
        int need1 = (hash_t.first * hs.p1[i]) % MOD1;
        int need2 = (hash_t.second * hs.p2[i]) % MOD2;
        if (cur.first == need1 && cur.second == need2) {
            cnt++;
            i += m;
        } else i++;
    }
    return cnt;
}

signed main() {
    winton;
    string s;
    cin >> s;
    int n = s.size();

    set<string> st;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j + i <= n; j++){
            st.insert(s.substr(j, i));
        }
    }
    debug(st.size);
    hashing hs(s);
    hs.build();

    int ans = 1e12;
    
    for (string t : st) {
        int m = t.size();
        int k = solve(s, t, hs);
        int total = n + m - 1LL * k * (m - 1);
        debug(k, total);
        ans = min(ans,total);
    }
    cout << ans << endl;
}
