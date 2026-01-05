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

const int MAX = 1e6+7;
const int MOD = 1e9+7;
int fac[MAX];

signed main(){
    winton;
    fac[0] = 1;
    for (int i = 1; i < MAX; i++) fac[i] = (i * fac[i-1]) % MOD;
    int n, h;
    cin >> n >> h;
    vector<int> a(h), sum(h), dp(h);
    for (int i = 0; i < h; i++){
        cin >> a[i];
        sum[i] = a[i];
        if(i) sum[i] += sum[i-1];
    }
    if (!h){
        cout << fac[n] << endl;
        return 0;
    }

    dp[0] = fac[sum[0]];
    for (int i = 1; i < h; i++){
        int cur = 0;
        for (int s = 0; s < i; s++){
            cur = (cur + (fac[sum[i] - sum[s]] * dp[s]) % MOD) % MOD;
        }
        dp[i] = (fac[sum[i]] - cur + MOD) % MOD;
    }
    debug(sum, dp);
    int ans = fac[n];
    
    for (int i = 0; i < h; i++){
        ans = ((ans - (dp[i] * fac[n - sum[i]]) % MOD) + MOD) % MOD;
    }
    cout << ans % MOD << endl;
}