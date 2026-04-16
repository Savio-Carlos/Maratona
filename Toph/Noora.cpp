#include <bits/stdc++.h>
#include <bit>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


int dp[20][(1<<10)][2];
int n, k;
string s;

int pd(int index, int tight, int mask, int ldz){
    if (index == -1) return ((__bit_width(mask) - 1) == __popcount(mask));
    
    if (!tight && dp[index][mask][ldz] != -1) return dp[index][mask][ldz];

    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;
    int sum = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_tight = tight && (digit == ub);

        int new_ldz = ldz && (digit == 0);
        
        int new_mask = mask;
        if (!new_ldz) new_mask |= (1 << digit);

        ans += pd(index - 1, new_tight, new_mask, new_ldz);
    }

    if (!tight) dp[index][mask][ldz] = ans; 
    return ans;
}

int count(ll x){
    s.clear();
    while(x) {
        s += (to_string(x % 10));
        x /= 10;
    }
    n = s.size();
    // debug(s);
    return pd(n-1,1,0,1);
}

void solve(){
    ll r;
    cin >> r;
    cout << count(r) << endl;
}

signed main(){
    winton;
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while(t--) solve();
}
