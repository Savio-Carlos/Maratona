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


const int INF = 1e18;

int cost(int lado){
    if (lado == 0) return 0;
    if (lado <= 4) return 1;
    return 2;
}

signed main(){
    winton;
    vector<string> lines(6);
    for (auto &s : lines) cin >> s;
    debug(lines);
    vector<int> dp(6,0);
    for (int i = 0; i < 6; i++) dp[i] = cost(i);

    for (int i = 1; i < 16; i++){
        vector<int> ndp(6,INF);
        for (int j = 0; j < 6; j++){
            char cur = lines[j][i];
            debug(i,j, cur);
            for (int k = 0; k < 6; k++){
                if (dp[k] >= INF) continue;
                char prev = lines[k][i-1];
                if (prev == 'Q') prev = 'U'; 
                debug(prev);
                if (prev <= cur) ndp[j] = min(ndp[j], dp[k] + cost(j));
            }
        }
        debug(ndp);
        dp = ndp;
    }

    int ans = *min_element(all(dp));
    if (ans >= INF) cout << "impossible" << endl;
    else cout << ans << endl;
}