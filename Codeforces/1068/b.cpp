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

void solve(){
    int n;
    cin >> n;
    vector<int> r(n), b(n);
    for (auto &u : r) cin >> u;
    for (auto &u : b) cin >> u;
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = min(-r[0], b[0]);
    dp[0][1] = max(-r[0], b[0]);

    for (int i = 1; i < n; i++){
        dp[i][0] = min({b[i] - dp[i-1][0], b[i] - dp[i-1][1], dp[i-1][0] - r[i], dp[i-1][1] - r[i]});
        dp[i][1] = max({b[i] - dp[i-1][0], b[i] - dp[i-1][1], dp[i-1][0] - r[i], dp[i-1][1] - r[i]});
    }
    debug(dp);
    cout << dp[n-1][1] << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}