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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 998244353;

pair<int,int> dp[22][(1<<10)][2];
int pot10[22];
int n, k;
string s;

pair<int,int> pd(int index, int tight, int mask, int ldz){
    if (index == n) return {0LL, (__popcount(mask) <= k)};
    
    
    if (!tight && dp[index][mask][ldz] != make_pair(-1LL, -1LL)) return dp[index][mask][ldz];

    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;
    int sum = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_tight = tight && (digit == ub);

        int new_ldz = ldz && (digit == 0);
        
        int new_mask = mask;
        if (!new_ldz) new_mask |= (1 << digit);

        // debug(digit, mask, new_mask);
        auto [sm, cnt] = pd(index + 1, new_tight, new_mask, new_ldz);

        sum = ((sum + (sm % MOD)) % MOD + (((digit * pot10[n-index-1]) % MOD) * cnt % MOD)) % MOD;
        ans = ans + cnt;    
    }
    ans = (ans + MOD) % MOD;
    sum = (sum + MOD) % MOD;
    
    if (!tight) dp[index][mask][ldz] = {sum, ans}; 
    return {sum, ans};
}

int count(int x){
    for (auto& a : dp)
        for (auto& b : a)
            for (auto& c : b)
                c = {-1LL, -1LL};

    s = to_string(x);
    n = s.size();
    auto [sum,ans] = pd(0,1,0,1);
    return (sum + MOD % MOD);
}

signed main(){
    winton;
    
    pot10[0] = 1;
    for (int i = 1; i < 22; i++) pot10[i] = (pot10[i-1] * 10LL) % MOD;

    int l, r;
    cin >> l >> r >> k;

    debug(count(r));
    debug(count(l-1));
    cout << (count(r) - count(l-1) + MOD) % MOD << endl;
}
