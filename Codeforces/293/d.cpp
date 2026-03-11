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
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

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
    int n, t;
    ld p;
    cin >> n >> p >> t;

    vector<vector<ld>> dp(n+1, vector<ld>(t+1));
    dp[0][0] = 1.0;
    debug(dp);
    for (int j = 0; j < t; j++){
        for (int i = 0; i <= n; i++){
            //se a quantidade de pessoas ja for o maximo, entao a chance de ter n pessoas no proximo segundo se mantem
            if (i == n) dp[i][j+1] += dp[i][j];
            else {
                //nao entrar ninguem, no proximo segundo a quantidade de pessoas se mantem, com probabilidade 1-p    
                dp[i][j+1] += dp[i][j] * (1.0-p);
                //entrar alguem, no proximo seguinte a quantidade de pessoas cresce em 1, com probabilidade p
                dp[i+1][j+1] += dp[i][j] * p; 
            }
        }
    
    }
    debug(dp);
    ld ans = 0;
    for (int i = 1; i <= n; i++){
        ans = ans + dp[i][t] * i; 
    }
    debug(ans);
    cout << fixed << setprecision(10) << ans << endl;
}

signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}